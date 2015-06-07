#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T01:20:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TigerWoods2013Editor
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        MainWindow.cpp \
    IO/FileIO.cpp \
    IO/BaseIO.cpp \
    TigerWoods13/UserFile.cpp \
    TigerWoods13/TigerLegacyChallenge.cpp \
    TigerWoods13/ProgressFile.cpp

HEADERS  += MainWindow.h \
    TigerWoodsUserFile.h \
    winnames.h \
    IO/FileIO.h \
    IO/BaseIO.h \
    TigerWoodsProgressFile.h \
    TigerWoodsTigerLegacyChallenge.h \
    TigerWoods13/UserFile.h \
    TigerWoods13/TigerLegacyChallenge.h \
    TigerWoods13/ProgressFile.h

FORMS    += MainWindow.ui

RESOURCES += \
    images.qrc
