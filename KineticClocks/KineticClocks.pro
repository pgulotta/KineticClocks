TARGET = KineticClocks
TEMPLATE = app

QT += widgets
QT += concurrent

CONFIG += qt warn_on  c++14

MOBILITY =

SOURCES += \
    view/main.cpp \
    view/clockgraphicsitem.cpp \
    view/clockslayoutview.cpp \
    model/clocksymbols.cpp \
    model/clocktime.cpp \
    utils/utils.cpp \
    utils/colorgenerator.cpp \
    viewmanager/clockslayoutviewmanager.cpp \
    utils/platform.cpp



HEADERS += \
    model/clock.hpp \
    model/clocksymbols.hpp \
    model/symbol.hpp \
    model/grid.hpp \
    model/clocktime.hpp \
    model/display.hpp \
    view/clockgraphicsitem.hpp \
    view/clockslayoutview.hpp \
    viewmanager/clockslayoutviewmanager.hpp \
    utils/utils.hpp \
    utils/colorgenerator.hpp \
    utils/platform.hpp



# Default rules for deployment.
include(deployment.pri)



gcc|clang {
    QMAKE_CXXFLAGS += -std=c++1y
}

