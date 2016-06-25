#-------------------------------------------------
#
# Project showd by QtCreator 2016-06-25T14:04:39
#
#-------------------------------------------------

QT       += core gui opengl quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flickerExample
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    qml.qrc
