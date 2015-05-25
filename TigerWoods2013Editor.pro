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

win32:LIBS += -LC:\Users\Adam\Desktop\VelocityClone\XboxInternals-Win\debug\XboxInternals.dll
win32:INCLUDEPATH += C:\Users\Adam\Desktop\VelocityClone\XboxInternals

SOURCES += main.cpp\
        MainWindow.cpp \
    TigerWoodsUserFile.cpp

HEADERS  += MainWindow.h \
    TigerWoodsUserFile.h

FORMS    += MainWindow.ui
