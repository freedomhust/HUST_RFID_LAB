/********************************************************************************
** Form generated from reading UI file 'lostandfound.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSTANDFOUND_H
#define UI_LOSTANDFOUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lostandfound
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QTextEdit *textEdit_Student;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_phone;
    QPushButton *btn_Lost;
    QPushButton *btn_Return;
    QPushButton *btn_Found;
    QLineEdit *lineEdit_cardId;
    QPushButton *btn_Inventory;

    void setupUi(QDialog *lostandfound)
    {
        if (lostandfound->objectName().isEmpty())
            lostandfound->setObjectName(QStringLiteral("lostandfound"));
        lostandfound->resize(576, 230);
        verticalLayoutWidget = new QWidget(lostandfound);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 261, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        textEdit_Student = new QTextEdit(verticalLayoutWidget);
        textEdit_Student->setObjectName(QStringLiteral("textEdit_Student"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_Student->sizePolicy().hasHeightForWidth());
        textEdit_Student->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(textEdit_Student);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        textEdit_phone = new QTextEdit(verticalLayoutWidget);
        textEdit_phone->setObjectName(QStringLiteral("textEdit_phone"));

        horizontalLayout_2->addWidget(textEdit_phone);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_Lost = new QPushButton(lostandfound);
        btn_Lost->setObjectName(QStringLiteral("btn_Lost"));
        btn_Lost->setGeometry(QRect(20, 160, 93, 28));
        btn_Return = new QPushButton(lostandfound);
        btn_Return->setObjectName(QStringLiteral("btn_Return"));
        btn_Return->setGeometry(QRect(410, 160, 93, 28));
        btn_Found = new QPushButton(lostandfound);
        btn_Found->setObjectName(QStringLiteral("btn_Found"));
        btn_Found->setGeometry(QRect(220, 160, 93, 28));
        lineEdit_cardId = new QLineEdit(lostandfound);
        lineEdit_cardId->setObjectName(QStringLiteral("lineEdit_cardId"));
        lineEdit_cardId->setGeometry(QRect(280, 40, 181, 41));
        btn_Inventory = new QPushButton(lostandfound);
        btn_Inventory->setObjectName(QStringLiteral("btn_Inventory"));
        btn_Inventory->setGeometry(QRect(470, 50, 93, 28));

        retranslateUi(lostandfound);

        QMetaObject::connectSlotsByName(lostandfound);
    } // setupUi

    void retranslateUi(QDialog *lostandfound)
    {
        lostandfound->setWindowTitle(QApplication::translate("lostandfound", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("lostandfound", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("lostandfound", "\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        btn_Lost->setText(QApplication::translate("lostandfound", "\346\214\202\345\244\261", Q_NULLPTR));
        btn_Return->setText(QApplication::translate("lostandfound", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_Found->setText(QApplication::translate("lostandfound", "\350\247\243\346\214\202", Q_NULLPTR));
        btn_Inventory->setText(QApplication::translate("lostandfound", "\350\257\206\345\210\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lostandfound: public Ui_lostandfound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSTANDFOUND_H
