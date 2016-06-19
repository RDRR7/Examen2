#include "fotoalbum.h"
#include "ui_fotoalbum.h"

fotoAlbum::fotoAlbum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fotoAlbum)
{
    ui->setupUi(this);
    ui->background->setScaledContents(true);
    ui->background->setPixmap(QPixmap("background.jpg"));
}

fotoAlbum::~fotoAlbum()
{
    delete ui;
}
