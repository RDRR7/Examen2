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
    form.cpp \
    form_addnew.cpp

HEADERS  += mainwindow.h \
    reminder.h \
    doctorsappoinment.h \
    form.h \
    form_addnew.h

FORMS    += mainwindow.ui \
    form.ui \
    form_addnew.ui
