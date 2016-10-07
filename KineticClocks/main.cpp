#include "model/display.hpp"
#include "viewmanager/clocksviewmanager.hpp"
#include <QApplication>
#include <QScreen>



using namespace twentysixapps;

auto main(int argc, char *argv[])->int
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QObject::connect(&app, &QApplication::lastWindowClosed,&app, &QApplication::quit);

    TimeDisplayAdapter displayAdapter;
    ClocksViewManager manager(&app,  &displayAdapter);

    return app.exec();
}
