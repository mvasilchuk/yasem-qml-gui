#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T11:43:40
#
#-------------------------------------------------

VERSION = 0.1.0

QT       += gui qml quick declarative

TARGET = yasem-qml-gui
TEMPLATE = lib

CONFIG += c++11

INCLUDEPATH += ../../yasem-core

DEFINES += YASEMQMLGUI_LIBRARY

SOURCES += qmlgui.cpp

HEADERS += qmlgui.h\
        yasem-qml-gui_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    metadata.json \
    mainwindow.qml

include(../../common.pri)
DESTDIR = $$DEFAULT_PLUGIN_DIR

RESOURCES += \
    resources.qrc
