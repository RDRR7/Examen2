#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDate>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    //explicit Form(QWidget *parent = 0);
    Form(QDate date);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
