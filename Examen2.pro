#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T10:09:48
#
#-------------------------------------------------

QT       += core gui
QT += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Examen2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reminder.cpp \
    doctorsappoinment.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    reminder.h \
    doctorsappoinment.h \
    form.h

FORMS    += mainwindow.ui \
    form.ui
target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/camera
INSTALLS += target
