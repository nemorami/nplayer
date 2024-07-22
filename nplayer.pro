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
    playlistmodel.cpp \
    qmediaplaylist.cpp \
    qmediaplaylist_p.cpp

HEADERS  += mainwindow.h \
    playercontrols.h \
    nmediaplayer.h \
    blocktimecontrols.h \
    playlistview.h \
    playlistmodel.h \
    qmediaplaylist.h \
    qmediaplaylist_p.h

FORMS    += mainwindow.ui \
    playercontrols.ui \
    blocktimecontrols.ui \
    playlistview.ui

CONFIG   += c++20


DISTFILES += \
    ChangeLog.txt
