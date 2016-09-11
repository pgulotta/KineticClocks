#include "model/display.hpp"
#include "viewmanager/clockslayoutviewmanager.hpp"
#include <QApplication>
#include <QScreen>



using namespace twentysixapps;

auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    QObject::connect(&app, &QApplication::lastWindowClosed,&app, &QApplication::quit);

    TimeDisplayAdapter displayAdapter ;
    ClocksLayoutViewManager manager(&app,  app.primaryScreen(), &displayAdapter);

    return app.exec();
}
