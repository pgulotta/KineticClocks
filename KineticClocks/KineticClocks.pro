QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KineticClocks
TEMPLATE = app

CONFIG += c++14 mobility

MOBILITY =

SOURCES += \
    view/main.cpp \
    model/clocksymbols.cpp \
    utils/utils.cpp \
    view/clockgraphicsitem.cpp \
    view/clockslayoutview.cpp \
    viewmanager/clockslayoutviewmanager.cpp

HEADERS += \
    model/clock.hpp \
    model/layout.hpp \
    model/clocksymbols.hpp \
    model/symbol.hpp \
    model/grid.hpp \
    view/clockgraphicsitem.hpp \
    view/clockslayoutview.hpp \
    viewmanager/clockslayoutviewmanager.hpp \
    utils/consts.hpp \
    utils/utils.hpp



# Default rules for deployment.
include(deployment.pri)



gcc|clang {
    QMAKE_CXXFLAGS += -std=c++1y
}

