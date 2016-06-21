#ifndef DOCTORSAPPOINMENT_H
#define DOCTORSAPPOINMENT_H

#include <QTime>
#include "reminder.h"

class DoctorsAppoinment : public Reminder
{
public:
    DoctorsAppoinment(){}
    DoctorsAppoinment(QString _description, QDate _date, QTime _time);

    QTime getTime() const;
    void toTxt(QTextStream *outStream);

private:
    QTime time;
};

QDataStream &operator<<(QDataStream &out, const DoctorsAppoinment &doctorsAppoinment);
QDataStream &operator>>(QDataStream &in, DoctorsAppoinment &doctorsAppoinment);

#endif // DOCTORSAPPOINMENT_H
