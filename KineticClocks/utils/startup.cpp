#include "startup.hpp"
#include "utils/consts.hpp"
#include "view/clockslayoutview.hpp"
#include <QGraphicsScene>


namespace twentysixapps
{
Startup::Startup(ClocksLayoutView& clocksLayoutView):
    mClocksLayoutViewManager(clocksLayoutView)
{
}



void Startup::show() const
{
    mClocksLayoutViewManager.ShowView();
}

Startup::~Startup()
{

}

}
