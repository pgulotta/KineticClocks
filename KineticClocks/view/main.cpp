#include "clockslayoutview.hpp"
#include "viewmanager/clockslayoutviewmanager.hpp"
#include <QApplication>
#include <QScreen>



using namespace twentysixapps;

auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    QObject::connect(&app, &QApplication::lastWindowClosed,&app, &QApplication::quit);
    ClocksLayoutViewManager manager(&app,  app.primaryScreen());
    manager.showTime();
    return app.exec();
}
