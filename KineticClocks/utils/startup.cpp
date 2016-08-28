#include "startup.hpp"
#include "utils/consts.hpp"
#include "view/clockslayoutview.hpp"
#include <QGraphicsScene>


namespace twentysixapps
{
Startup::Startup(ClocksLayoutView& clocksLayoutView):
    mClocksLayoutView(clocksLayoutView)
{
}



void Startup::show() const
{
    mClocksLayoutView.Initialize();
    mClocksLayoutView.show();
}

Startup::~Startup()
{

}

}
