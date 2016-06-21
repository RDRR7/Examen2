#ifndef PAYMENT_H
#define PAYMENT_H

#include "reminder.h"

class Payment : public Reminder
{
public:
    Payment(){}
    Payment(QString _description, QDate _date);

    void toTxt(QTextStream *outStream);
    QTime getTime() const;
};

QDataStream &operator<<(QDataStream &out, const Payment &payment);
QDataStream &operator>>(QDataStream &in, Payment &payment);

#endif // PAYMENT_H
