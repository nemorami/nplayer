#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T10:03:32
#
#-------------------------------------------------

QT       += core gui network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nplayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    playercontrols.cpp \
    nmediaplayer.cpp \
    blocktimecontrols.cpp \
    playlistview.cpp \
    playlistmodel.cpp

HEADERS  += mainwindow.h \
    playercontrols.h \
    nmediaplayer.h \
    blocktimecontrols.h \
    playlistview.h \
    playlistmodel.h

FORMS    += mainwindow.ui \
    playercontrols.ui \
    blocktimecontrols.ui \
    playlistview.ui

CONFIG   += c++17


DISTFILES += \
    ChangeLog.txt
