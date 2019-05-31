#include "persontablemodel.h"
#include "database/database_api.h"
#include <QSqlRecord>
#include <QSqlField>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
PersonTableModel::PersonTableModel(QObject *parent) : QSqlTableModel(parent)
{
    tableName = TABLE_NAME_PERSON;
    header<<QObject::trUtf8("编号")<<
            QObject::trUtf8("卡号")<<
            QObject::trUtf8("姓名")<<
            QObject::trUtf8("学号")<<
            QObject::trUtf8("身份类型")<<
            QObject::trUtf8("电话号码")<<
            QObject::trUtf8("是否激活")<<
            QObject::trUtf8("备注");
}


/**
 * @brief PersonTableModel::createTable
 * @param tableName 数据块表名称
 * 用于创建Person表
 */
void PersonTableModel::createTable()
{
    QSqlQuery query;
    QString str;
    str  = tr("create table ") + tableName + tr(" ( ");
    str += header.at(0) + tr(" varchar PRIMARY KEY not null, ");
    str += header.at(1) + tr(" varchar, ");
    str += header.at(2) + tr(" varchar, ");
    str += header.at(3) + tr(" varchar, ");
    str += header.at(4) + tr(" varchar, ");
    str += header.at(5) + tr(" varchar, ");
    str += header.at(6) + tr(" varchar, ");
    str += header.at(7) + tr(" varchar) ");
    qDebug()<<"Sql: " << str.toUtf8().data();
    bool ret = query.exec(str);
    if(ret == true){
        qDebug()<<tableName<<QObject::tr(" table create success");
    }
    else{
        qDebug()<<tableName<<QObject::tr(" table create failed");
    }
}


/**
 * @brief PersonTableModel::restore
 * 绑定表名
 */
void PersonTableModel::bindTable(void)
{
    setTable(tableName);
    select();
}

//返回尾号的奇偶
int PersonTableModel::findstunum(QString tagId){
    int row;
    int stunum;
    QString SID;
    QString SID2;
    for(row=0; row<rowCount(); row++){
        if(data(index(row, 1)) == tagId){
           qDebug()<<data(index(row,3));
           SID = data(index(row,3)).toString();
           SID2 = SID[9];
           stunum = SID2.toInt();
           return stunum % 2;
        }
    }
    return -1;
}


/**
 * @brief PersonTableModel::findRecord
 * @param personId 人员编号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
int PersonTableModel::findRecordById(const QString personId)
{
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 0)).toString() == personId)
            return row;
    }
    return -1;
}

/**
 * @brief PersonTableModel::findPhoneBycardId
 * @param cardId 卡号
 * @return QString
 * 根据卡号查找手机号
 */
QString PersonTableModel::findPhoneBycardId(const QString cardId){
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 1)).toString() == cardId)
            return data(index(row, 5)).toString();
    }
    return "N";
}

/**
 * @brief PersonTableModel::findRecordBycardId
 * @param cardId 卡号
 * @return QString
 * 根据卡号查找记录
 */
QString PersonTableModel::findRecordBycardId(const QString cardId){
    int count = rowCount();
    for(int row=0; row < count; row++){
        if(data(index(row, 1)).toString() == cardId && data(index(row, 6)).toString() == "Y")
            return "Y";
    }
    return "N";
}


/**
 * @brief PersonTableModel::findRecordByStudentId
 * @param StudentId 学生学号
 * @return 成功返回行号，失败返回-1
 * 根据学号查找是否有此学号
 */
int PersonTableModel::findRecordByStudentId(const QString StudentId){
    int count = rowCount();
    for(int row = 0; row < count; row++){
        if(data(index(row,3)).toString() == StudentId)
            return row;
    }
    return -1;
}

/**
 * @brief PersonTableModel::findPhoneByStudentId
 * @param Phone 手机号 row 行号
 * @return 如果当前卡号已挂失，则返回2，如果挂失成功，返回1，不是这个手机号则返回0
 * 根据学号查找手机号顺便挂失
 */
int PersonTableModel::findPhoneByStudentId_tolost(const QString Phone,const int row){
    QSqlQuery query;
    QString str;

    if(data(index(row,5)).toString() == Phone){
        if(data(index(row,6)).toString() == "N"){
            return 2;
        }
        setData(index(row, 6), QVariant("N"));
        qDebug()<<row;
        submitAll();
        return 1;
    }
    //不是这个手机号
    else return 0;
}

/**
 * @brief PersonTableModel::findPhoneByStudentId
 * @param Phone 手机号 row 行号
 * @return 如果当前卡号已挂失，则返回2，如果挂失成功，返回1，不是这个手机号则返回0
 * 根据学号查找手机号顺便解挂
 */
int PersonTableModel::findPhoneByStudentId_tofound(const QString Phone,const int row){
    if(data(index(row,5)).toString() == Phone){
        if(data(index(row,6)).toString() == "Y"){
            return 2;
        }
        setData(index(row, 6), QVariant("Y"));
        qDebug()<<row;
        submitAll();
        return 1;
    }
    //不是这个手机号
    else return 0;
}


/**
 * @brief PersonTableModel::findRecord
 * @param personId 人员编号
 * @return QSqlRecord型记录集
 * 根据人员编号查找记录
 */
QSqlRecord PersonTableModel::findRecordByName(const QString userName)
{
    setFilter(QObject::tr("姓名= '%1'").arg(userName)); //根据姓名进行筛选
    select();
    return record();
}


/**
 * @brief PersonTableModel::insertRecords
 * @param personId   人员编号
 * @param personName 人员名称
 * @param personType 身份类别
 * @param remark 备注信息
 * @return 成功返回true，失败返回false
 * 向表格中插入记录
 */
bool PersonTableModel::insertRecords(QString personId,QString cardId,QString personName,
                                     QString userID, QString personType, QString userPhone, QString personRemark)
{
    QSqlQuery query;
    QString str;
    str  = tr("insert into ") + tableName + tr(" values( \"%1\" , \"%2\" , \"%3\" , \"%4\" , \"%5\" , \"%6\",  \"Y\", \"%7\" ) ")
           .arg(personId).arg(cardId).arg(personName).arg(userID).arg(personType).arg(userPhone).arg(personRemark);
    qDebug()<<"Sql: " << str.toUtf8().data();
    return query.exec(str);
}


/**
 * @brief PersonTableModel::deleteRecords
 * @param row 待删除的行
 * @return  如果删除成功返回true，否则false
 * 删除一行记录
 */
bool PersonTableModel::deleteRecords(int row)
{
    return removeRow(row);
}
