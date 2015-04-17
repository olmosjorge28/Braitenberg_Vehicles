#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T01:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = braitenburgVehicle
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vehicle.cpp \
    lights.cpp

HEADERS  += mainwindow.h \
    vehicle.h \
    lights.h

FORMS    += mainwindow.ui
