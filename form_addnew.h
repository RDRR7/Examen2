#ifndef FORM_ADDNEW_H
#define FORM_ADDNEW_H

#include <QWidget>
#include <QVector>
#include "reminder.h"

namespace Ui {
class Form_AddNew;
}

class Form_AddNew : public QWidget
{
    Q_OBJECT

public:
    Form_AddNew(QVector<Reminder*> *_reminders);
    ~Form_AddNew();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_ok_clicked();

private:
    Ui::Form_AddNew *ui;
    QVector<Reminder*> *reminders;
};

#endif // FORM_ADDNEW_H
