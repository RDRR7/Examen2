#include "doctorsappoinment.h"

DoctorsAppoinment::DoctorsAppoinment(QString _description, QDate _date, QTime _time): Reminder(_description, _date)
{
    time=_time;
}

QTime DoctorsAppoinment::getTime()
{
    return time;
}