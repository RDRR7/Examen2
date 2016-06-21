#include "form.h"
#include "ui_form.h"
#include <QStandardItemModel>
#include <QFile>
#include <QDataStream>
#include "doctorsappoinment.h"
#include "grocery.h"
#include "payment.h"
#include "meeting.h"

Form::Form(QDate _date, QVector<Reminder*> *_reminders) :
    QWidget(0),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    reminders=_reminders;
    date=_date;
    isEmpty=true;
    type=0;

    ui->label_date->setText(date.toString());
    ui->timeEdit->setTime(QTime::currentTime());
    ui->background->setScaledContents(true);
    ui->background->setPixmap(QPixmap("background.jpg"));

    initialize();
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_back_clicked()
{
    this->setVisible(false);
}

void Form::initialize()
{
    QStandardItemModel *model=new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Type")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Description")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Hour")));

    inOrder(0,1);

    int y=0;
    for(int x=0; x<reminders->size(); x++)
    {
        if((*reminders).at(x)->getDate()==date)
        {
            isEmpty=false;
            if((*reminders).at(x)->getType()=="DOCTOR")
            {
                QStandardItem *item=new QStandardItem(QString((*reminders).at(x)->getType()));
                model->setItem(y,0,item);
                item=new QStandardItem(QString((*reminders).at(x)->getDescription()));
                model->setItem(y,1,item);
                item=new QStandardItem(QString(((DoctorsAppoinment*)(*reminders).at(x))->getTime().toString("h:m ap")));
                model->setItem(y,2,item);
                y++;
            }
            else if((*reminders).at(x)->getType()=="MEETING")
            {
                QStandardItem *item=new QStandardItem(QString((*reminders).at(x)->getType()));
                model->setItem(y,0,item);
                item=new QStandardItem(QString((*reminders).at(x)->getDescription()));
                model->setItem(y,1,item);
                item=new QStandardItem(QString(((Meeting*)(*reminders).at(x))->getTime().toString("h:m ap")));
                model->setItem(y,2,item);
                y++;
            }
            else
            {
                QStandardItem *item=new QStandardItem(QString((*reminders).at(x)->getType()));
                model->setItem(y,0,item);
                item=new QStandardItem(QString((*reminders).at(x)->getDescription()));
                model->setItem(y,1,item);
                item=new QStandardItem(QString("All day"));
                model->setItem(y,2,item);
                y++;
            }
        }
    }
    ui->table->setModel(model);
}

void Form::sendToTxt()
{
    if(!isEmpty)
    {
        QFile outputFile(QDate::currentDate().toString()+".txt");
        outputFile.open(QIODevice::WriteOnly);
        QTextStream *outStream=new QTextStream(&outputFile);
        for(int x=0; x<reminders->size(); x++)
        {
            if((*reminders).at(x)->getDate()==date)
            {
                (*reminders)[x]->toTxt(outStream);
            }
        }
        delete outStream;
        outputFile.close();
    }
}

void Form::on_pushButton_add_clicked()
{
    if(ui->msg->toPlainText()!="")
    {
        if(type==0)
            (*reminders)<<new DoctorsAppoinment(ui->msg->toPlainText(), date , ui->timeEdit->time());
        else if(type==1)
            (*reminders)<<new Grocery(ui->msg->toPlainText(), date);
        else if(type==2)
            (*reminders)<<new Payment(ui->msg->toPlainText(), date);
        else if(type==3)
            (*reminders)<<new DoctorsAppoinment(ui->msg->toPlainText(), date , ui->timeEdit->time());
        initialize();
    }
}

void Form::on_comboBox_type_currentIndexChanged(int index)
{
    type=index;
    if(type==1 || type==2)
        ui->timeEdit->setEnabled(false);
    else
        ui->timeEdit->setEnabled(true);
}

void Form::on_btn_txt_clicked()
{
    sendToTxt();
}

void Form::inOrder(int x, int y)
{
    if(reminders->size()<=1 || x==reminders->size())
        return;
    if((*reminders).at(x)->getTime()>(*reminders).at(y)->getTime())
    {
        Reminder *tmp=reminders->at(x);
        reminders->replace(x, reminders->at(y));
        reminders->replace(y, tmp);
    }
    if(y<reminders->size()-1)
        inOrder(x, y+1);
    else
        inOrder(x+1, x+1);
}
