#-------------------------------------------------
#
# Project created by QtCreator 2014-06-23T00:27:11
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gdcad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    circle.cpp \
    ellipse.cpp \
    point.cpp \
    line.cpp

HEADERS  += mainwindow.h \
    circle.h \
    ellipse.h \
    point.h \
    line.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
