/********************************************************************************
** Form generated from reading UI file 'fotoalbum.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOTOALBUM_H
#define UI_FOTOALBUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fotoAlbum
{
public:
    QLabel *background;
    QLabel *foto;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QPushButton *pushButton_new;
    QPushButton *pushButton_delete;

    void setupUi(QWidget *fotoAlbum)
    {
        if (fotoAlbum->objectName().isEmpty())
            fotoAlbum->setObjectName(QStringLiteral("fotoAlbum"));
        fotoAlbum->resize(800, 600);
        background = new QLabel(fotoAlbum);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 800, 600));
        foto = new QLabel(fotoAlbum);
        foto->setObjectName(QStringLiteral("foto"));
        foto->setGeometry(QRect(50, 50, 500, 500));
        pushButton_up = new QPushButton(fotoAlbum);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setGeometry(QRect(620, 40, 125, 125));
        pushButton_down = new QPushButton(fotoAlbum);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        pushButton_down->setGeometry(QRect(620, 180, 125, 125));
        pushButton_new = new QPushButton(fotoAlbum);
        pushButton_new->setObjectName(QStringLiteral("pushButton_new"));
        pushButton_new->setGeometry(QRect(620, 320, 125, 125));
        pushButton_delete = new QPushButton(fotoAlbum);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(620, 450, 125, 125));

        retranslateUi(fotoAlbum);

        QMetaObject::connectSlotsByName(fotoAlbum);
    } // setupUi

    void retranslateUi(QWidget *fotoAlbum)
    {
        fotoAlbum->setWindowTitle(QApplication::translate("fotoAlbum", "Form", 0));
        background->setText(QString());
        foto->setText(QString());
        pushButton_up->setText(QApplication::translate("fotoAlbum", "up", 0));
        pushButton_down->setText(QApplication::translate("fotoAlbum", "down", 0));
        pushButton_new->setText(QApplication::translate("fotoAlbum", "new", 0));
        pushButton_delete->setText(QApplication::translate("fotoAlbum", "delete", 0));
    } // retranslateUi

};

namespace Ui {
    class fotoAlbum: public Ui_fotoAlbum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOTOALBUM_H
