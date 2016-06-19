#include "form_addnew.h"
#include "ui_form_addnew.h"
#include <QDate>
#include <QtCore>

Form_AddNew::Form_AddNew(QVector<Reminder> *_reminders) :
    QWidget(0),
    ui(new Ui::Form_AddNew)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    reminders=_reminders;
}

Form_AddNew::~Form_AddNew()
{
    delete ui;
}

void Form_AddNew::on_btn_cancel_clicked()
{
    this->setVisible(false);
}


void Form_AddNew::on_btn_ok_clicked()
{
    (*reminders)<<Reminder(ui->textEdit->toPlainText(), ui->dateEdit->date());
    qDebug()<<(*reminders)[0].getDescription();
}
