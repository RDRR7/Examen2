#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initAll();
}

MainWindow::~MainWindow()
{
    delete camera;
    delete ui;
}

void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{
    delete camera;

    camera = new QCamera(cameraInfo);

    camera->setViewfinder(ui->viewfinder);

    camera->start();
}

void MainWindow::updateCameraDevice(QAction *action)
{
    setCamera(qvariant_cast<QCameraInfo>(action->data()));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    updateCameraDevice(videoDevicesGroup->actions().at(index));
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    delete form;
    form=new Form(date);
    form->show();
}

void MainWindow::on_btn_youtube_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/channel/UCvw7rZIoXbNTFBc987hjS6Q"));
}

void MainWindow::on_pushButton_open_clicked()
{
    openFile();
}

void MainWindow::on_pushButton_start_clicked()
{
    //Load file
    //when fireup set media will fire up durationchange and when play it going to start seeking for that file
    //player->setMedia(QUrl::fromLocalFile(ui->listWidget->item(cont)->text()));
    player->play();
    qDebug() << player->errorString();
}

void MainWindow::on_pushButton_stop_clicked()
{
    player->stop();
}

void MainWindow::on_horizontalSlider_progress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_horizontalSlider_volume_sliderMoved(int position)
{
    player->setVolume(position);
}
void MainWindow::openFile()
{
    const QStringList musicPaths = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    filePath =
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     musicPaths.isEmpty() ? QDir::homePath() : musicPaths.first(),
                                     tr("MP3 files (*.mp3);;All files (*.*)"));
    ui->listWidget->addItem(filePath);

    playlist->addMedia(QUrl(filePath));
}
void MainWindow::onPositionChange(qint64 position)
{
    ui->horizontalSlider_progress->setValue(position);
}
void MainWindow::onDurationChange(qint64 position)
{
    ui->horizontalSlider_progress->setMaximum(position);
}
void MainWindow::initMedia()
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist;

    connect(player, &QMediaPlayer::positionChanged,this, MainWindow::onPositionChange);
    connect(player, &QMediaPlayer::durationChanged,this, MainWindow::onDurationChange);
    player->setVolume(ui->horizontalSlider_volume->value());
    player->setPlaylist(playlist);
    playlist->setCurrentIndex(1);
}

void MainWindow::initCamera()
{
    camera=NULL;
    form=NULL;
    videoDevicesGroup=new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);



    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras()) {
        QAction *videoDeviceAction=new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);

        ui->comboBox->addItem(cameraInfo.description());
    }

    setCamera(QCameraInfo::defaultCamera());
}

void MainWindow::initAll()
{
    initCamera();
    initMedia();
    ui->background->setScaledContents(true);
    ui->background->setPixmap(QPixmap("background.jpg"));
    notes = new QList<QString>();

}

void MainWindow::on_pushButton_album_clicked()
{
    fotoAlbum *fa = new fotoAlbum();
    fa->setVisible(true);
}

void MainWindow::on_pushButton_addNote_clicked()
{
   QString _note = ui->plainTextEdit->toPlainText();
   if(_note != "")
   {
        if(!notes->isEmpty())
            currentNote++;
        notes->append(_note);
        ui->plainTextEdit->clear();
   }
}

void MainWindow::on_pushButton_deleteNote_clicked()
{
    if(notes->isEmpty()){return;}
    notes->removeAt(currentNote);
}

void MainWindow::on_pushButton_forwardNote_clicked()
{
    if(notes->isEmpty()){return;}
    if(currentNote+1 < notes->size())
    {
        currentNote++;
        ui->plainTextEdit->setPlainText(notes->at(currentNote));
    }
}

void MainWindow::on_pushButton_backwardNote_clicked()
{
    if(notes->isEmpty()){return;}
    if(currentNote-1 >= 0)
    {
        currentNote--;
        ui->plainTextEdit->setPlainText(notes->at(currentNote));
    }
}
