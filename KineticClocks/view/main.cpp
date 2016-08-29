#include "clockslayoutview.hpp"
#include "viewmanager/clockslayoutviewmanager.hpp"
#include <QApplication>
#include <QScreen>



using namespace twentysixapps;

auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    QObject::connect(&app, &QApplication::lastWindowClosed,&app, &QApplication::quit);
    auto primaryScreen = app.primaryScreen();
    auto virtualSize = primaryScreen->availableVirtualSize();
    ClocksLayoutViewManager manager(virtualSize.width(),
                                    virtualSize.height(),
                                    primaryScreen->isPortrait(primaryScreen->orientation()));
    manager.showTime();
    return app.exec();
}
