#ifndef DOCTORSAPPOINMENT_H
#define DOCTORSAPPOINMENT_H

#include <QTime>
#include "reminder.h"

class DoctorsAppoinment : public Reminder
{
public:
    DoctorsAppoinment(QString _description, QDate _date, QTime _time);
    QTime getTime();

private:
    QTime time;
};

#endif // DOCTORSAPPOINMENT_H
