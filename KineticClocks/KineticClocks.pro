QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KineticClocks
TEMPLATE = app

CONFIG += c++14 mobility

MOBILITY =

SOURCES += \
    view/main.cpp \
    view/mainwindow.cpp \
    model/clocksymbols.cpp

HEADERS += \
    view/mainwindow.hpp \
    model/clock.hpp \
    model/layout.hpp \
    model/clocksymbols.hpp \
    model/symbol.hpp \
    model/grid.hpp

FORMS    += view/mainwindow.ui


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)



gcc|clang {
    QMAKE_CXXFLAGS += -std=c++1y
}

