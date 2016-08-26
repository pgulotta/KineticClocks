#include "clockslayoutview.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QScreen>
#include <QGraphicsScene>


using namespace twentysixapps;

 auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    auto rec = app.primaryScreen()->availableVirtualSize();
    auto width = rec.width();
    auto height = rec.height();

    QGraphicsScene scene(0, 0, 1000,1000 );
    ClocksLayoutView window(&scene);
    window.resize(width, height);
    window.show();

    return app.exec();
}
