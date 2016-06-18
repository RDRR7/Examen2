#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCamera>
#include <QCameraInfo>
#include <QMediaMetaData>
#include <QActionGroup>

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

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QActionGroup *videoDevicesGroup;
};

#endif // MAINWINDOW_H
