QT += qml quick

CONFIG += c++14

SOURCES += \
    ui/main.cpp \
    engine/clocksymbols.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    engine/clock.hpp \
    engine/layout.hpp \
    engine/clocksymbols.hpp \
    engine/symbol.hpp \
    engine/grid.hpp

gcc|clang {
    QMAKE_CXXFLAGS += -std=c++1y
}

