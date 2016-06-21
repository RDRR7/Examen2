#ifndef MEETING_H
#define MEETING_H

#include <QTime>
#include "reminder.h"

class Meeting : public Reminder
{
public:
    Meeting(){}
    Meeting(QString _description, QDate _date, QTime _time);

    QTime getTime() const;
    void toTxt(QTextStream *outStream);

private:
    QTime time;
};

QDataStream &operator<<(QDataStream &out, const Meeting &meeting);
QDataStream &operator>>(QDataStream &in, Meeting &meeting);

#endif // MEETING_H
