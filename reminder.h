#ifndef REMINDER_H
#define REMINDER_H

#include <QString>
#include <QDate>
#include <QTextStream>

class Reminder
{
public:
    Reminder(){}
    Reminder(QString _description, QDate _date);
    QString getDescription();
    QDate getDate();
    virtual QString getType()=0;
    virtual void toTxt(QTextStream *outStream)=0;

private:
    QString description;
    QDate date;
};

#endif // REMINDER_H
