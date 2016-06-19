#include "form_addnew.h"
#include "ui_form_addnew.h"
#include <QDate>
#include "doctorsappoinment.h"
#include <QTime>
#include <QFile>
#include <QTextStream>

Form_AddNew::Form_AddNew(QVector<Reminder*> *_reminders) :
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
    (*reminders)<<new DoctorsAppoinment(ui->textEdit->toPlainText(), ui->dateEdit->date(), QTime::currentTime());
}
