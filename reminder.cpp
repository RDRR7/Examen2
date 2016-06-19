#include "reminder.h"

Reminder::Reminder(QString _description, QDate _date, QString _type)
{
    description=_description;
    date=_date;
    type=_type;
}

QString Reminder::getDescription() const
{
    return description;
}

QDate Reminder::getDate() const
{
    return date;
}

QString Reminder::getType() const
{
    return type;
}

