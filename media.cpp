#include "media.h"

Media::Media()
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist;
}


