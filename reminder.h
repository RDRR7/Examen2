#ifndef REMINDER_H
#define REMINDER_H

#include <QString>
#include <QDate>

class Reminder
{
public:
    Reminder(QString _description, QDate _date);
    QString getDescription();
    QDate getDate();

private:
    QString description;
    QDate date;

};

#endif // REMINDER_H
