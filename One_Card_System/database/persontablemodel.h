#ifndef PERSONTABLEMODEL_H
#define PERSONTABLEMODEL_H

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
/**************************************
 *作者: jianghj@up-tech.com
 *日期: 2016-09-20
 *描述: 人员信息表的model
***************************************/
class PersonTableModel : public QSqlTableModel
{
    Q_OBJECT
private:
    QString tableName;//表名

    QStringList header;//表头
public:
    explicit PersonTableModel(QObject *parent = 0);
    //创建表
    void createTable();
    //绑定表
    void bindTable(void);
    //根据用户Id查询记录
    int findRecordById(const QString personId);
    //根据用户名查询记录
    QSqlRecord findRecordByName(const QString userName);
    //根据学号查询记录
    int findRecordByStudentId(const QString StudentId);
    //根据学号查询记录
    QString findRecordBycardId(const QString cardId);
    //根据行号查找手机号_挂失
    int findPhoneByStudentId_tolost(const QString Phone,const int row);
    //根据行号查找手机号_解挂
    int findPhoneByStudentId_tofound(const QString Phone,const int row);
    //插入记录
    bool insertRecords(QString personId,QString cardId,QString personName,QString userID, QString personType,QString userPhone,QString personRemark);
    //删除记录
    bool deleteRecords(int row);
    //查找学号是否尾号为奇数还是偶数
    int findstunum(QString tagId);
    //根据卡号查找手机号
    QString findPhoneBycardId(const QString cardId);

signals:

public slots:
};

#endif // PERSONTABLEMODEL_H
