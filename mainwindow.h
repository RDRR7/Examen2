#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCamera>
#include <QCameraInfo>
#include <QMediaMetaData>
#include <QActionGroup>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

////////////MULTIMEDIA///////////////
#include <QLabel>
#include <QSlider>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDir>

#include "form.h"
#include "fotoalbum.h"


#include <QMainWindow>

Q_DECLARE_METATYPE(QCameraInfo)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /////////////////////SLOTS///////////////////////////////

    void setCamera(const QCameraInfo &cameraInfo);
    void updateCameraDevice(QAction *action);

    /////////////////////////////////////////////////////////

    void on_comboBox_currentIndexChanged(int index);
    void on_calendarWidget_clicked(const QDate &date);
    void on_btn_youtube_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_horizontalSlider_progress_sliderMoved(int position);

    void on_horizontalSlider_volume_sliderMoved(int position);

    void openFile();
    void onPositionChange(qint64 position);
    void onDurationChange(qint64 position);

    void on_pushButton_album_clicked();

private:
    Ui::MainWindow *ui;

    //////////VARIABLES/////////////////

    QCamera *camera;
    QActionGroup *videoDevicesGroup;
    Form *form;

    /////////////MULTIMEDIA//////////////

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QString filePath;
    void initMedia();
    void initCamera();
    void initAll();
    //////////////////////////////////////
};

#endif // MAINWINDOW_H
