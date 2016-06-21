#ifndef GROCERY_H
#define GROCERY_H

#include "reminder.h"

class Grocery : public Reminder
{
public:
    Grocery(){}
    Grocery(QString _description, QDate _date);

    void toTxt(QTextStream *outStream);
    QTime getTime() const;
};
QDataStream &operator<<(QDataStream &out, const Grocery &grocery);
QDataStream &operator>>(QDataStream &in, Grocery &grocery);
#endif // GROCERY_H
