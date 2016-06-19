#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QUrl>
#include "doctorsappoinment.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera=NULL;
    form=NULL;
    form_AddNew=NULL;
    videoDevicesGroup=new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);

    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras())
    {
        QAction *videoDeviceAction=new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);

        ui->comboBox->addItem(cameraInfo.description());
    }

    setCamera(QCameraInfo::defaultCamera());

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
        x++;
    }
    inputFile.close();
}

MainWindow::~MainWindow()
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
    }
    outputFile.close();
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
    form=new Form(date, &reminders);
    form->show();
}

void MainWindow::on_btn_youtube_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.youtube.com"));
}

void MainWindow::on_btn_rem_clicked()
{
    delete form_AddNew;
    form_AddNew=new Form_AddNew(&reminders);
    form_AddNew->show();
}
