#include "doctorsappoinment.h"

DoctorsAppoinment::DoctorsAppoinment(QString _description, QDate _date, QTime _time): Reminder(_description, _date, "DOCTOR")
{
    time=_time;
}

QTime DoctorsAppoinment::getTime() const
{
    return time;
}

void DoctorsAppoinment::toTxt(QTextStream *outStream)
{
    (*outStream)<<"Doctor: "+getDescription()+" "+ "Fecha: "+getDate().toString()+" "+ time.toString()+"\r\n";
}

QDataStream &operator<<(QDataStream &out, const DoctorsAppoinment &doctorsAppoinment)
{
    out << doctorsAppoinment.getDescription() << doctorsAppoinment.getDate() <<doctorsAppoinment.getTime();
    return out;
}

QDataStream &operator>>(QDataStream &in, DoctorsAppoinment &doctorsAppoinment)
{
    QString _despcription;
    QDate _date;
    QTime _time;
    in >> _despcription >> _date >> _time;
    doctorsAppoinment=DoctorsAppoinment(_despcription, _date, _time);
    return in;
}
