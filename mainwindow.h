#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCamera>
#include <QCameraInfo>
#include <QMediaMetaData>
#include <QActionGroup>
#include <QVector>
#include <QFile>
#include <QDataStream>
#include "form.h"
#include "form_addnew.h"
#include "reminder.h"

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

    void on_btn_rem_clicked();

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QActionGroup *videoDevicesGroup;
    Form *form;
    Form_AddNew *form_AddNew;
    QVector<Reminder*> reminders;
};

#endif // MAINWINDOW_H
