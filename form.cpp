#include "form.h"
#include "ui_form.h"
#include <QStandardItemModel>
#include <QFile>
#include <QDataStream>
#include "doctorsappoinment.h"

Form::Form(QDate _date, QVector<Reminder *> *_reminders) :
    QWidget(0),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    reminders=_reminders;
    date=_date;
    ui->label_date->setText(date.toString());
    isEmpty=true;

    QStandardItemModel *model=new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Tipo")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Descripcion")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Hora")));

    int y=0;
    for(int x=0; x<reminders->size(); x++)
    {
        if((*reminders).at(x)->getDate()==date)
        {
            isEmpty=false;
            QStandardItem *item=new QStandardItem(QString((*reminders).at(x)->getType()));
            model->setItem(y,0,item);
            item=new QStandardItem(QString((*reminders).at(x)->getDescription()));
            model->setItem(y,1,item);
            item=new QStandardItem(QString((*reminders).at(x)->getDate().toString()));
            model->setItem(y,2,item);
            y++;
        }
    }
    ui->tableView->setModel(model);
}

Form::~Form()
{
    delete ui;
}

void Form::on_btnTxt_clicked()
{
    if(!isEmpty)
    {
        QFile outputFile(QDate::currentDate()+".txt");
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
