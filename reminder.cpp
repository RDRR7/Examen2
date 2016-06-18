#include "reminder.h"

Reminder::Reminder(QString _description, QDate _date)
{
    description=_description;
    date=_date;
}

QString Reminder::getDescription()
{
    return description;
}

QDate Reminder::getDate()
{
    return date;
}
