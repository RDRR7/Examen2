#include "payment.h"

Payment::Payment(QString _description, QDate _date): Reminder(_description, _date, "PAYMENT")
{}

void Payment::toTxt(QTextStream *outStream)
{
    (*outStream)<<"Payment: "+getDescription()+" "+ "Date: "+getDate().toString()+"\r\n";
}

QDataStream &operator<<(QDataStream &out, const Payment &payment)
{
    out << payment.getDescription() << payment.getDate();
    return out;
}

QDataStream &operator>>(QDataStream &in, Payment &payment)
{
    QString _despcription;
    QDate _date;
    in >> _despcription >> _date;
    payment=Payment(_despcription, _date);
    return in;
}

QTime Payment::getTime() const
{
    return QTime(23, 59, 59, 99);
}
