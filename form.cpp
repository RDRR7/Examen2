#include "form.h"
#include "ui_form.h"

Form::Form(QDate date) :
    QWidget(0),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->label_date->setText(date.toString());
    ui->tableView->
}

Form::~Form()
{
    delete ui;
}
