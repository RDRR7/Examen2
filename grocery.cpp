#include "grocery.h"

Grocery::Grocery(QString _description, QDate _date): Reminder(_description, _date, "GROCERY")
{}

void Grocery::toTxt(QTextStream *outStream)
{
    (*outStream)<<"Grocery: "+getDescription()+" "+ "Date: "+getDate().toString()+"\r\n";
}

QDataStream &operator<<(QDataStream &out, const Grocery &grocery)
{
    out << grocery.getDescription() << grocery.getDate();
    return out;
}

QDataStream &operator>>(QDataStream &in, Grocery &grocery)
{
    QString _despcription;
    QDate _date;
    in >> _despcription >> _date;
    grocery=Grocery(_despcription, _date);
    return in;
}

QTime Grocery::getTime() const
{
    return QTime(23, 59, 59, 99);
}
