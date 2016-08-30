QT       += testlib

QT       -= gui

TARGET = testkineticclocks
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app




SOURCES += \
    testkineticclocks.cpp \
    ..\KineticClocks\model\clocksymbols.cpp



DEFINES += SRCDIR=\\\"$$PWD/\\\"
