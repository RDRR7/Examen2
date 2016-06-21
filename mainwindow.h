#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCamera>
#include <QCameraInfo>
#include <QMediaMetaData>
#include <QActionGroup>
#include <QCameraImageCapture>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

#include <QSlider>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDir>
#include <QList>

#include <QVector>
#include <QFile>
#include <QDataStream>

#include <QUrl>
#include <QImage>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QBuffer>
#include <QThread>

#include "form.h"
#include "fotoalbum.h"
#include "reminder.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>

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

    void setCamera(const QCameraInfo &cameraInfo);
    void updateCameraDevice(QAction *action);
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
    void on_pushButton_addNote_clicked();
    void on_pushButton_deleteNote_clicked();
    void on_pushButton_forwardNote_clicked();
    void on_pushButton_backwardNote_clicked();
    void on_pushButton_clicked();
    void conexion_nueva();
    void leer_socketcliente();
    void on_pushButton_img_clicked();

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QCameraImageCapture * capture;
    QActionGroup *videoDevicesGroup;
    Form *form;
    QList<QString> *notes;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    fotoAlbum *fa;
    QVector<Reminder*> reminders;
    int currentNote;

    QTcpServer *tcpservidor;
    QTcpSocket *tcpcliente[3];
    QString takeImage();
    QString address_str;

    void initMedia();
    void InitServer();
    void initCamera();
    void initAll();
    void serialize();
    void unserialize();
    void deleteAll();
};

#endif // MAINWINDOW_H
