#ifndef MEDIA_H
#define MEDIA_H


#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

#include <QLabel>
#include <QSlider>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDir>

class Media
{
public:
    Media();

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QString filePath = "";
};

#endif // MEDIA_H
