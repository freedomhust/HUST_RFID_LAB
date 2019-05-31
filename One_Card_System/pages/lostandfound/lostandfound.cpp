#include "lostandfound.h"
#include "ui_lostandfound.h"
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>

lostandfound::lostandfound(QWidget *parent,SerialPortThread *serialPortThread) :
    QDialog(parent), ui(new Ui::lostandfound)
{
    ui->setupUi(this);
    this->serialPortThread = serialPortThread;
    ui->lineEdit_cardId->setReadOnly(true);
}


lostandfound::~lostandfound()
{
    delete ui;
}

/**
 * @brief WriteOffPerson::on_btn_Lost_clicked
 * 挂失按钮点击事件
 */
void lostandfound::on_btn_Lost_clicked(){
    QString StudentId = ui->textEdit_Student->toPlainText();
    QString Phone = ui->textEdit_phone->toPlainText();

    //用户信息表的信息
    PersonTableModel *persontablemodel = new PersonTableModel;
    persontablemodel->bindTable();


    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);



    int row = persontablemodel->findRecordByStudentId(StudentId);
    //有该学号则继续查找
    if(row >= 0){
        int res = persontablemodel->findPhoneByStudentId_tolost(Phone,row);
        //不是该手机号
        if(res == 0){
            message.setText(tr("学号对应手机号错误，请重新输入"));
            message.exec();
            return ;
        }
        else if(res == 1){
            message.setText(tr("挂失成功！"));
            message.exec();
            return ;
        }
        else {
            message.setText(tr("此卡已被挂失，请勿重复挂失操作"));
            message.exec();
            return ;
        }
    }
    //如果没有该学号则返回错误信息
    else{
        message.setText(tr("学号尚未注册"));
        message.exec();
        return ;
    }
}

/**
 * @brief lostandfound::on_btn_Inventory_clicked
 * 识别按钮点击事件
 */
void lostandfound::on_btn_Inventory_clicked()
{
    if(!serialPortThread->serialPortIsOpen())
    {
        QMessageBox::warning(this,tr("温馨提示"),tr("请先连接读卡器后再试！"),QMessageBox::Yes);
        return;
    }
    m1356dll = new M1356Dll();
    uint16 frameLen;
    quint8 buffer[1];
    uint8 *p;
    memset(buffer, 0, 1);
    buffer[0] = RC632_14443_ALL;
    p = m1356dll->RC632_SendCmdReq(RC632_CMD_REQUEST_A,buffer,1);
    frameLen = BUILD_UINT16(p[0], p[1]);
    serialPortThread->writeData((char *)(p + 2 ),frameLen);
    delete m1356dll;
}

/**
 * @brief RegistorWidget::on_tagIdReceived
 * @param tagId 标签ID
 * 接收到卡号时调用
 */
void lostandfound::on_tagIdReceived(QString tagId){
      ui->lineEdit_cardId->setText(tagId);
 }

/**
 * @brief WriteOffPerson::on_btn_Found_clicked
 * 解挂按钮点击事件
 */
void lostandfound::on_btn_Found_clicked(){
    QString StudentId = ui->textEdit_Student->toPlainText();
    QString Phone = ui->textEdit_phone->toPlainText();
    QString CardId = ui->lineEdit_cardId->text();

    //用户信息表的信息
    PersonTableModel *persontablemodel = new PersonTableModel;
    persontablemodel->bindTable();
    RegisterTableModel *registertablemodel = new RegisterTableModel;
    registertablemodel->bindTable();

    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);

    //卡未被注册
    int row = registertablemodel->findRecord(CardId);
    if(row == -1){
        message.setText(tr("此卡未被注册，您是否拿错卡了"));
        message.exec();
        return ;
    }

    row = persontablemodel->findRecordByStudentId(StudentId);
    //有该学号则继续查找
    if(row >= 0){
        int res = persontablemodel->findPhoneByStudentId_tofound(Phone,row);
        //不是该手机号
        if(res == 0){
            message.setText(tr("学号对应手机号错误，请重新输入"));
            message.exec();
            return ;
        }
        else if(res == 1){
            message.setText(tr("解挂成功！"));
            message.exec();
            return ;
        }
        else {
            message.setText(tr("此卡已解挂，请勿重复解挂操作"));
            message.exec();
            return ;
        }
    }
    //如果没有该学号则返回错误信息
    else{
        message.setText(tr("学号尚未注册"));
        message.exec();
        return ;
    }
}

/**
 * @brief WriteOffPerson::on_btn_Return_clicked
 * 返回按钮点击事件
 */
void lostandfound::on_btn_Return_clicked(){
    this->close();
}
