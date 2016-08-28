#include "clockslayoutview.hpp"
#include "viewmanager/clockslayoutviewmanager.hpp"
#include <QApplication>
#include <QScreen>



using namespace twentysixapps;

auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    QObject::connect(&app, &QApplication::lastWindowClosed,&app, &QApplication::quit);
    auto rec = app.primaryScreen()->availableVirtualSize();
    auto width = rec.width();
    auto height = rec.height();
    ClocksLayoutViewManager manager(width, height);
    manager.showTime();
    return app.exec();
}
