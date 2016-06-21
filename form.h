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
    void on_pushButton_back_clicked();
    void on_pushButton_add_clicked();
    void on_comboBox_type_currentIndexChanged(int index);
    void on_btn_txt_clicked();

private:
    Ui::Form *ui;
    QVector<Reminder*> *reminders;
    QDate date;
    bool isEmpty;
    int type;

    void initialize();
    void sendToTxt();
    void inOrder(int x, int y);
};

#endif // FORM_H
