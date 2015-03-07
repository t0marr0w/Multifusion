######################################################################
#	Star tool MultiFusion build script. Kukushkin Alexey, 2009
######################################################################

TEMPLATE = lib
TARGET = Star
CONFIG += plugin
DEPENDPATH += . \
    ./../../../pluginTool
INCLUDEPATH += . \
    ./../../../pluginTool \
    ./../../../interfaces
QT += xml \
    xmlpatterns
LIBS += -L./../../../pluginTool
DESTDIR = ./../../../bin/plugins/Star

HEADERS += Star.h \
    Plugin.h \
    FigureToolInterface.h \
    InterfacePlugin.h \
	SignalHolder.h
SOURCES += Star.cpp
RESOURCES += Star.qrc
