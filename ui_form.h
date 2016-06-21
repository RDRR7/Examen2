/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_date;
    QLabel *Title;
    QPushButton *pushButton_add;
    QPushButton *pushButton_back;
    QComboBox *comboBox_type;
    QLabel *Title_2;
    QLabel *Title_3;
    QPlainTextEdit *msg;
    QLabel *Title_4;
    QTimeEdit *timeEdit;
    QLabel *background;
    QTableView *table;
    QPushButton *btn_txt;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(852, 467);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        Form->setPalette(palette);
        label_date = new QLabel(Form);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setGeometry(QRect(410, 10, 431, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_date->setFont(font);
        label_date->setAlignment(Qt::AlignCenter);
        Title = new QLabel(Form);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(10, 10, 371, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        Title->setFont(font1);
        pushButton_add = new QPushButton(Form);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(10, 330, 130, 130));
        pushButton_add->setStyleSheet(QStringLiteral("background-image: url(:/plus.jpg);"));
        pushButton_add->setFlat(true);
        pushButton_back = new QPushButton(Form);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(270, 330, 130, 130));
        pushButton_back->setStyleSheet(QStringLiteral("background-image: url(:/back.jpg);"));
        pushButton_back->setFlat(true);
        comboBox_type = new QComboBox(Form);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setGeometry(QRect(10, 220, 391, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        comboBox_type->setFont(font2);
        Title_2 = new QLabel(Form);
        Title_2->setObjectName(QStringLiteral("Title_2"));
        Title_2->setGeometry(QRect(10, 190, 201, 31));
        Title_2->setFont(font2);
        Title_3 = new QLabel(Form);
        Title_3->setObjectName(QStringLiteral("Title_3"));
        Title_3->setGeometry(QRect(10, 50, 201, 31));
        Title_3->setFont(font2);
        msg = new QPlainTextEdit(Form);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(10, 80, 391, 111));
        Title_4 = new QLabel(Form);
        Title_4->setObjectName(QStringLiteral("Title_4"));
        Title_4->setGeometry(QRect(10, 260, 201, 31));
        Title_4->setFont(font2);
        timeEdit = new QTimeEdit(Form);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(10, 291, 391, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Black"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        timeEdit->setFont(font3);
        timeEdit->setAlignment(Qt::AlignCenter);
        background = new QLabel(Form);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 851, 471));
        table = new QTableView(Form);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(430, 80, 401, 381));
        btn_txt = new QPushButton(Form);
        btn_txt->setObjectName(QStringLiteral("btn_txt"));
        btn_txt->setGeometry(QRect(140, 330, 130, 130));
        btn_txt->setAutoFillBackground(false);
        btn_txt->setStyleSheet(QStringLiteral("background-image: url(:/text.jpg);"));
        btn_txt->setFlat(true);
        background->raise();
        label_date->raise();
        Title->raise();
        pushButton_add->raise();
        pushButton_back->raise();
        comboBox_type->raise();
        Title_2->raise();
        Title_3->raise();
        msg->raise();
        Title_4->raise();
        timeEdit->raise();
        table->raise();
        btn_txt->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label_date->setText(QString());
        Title->setText(QApplication::translate("Form", "REMINDERS", 0));
        pushButton_add->setText(QString());
        pushButton_back->setText(QString());
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("Form", "DOCTOR", 0)
         << QApplication::translate("Form", "MARKET", 0)
         << QApplication::translate("Form", "PAYMENT", 0)
         << QApplication::translate("Form", "MEETING", 0)
        );
        Title_2->setText(QApplication::translate("Form", "TYPE:", 0));
        Title_3->setText(QApplication::translate("Form", "MESSAGE:", 0));
        Title_4->setText(QApplication::translate("Form", "HOUR:", 0));
        background->setText(QString());
        btn_txt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
