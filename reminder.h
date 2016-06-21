#ifndef REMINDER_H
#define REMINDER_H

#include <QString>
#include <QDate>
#include <QTextStream>
#include <QDataStream>
#include <QTime>

class Reminder
{
public:
    Reminder(){}
    Reminder(QString _description, QDate _date, QString _type);

    QString getDescription() const;
    QDate getDate() const;
    QString getType() const;

    virtual QTime getTime() const;
    virtual void toTxt(QTextStream *outStream)=0;

private:
    QString description;
    QDate date;
    QString type;
};

#endif // REMINDER_H
