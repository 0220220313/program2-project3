#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T19:17:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    boss_ice.cpp \
    player_1.cpp \
    boss.cpp \
    life.cpp \
    end.cpp \
    damage.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    boss.h \
    boss_ice.h \
    boss_ice.h \
    player.h \
    player_1.h \
    boss.h \
    life.h \
    end.h \
    damage.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
