#include "meeting.h"

Meeting::Meeting(QString _description, QDate _date, QTime _time): Reminder(_description, _date, "MEETING")
{
    time=_time;
}

QTime Meeting::getTime() const
{
    return time;
}

void Meeting::toTxt(QTextStream *outStream)
{
    (*outStream)<<"Meeting: "+getDescription()+" "+ "Date and Time: "+getDate().toString()+" "+ time.toString("h:m ap")+"\r\n";
}

QDataStream &operator<<(QDataStream &out, const Meeting &meeting)
{
    out << meeting.getDescription() << meeting.getDate() <<meeting.getTime();
    return out;
}

QDataStream &operator>>(QDataStream &in, Meeting &meeting)
{
    QString _despcription;
    QDate _date;
    QTime _time;
    in >> _despcription >> _date >> _time;
    meeting=Meeting(_despcription, _date, _time);
    return in;
}


