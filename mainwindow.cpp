#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
