TARGET = KineticClocks
TEMPLATE = app

QT += widgets

CONFIG += qt warn_on  c++14

MOBILITY =

SOURCES += \
    view/main.cpp \
    model/clocksymbols.cpp \
    model/clocktime.cpp \
    utils/utils.cpp \
    view/clockgraphicsitem.cpp \
    view/clockslayoutview.cpp \
    viewmanager/clockslayoutviewmanager.cpp


HEADERS += \
    model/clock.hpp \
    model/clocksymbols.hpp \
    model/symbol.hpp \
    model/grid.hpp \
    model/clocktime.hpp \
    view/clockgraphicsitem.hpp \
    view/clockslayoutview.hpp \
    viewmanager/clockslayoutviewmanager.hpp \
    utils/utils.hpp \
    model/display.hpp

# Default rules for deployment.
include(deployment.pri)



gcc|clang {
    QMAKE_CXXFLAGS += -std=c++1y
}

