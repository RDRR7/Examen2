#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDate>
#include <QVector>
#include "reminder.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QDate _date, QVector<Reminder*> *_reminders);
    ~Form();

private slots:
    void on_btnTxt_clicked();

private:
    Ui::Form *ui;
    QVector<Reminder*> *reminders;
    QDate date;
    bool isEmpty;
};

#endif // FORM_H
