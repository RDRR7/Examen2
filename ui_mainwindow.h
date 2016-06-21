/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_youtube;
    QLabel *background;
    QComboBox *comboBox;
    QCalendarWidget *calendarWidget;
    QStackedWidget *stackedWidget;
    QWidget *viewfinderPage;
    QCameraViewfinder *viewfinder;
    QWidget *previewPage;
    QGridLayout *gridLayout_4;
    QLabel *lastImagePreviewLabel;
    QPlainTextEdit *plainTextEdit;
    QLabel *Title;
    QLabel *Title_2;
    QLabel *Title_3;
    QLabel *Title_4;
    QListWidget *listWidget;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_open;
    QPushButton *pushButton_start;
    QSlider *horizontalSlider_volume;
    QSlider *horizontalSlider_progress;
    QPushButton *pushButton_album;
    QPushButton *pushButton_forwardNote;
    QPushButton *pushButton_backwardNote;
    QPushButton *pushButton_addNote;
    QPushButton *pushButton_deleteNote;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 690);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_youtube = new QPushButton(centralWidget);
        btn_youtube->setObjectName(QStringLiteral("btn_youtube"));
        btn_youtube->setGeometry(QRect(710, 40, 300, 201));
        btn_youtube->setStyleSheet(QStringLiteral("background-image: url(:/parent.jpg);"));
        btn_youtube->setFlat(true);
        background = new QLabel(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 1500, 691));
        background->setStyleSheet(QStringLiteral(""));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 510, 641, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        comboBox->setFont(font);
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(1060, 40, 271, 241));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 20, 640, 480));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(145, 145, 145, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        stackedWidget->setPalette(palette1);
        viewfinderPage = new QWidget();
        viewfinderPage->setObjectName(QStringLiteral("viewfinderPage"));
        viewfinder = new QCameraViewfinder(viewfinderPage);
        viewfinder->setObjectName(QStringLiteral("viewfinder"));
        viewfinder->setGeometry(QRect(0, -1, 641, 480));
        stackedWidget->addWidget(viewfinderPage);
        previewPage = new QWidget();
        previewPage->setObjectName(QStringLiteral("previewPage"));
        gridLayout_4 = new QGridLayout(previewPage);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lastImagePreviewLabel = new QLabel(previewPage);
        lastImagePreviewLabel->setObjectName(QStringLiteral("lastImagePreviewLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lastImagePreviewLabel->sizePolicy().hasHeightForWidth());
        lastImagePreviewLabel->setSizePolicy(sizePolicy);
        lastImagePreviewLabel->setFrameShape(QFrame::Box);

        gridLayout_4->addWidget(lastImagePreviewLabel, 0, 0, 1, 1);

        stackedWidget->addWidget(previewPage);
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(1060, 340, 271, 261));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        plainTextEdit->setFont(font1);
        plainTextEdit->setStyleSheet(QStringLiteral("background-image: url(:/note.png);"));
        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(710, 0, 311, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(17);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        Title->setFont(font2);
        Title->setAlignment(Qt::AlignCenter);
        Title_2 = new QLabel(centralWidget);
        Title_2->setObjectName(QStringLiteral("Title_2"));
        Title_2->setGeometry(QRect(1060, 0, 271, 41));
        Title_2->setFont(font2);
        Title_2->setAlignment(Qt::AlignCenter);
        Title_3 = new QLabel(centralWidget);
        Title_3->setObjectName(QStringLiteral("Title_3"));
        Title_3->setGeometry(QRect(1060, 300, 271, 41));
        Title_3->setFont(font2);
        Title_3->setAlignment(Qt::AlignCenter);
        Title_4 = new QLabel(centralWidget);
        Title_4->setObjectName(QStringLiteral("Title_4"));
        Title_4->setGeometry(QRect(710, 340, 301, 41));
        Title_4->setFont(font2);
        Title_4->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(710, 390, 300, 150));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        listWidget->setPalette(palette2);
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Black"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        listWidget->setFont(font3);
        listWidget->setStyleSheet(QStringLiteral("background-image: url(:/playlist.png);"));
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(920, 580, 100, 100));
        pushButton_stop->setStyleSheet(QStringLiteral("background-image: url(:/stop.jpg);"));
        pushButton_stop->setFlat(true);
        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setGeometry(QRect(700, 580, 100, 100));
        pushButton_open->setStyleSheet(QStringLiteral("background-image: url(:/open.jpg);"));
        pushButton_open->setFlat(true);
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(810, 580, 100, 100));
        pushButton_start->setAutoFillBackground(false);
        pushButton_start->setStyleSheet(QStringLiteral("background-image: url(:/play.jpg);"));
        pushButton_start->setFlat(true);
        horizontalSlider_volume = new QSlider(centralWidget);
        horizontalSlider_volume->setObjectName(QStringLiteral("horizontalSlider_volume"));
        horizontalSlider_volume->setGeometry(QRect(930, 550, 81, 22));
        horizontalSlider_volume->setMaximum(100);
        horizontalSlider_volume->setValue(30);
        horizontalSlider_volume->setOrientation(Qt::Horizontal);
        horizontalSlider_progress = new QSlider(centralWidget);
        horizontalSlider_progress->setObjectName(QStringLiteral("horizontalSlider_progress"));
        horizontalSlider_progress->setGeometry(QRect(710, 550, 211, 22));
        horizontalSlider_progress->setOrientation(Qt::Horizontal);
        pushButton_album = new QPushButton(centralWidget);
        pushButton_album->setObjectName(QStringLiteral("pushButton_album"));
        pushButton_album->setGeometry(QRect(710, 260, 301, 71));
        pushButton_album->setStyleSheet(QStringLiteral("background-image: url(:/memories.jpg);"));
        pushButton_forwardNote = new QPushButton(centralWidget);
        pushButton_forwardNote->setObjectName(QStringLiteral("pushButton_forwardNote"));
        pushButton_forwardNote->setGeometry(QRect(1200, 610, 70, 70));
        pushButton_forwardNote->setStyleSheet(QStringLiteral("background-image: url(:/left.jpg);"));
        pushButton_forwardNote->setFlat(true);
        pushButton_backwardNote = new QPushButton(centralWidget);
        pushButton_backwardNote->setObjectName(QStringLiteral("pushButton_backwardNote"));
        pushButton_backwardNote->setGeometry(QRect(1270, 610, 70, 70));
        pushButton_backwardNote->setStyleSheet(QStringLiteral("background-image: url(:/right.jpg);"));
        pushButton_backwardNote->setFlat(true);
        pushButton_addNote = new QPushButton(centralWidget);
        pushButton_addNote->setObjectName(QStringLiteral("pushButton_addNote"));
        pushButton_addNote->setGeometry(QRect(1060, 610, 70, 70));
        pushButton_addNote->setStyleSheet(QStringLiteral("background-image: url(:/plus2.jpg);"));
        pushButton_addNote->setFlat(true);
        pushButton_deleteNote = new QPushButton(centralWidget);
        pushButton_deleteNote->setObjectName(QStringLiteral("pushButton_deleteNote"));
        pushButton_deleteNote->setGeometry(QRect(1130, 610, 70, 70));
        pushButton_deleteNote->setStyleSheet(QStringLiteral("background-image: url(:/minus2.jpg);"));
        pushButton_deleteNote->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);
        background->raise();
        btn_youtube->raise();
        comboBox->raise();
        calendarWidget->raise();
        stackedWidget->raise();
        plainTextEdit->raise();
        Title->raise();
        Title_2->raise();
        Title_3->raise();
        Title_4->raise();
        listWidget->raise();
        pushButton_stop->raise();
        pushButton_open->raise();
        pushButton_start->raise();
        horizontalSlider_volume->raise();
        horizontalSlider_progress->raise();
        pushButton_album->raise();
        pushButton_forwardNote->raise();
        pushButton_backwardNote->raise();
        pushButton_addNote->raise();
        pushButton_deleteNote->raise();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_youtube->setText(QString());
        background->setText(QString());
        lastImagePreviewLabel->setText(QString());
        Title->setText(QApplication::translate("MainWindow", "LEARN TO BE A PARENT", 0));
        Title_2->setText(QApplication::translate("MainWindow", "ADD A REMINDER", 0));
        Title_3->setText(QApplication::translate("MainWindow", "ADD A NOTE", 0));
        Title_4->setText(QApplication::translate("MainWindow", "REPRODUCTOR MP3", 0));
        pushButton_stop->setText(QString());
        pushButton_open->setText(QString());
        pushButton_start->setText(QString());
        pushButton_album->setText(QString());
        pushButton_forwardNote->setText(QString());
        pushButton_backwardNote->setText(QString());
        pushButton_addNote->setText(QString());
        pushButton_deleteNote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
