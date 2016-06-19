#include "form.h"
#include "ui_form.h"

Form::Form(QDate date) :
    QWidget(0),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->label_date->setText(date.toString());

    ui->background->setScaledContents(true);
    ui->background->setPixmap(QPixmap("background.jpg"));
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_back_clicked()
{
    this->setVisible(false);
}
