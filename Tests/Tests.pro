QT       += testlib

QT       -= gui

TARGET = testkineticclocks
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


HEADERS += \
    ../KineticClocks/model/clocktime.hpp \
    ../KineticClocks/model/display.hpp

SOURCES += \
    testkineticclocks.cpp \
    ../KineticClocks/model/clocktime.cpp \
    ../KineticClocks/model/clocksymbols.cpp


DEFINES += SRCDIR=\\\"$$PWD/\\\"


