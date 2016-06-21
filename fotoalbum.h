#ifndef FOTOALBUM_H
#define FOTOALBUM_H
#include <QList>

#include <QWidget>

namespace Ui {
class fotoAlbum;
}

class fotoAlbum : public QWidget
{
    Q_OBJECT

public:
    explicit fotoAlbum(QWidget *parent = 0);
    ~fotoAlbum();

private slots:
    void on_pushButton_new_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_up_clicked();
    void on_pushButton_down_clicked();

private:
    Ui::fotoAlbum *ui;
    QList<QString> *paths;
    const QString ALBUM_NAME="Album";
    int imageCont;
    int currentImageIndex;
    void setImage(QString _path);
    void serialize();
    void unserialize();
};

#endif // FOTOALBUM_H
