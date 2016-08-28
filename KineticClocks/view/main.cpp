#include "clockslayoutview.hpp"
#include "utils/consts.hpp"
#include "utils/startup.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QScreen>
#include <QGraphicsScene>


using namespace twentysixapps;

auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    QObject::connect(&app, &QApplication::lastWindowClosed,&app, &QApplication::quit);
    auto rec = app.primaryScreen()->availableVirtualSize();
    auto width = rec.width();
    auto height = rec.height();

    QGraphicsScene scene(0, 0, width /ClockDiameter,height/ClockDiameter);
    scene.setBackgroundBrush(BackColor);
    ClocksLayoutView view(&scene);
    view.resize(width ,height);

        Startup startup(view);
        startup.show();

    return app.exec();
}

