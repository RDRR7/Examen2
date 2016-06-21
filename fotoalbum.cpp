#include "fotoalbum.h"
#include "ui_fotoalbum.h"
#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>

fotoAlbum::fotoAlbum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fotoAlbum)
{
    ui->setupUi(this);
    ui->background->setScaledContents(true);
    ui->background->setPixmap(QPixmap("background.jpg"));
    paths = new QList<QString>();

    if(!QDir(ALBUM_NAME).exists())
        QDir().mkdir(ALBUM_NAME);

    unserialize();
}

fotoAlbum::~fotoAlbum()
{
    delete ui;
}

void fotoAlbum::on_pushButton_new_clicked()
{
    const QStringList imagePaths = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QString filePath=
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     imagePaths.isEmpty() ? QDir::homePath() : imagePaths.first(),
                                     tr("Images (*.png *.jpg);;All files (*.*)"));
    if(filePath!="")
        imageCont++;

    QStringList query = filePath.split('.');
    QString newPath=ALBUM_NAME+"/"+QString::number(imageCont)+"."+query.at(1);
    QFile::copy(filePath , newPath );

    paths->append(newPath);
    setImage(newPath);
    currentImageIndex++;
    serialize();
}

void fotoAlbum::on_pushButton_delete_clicked()
{
    QFile file (paths->at(currentImageIndex));
    file.remove();

    paths->removeAt(currentImageIndex);

    if(!paths->isEmpty())
    {
        setImage(paths->last());
        currentImageIndex=paths->size()-1;
    }
    else
    {
        setImage("");
        currentImageIndex=0;
    }
    serialize();
}

void fotoAlbum::on_pushButton_up_clicked()
{
    if(currentImageIndex<paths->size())
    {
        currentImageIndex++;
        if(currentImageIndex==paths->size())
            currentImageIndex--;
        setImage(paths->at(currentImageIndex));
    }
}

void fotoAlbum::on_pushButton_down_clicked()
{
    if(currentImageIndex>=0 && !paths->isEmpty())
    {
        currentImageIndex--;
        if(currentImageIndex==-1)
            currentImageIndex=0;
        setImage(paths->at(currentImageIndex));
    }
}

void fotoAlbum::setImage(QString _path)
{
    ui->image->setScaledContents(true);
    ui->image->setPixmap(QPixmap(_path));
}

void fotoAlbum::serialize()
{
    QFile outputFile("paths.pat");
    outputFile.open(QIODevice::WriteOnly);
    QDataStream out(&outputFile);
    for(int x=0; x<paths->size(); x++)
    {
        out<<(QString)paths->at(x);
    }
    outputFile.close();
}

void fotoAlbum::unserialize()
{
    QFile inputFile("paths.pat");
    inputFile.open(QIODevice::ReadOnly);
    QDataStream in(&inputFile);
    imageCont=0;
    while(!in.atEnd())
    {
        QString str;
        in>>str;
        paths->append(str);
        imageCont++;

    }
    inputFile.close();
    currentImageIndex=imageCont;
    if(imageCont!=0)
        setImage(paths->at(currentImageIndex-1));
}
