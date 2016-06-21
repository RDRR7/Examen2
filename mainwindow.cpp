#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QImage>
#include "doctorsappoinment.h"
#include "grocery.h"
#include "payment.h"
#include "meeting.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initAll();
}

MainWindow::~MainWindow()
{
    deleteAll();
    serialize();
    delete ui;
}

void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{
    delete camera;

    camera=new QCamera(cameraInfo);

    camera->setViewfinder(ui->viewfinder);

    camera->start();

    capture = new QCameraImageCapture(camera);

    QImageEncoderSettings encoder_setting = capture->encodingSettings();
    encoder_setting.setCodec("image/jpeg");
    encoder_setting.setResolution(800,600);
    capture->setEncodingSettings(encoder_setting);
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
    form=new Form(date, &reminders);
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
    player->play();
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
    QString filePath =
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     musicPaths.isEmpty() ? QDir::homePath() : musicPaths.first(),
                                     tr("MP3 files (*.mp3);;All files (*.*)"));

    QStringList pieces = filePath.split( "/" );

    ui->listWidget->addItem(pieces.at(pieces.size()-1));
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
    player=new QMediaPlayer(this);
    playlist=new QMediaPlaylist;

    connect(player, &QMediaPlayer::positionChanged,this, MainWindow::onPositionChange);
    connect(player, &QMediaPlayer::durationChanged,this, MainWindow::onDurationChange);

    player->setVolume(ui->horizontalSlider_volume->value());
    player->setPlaylist(playlist);
    playlist->setCurrentIndex(1);
}

void MainWindow::initCamera()
{
    camera=NULL;

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
    InitServer();

    ui->background->setScaledContents(true);
    ui->background->setPixmap(QPixmap("background.jpg"));

    notes=new QList<QString>();
    currentNote=0;
    form=NULL;
    fa=NULL;

    unserialize();
}

void MainWindow::on_pushButton_album_clicked()
{
    delete fa;
    fa=new fotoAlbum();
    fa->setVisible(true);
}

void MainWindow::on_pushButton_addNote_clicked()
{
   QString note=ui->plainTextEdit->toPlainText();
   if(note!="")
   {
        if(!notes->isEmpty())
            currentNote++;
        notes->append(note);
        ui->plainTextEdit->clear();
   }
}

void MainWindow::on_pushButton_deleteNote_clicked()
{
    if(notes->isEmpty()){return;}
    notes->removeAt(currentNote);
    ui->plainTextEdit->setPlainText("");
}

void MainWindow::on_pushButton_forwardNote_clicked()
{
    if(notes->isEmpty()){return;}
    if(currentNote+1<notes->size())
    {
        currentNote++;
        ui->plainTextEdit->setPlainText(notes->at(currentNote));
    }
    else
    {
        currentNote=notes->size()-1;
        ui->plainTextEdit->setPlainText(notes->at(currentNote));
    }
}

void MainWindow::on_pushButton_backwardNote_clicked()
{
    if(notes->isEmpty()){return;}
    if(currentNote-1>=0)
    {
        currentNote--;
        ui->plainTextEdit->setPlainText(notes->at(currentNote));
    }
}

void MainWindow::serialize()
{
    QFile outputFile("reminder.rem");
    outputFile.open(QIODevice::WriteOnly);
    QDataStream out(&outputFile);
    for(int x=0; x<reminders.size(); x++)
    {
        QString type=reminders.at(x)->getType();
        out<<type;
        if(type=="DOCTOR")
        {
            out<<*(DoctorsAppoinment*)reminders.at(x);
        }
        else if(type=="GROCERY")
        {
            out<<*(Grocery*)reminders.at(x);
        }
        else if(type=="PAYMENT")
        {
            out<<*(Payment*)reminders.at(x);
        }
        else if(type=="MEETING")
        {
            out<<*(Payment*)reminders.at(x);
        }
    }
    outputFile.close();

    QFile outputFileNotes("notes.not");
    outputFileNotes.open(QIODevice::WriteOnly);
    QDataStream outNotes(&outputFileNotes);
    for(int x=0; x<notes->size(); x++)
    {
        outNotes<<(QString)notes->at(x);
    }
    outputFileNotes.close();
}

void MainWindow::unserialize()
{
    QFile inputFile("reminder.rem");
    inputFile.open(QIODevice::ReadOnly);
    QDataStream in(&inputFile);
    int x=0;
    while(!in.atEnd())
    {
        QString type;
        in>>type;
        if(type=="DOCTOR")
        {
            reminders<<new DoctorsAppoinment();
            in>>*(DoctorsAppoinment*)reminders.at(x);
        }
        else if(type=="GROCERY")
        {
            reminders<<new Grocery();
            in>>*(Grocery*)reminders.at(x);
        }
        else if(type=="PAYMENT")
        {
            reminders<<new Payment();
            in>>*(Payment*)reminders.at(x);
        }
        else if(type=="MEETING")
        {
            reminders<<new Meeting();
            in>>*(Meeting*)reminders.at(x);
        }
        x++;
    }
    inputFile.close();

    QFile inputFileNotes("notes.not");
    inputFileNotes.open(QIODevice::ReadOnly);
    QDataStream inNotes(&inputFileNotes);
    while(!inNotes.atEnd())
    {
        QString str;
        inNotes>>str;
        notes->append(str);
    }
    inputFileNotes.close();
    currentNote=notes->size()-1;
    if(!notes->isEmpty())
        ui->plainTextEdit->setPlainText(notes->at(currentNote));
}

void MainWindow::deleteAll()
{
    delete form;
    delete fa;
    delete camera;
}

void MainWindow::conexion_nueva()
{
    static int j = 0;
    tcpcliente[j] = tcpservidor->nextPendingConnection();
    connect(tcpcliente[j], SIGNAL(readyRead()), this, SLOT(leer_socketcliente()));
    j++;
}

void MainWindow::leer_socketcliente()
{
    if(tcpcliente[0]->bytesAvailable() > 0)
    {
        QByteArray buffer;
        buffer.resize(tcpcliente[0]->bytesAvailable());
        tcpcliente[0]->read(buffer.data(), buffer.size());

        if(QString(buffer) == "foto")
        {
            QImage image(takeImage());
            QByteArray ba;
            QBuffer buffer(&ba);
            image.save(&buffer, "JPEG");
            ba.append(buffer.data());

            QByteArray outBlock;
            QDataStream out(&outBlock, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_6);
            qint64 size = ba.size();
            out << size << ba;
            qDebug()<<size;
            tcpcliente[0]->write(outBlock);
        }
    }
}

void MainWindow::InitServer()
{
    QTcpSocket socket;
    socket.connectToHost("8.8.8.8", 53);
    if (socket.waitForConnected())
        address_str = socket.localAddress().toString();

    ui->serverLabel->setText("ADDRESS-"+address_str);

    tcpservidor = new QTcpServer(this);

    tcpservidor->setMaxPendingConnections(3);

    for(int i = 0; i < tcpservidor->maxPendingConnections(); i++)
    {
        tcpcliente[i] = new QTcpSocket(this);
    }

    QHostAddress address(address_str);
    tcpservidor->listen(address, 51717);

    connect(tcpservidor, SIGNAL(newConnection()), this, SLOT(conexion_nueva()));
}

QString MainWindow::takeImage()
{
    QString imgName = "imageCapture.jpg";
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->searchAndLock();
    capture->setCaptureDestination(QCameraImageCapture::CaptureToFile);

    capture->capture(imgName);
    camera->unlock();

    QStringList homePath = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);

    ui->label_img->setScaledContents(true);
    QPixmap image(homePath.first().split(QDir::separator()).last()+"\\"+imgName  );
    ui->label_img->setPixmap(image);

    return homePath.first().split(QDir::separator()).last()+"\\"+imgName;
}

void MainWindow::on_pushButton_img_clicked()
{
    takeImage();
}

void MainWindow::on_pushButton_clicked(){}


