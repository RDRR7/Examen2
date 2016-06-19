#include "fotoalbum.h"
#include "ui_fotoalbum.h"
#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>

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
}

fotoAlbum::~fotoAlbum()
{
    delete ui;
}

void fotoAlbum::on_pushButton_new_clicked()
{
    const QStringList imagePaths = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    filePath =
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     imagePaths.isEmpty() ? QDir::homePath() : imagePaths.first(),
                                     tr("Images (*.png *.jpg);;All files (*.*)"));
    if(filePath != "")
        imageCont++;

    //QRegExp rx("(\\ |\\,|\\.|\\:|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
    QStringList query = filePath.split('.');
    QString newPath = ALBUM_NAME+"/"+QString::number(imageCont)+"."+query.at(1);
    QFile::copy(filePath , newPath );
    paths->append(newPath);
    setImage(newPath);
    currentImageIndex = imageCont;


}

void fotoAlbum::on_pushButton_delete_clicked()
{
    paths->removeAt(currentImageIndex);

    if(paths->size() == 0){return;}

    if(currentImageIndex < paths->size() && currentImageIndex >= 0)
        setImage(paths->at(currentImageIndex));
    else if(currentImageIndex > paths->size() && currentImageIndex -1 >= 0)
    {
        setImage(paths->at(currentImageIndex-1));
        currentImageIndex--;
    }
    else
        setImage("");
}

void fotoAlbum::on_pushButton_up_clicked()
{
    if(currentImageIndex + 1 > paths->size()-1 ){return;}
    currentImageIndex++;
    setImage(paths->at(currentImageIndex));

}

void fotoAlbum::on_pushButton_down_clicked()
{
    if(currentImageIndex - 1 < 0 ){return;}
    currentImageIndex--;
    setImage(paths->at(currentImageIndex));
}

void fotoAlbum::setImage(QString _path)
{
    ui->image->setScaledContents(true);
    ui->image->setPixmap(QPixmap(_path));
}
