#ifndef LOSTANDFOUND_H
#define LOSTANDFOUND_H

#include <QDialog>
#include "serialThread/serialportthread.h"
#include "database/dbmanager.h"
#include "inc/m1356dll.h"

namespace Ui {
class lostandfound;
}

class lostandfound : public QDialog
{
    Q_OBJECT

public:
    explicit lostandfound(QWidget *parent = 0,SerialPortThread *serialPortThread = 0);
    ~lostandfound();

private slots:

    void on_btn_Lost_clicked();//挂失按钮点击事件

    void on_btn_Return_clicked();//返回按钮点击事件

    void on_btn_Inventory_clicked();//识别按钮点击事件

    void on_btn_Found_clicked();//解挂按钮点击事件

    void on_tagIdReceived(QString tagId);//卡号接收槽

private:
    Ui::lostandfound *ui;

    SerialPortThread *serialPortThread;//串口线程

    M1356Dll *m1356dll;//13.56MHz模块库
};

#endif // LOSTANDFOUND_H
