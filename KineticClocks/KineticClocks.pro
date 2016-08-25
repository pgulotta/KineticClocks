QT += qml quick

CONFIG += c++14

SOURCES += \
    view/main.cpp \
    model/clocksymbols.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    model/clock.hpp \
    model/layout.hpp \
    model/clocksymbols.hpp \
    model/symbol.hpp \
    model/grid.hpp

gcc|clang {
    QMAKE_CXXFLAGS += -std=c++1y
}

