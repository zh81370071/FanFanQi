#-------------------------------------------------
#
# Project created by QtCreator 2021-09-25T16:29:30
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FanFanQi
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    startscene.cpp \
    mypushbutton.cpp \
    selectscene.cpp \
    playscene.cpp \
    coinbutton.cpp \
    dataconfig.cpp

HEADERS  += mymainwindow.h \
    startscene.h \
    mypushbutton.h \
    selectscene.h \
    playscene.h \
    coinbutton.h \
    dataconfig.h

FORMS    += mymainwindow.ui

RESOURCES += \
    res.qrc
