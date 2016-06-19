#ifndef FOTOALBUM_H
#define FOTOALBUM_H

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

private:
    Ui::fotoAlbum *ui;
};

#endif // FOTOALBUM_H
