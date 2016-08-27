#include "clockslayoutviewmanager.hpp"
#include "model\clocksymbols.hpp"
#include "view\clockslayoutview.hpp"


namespace twentysixapps
{
ClocksLayoutViewManager::ClocksLayoutViewManager(QObject *parent,
        ClocksLayoutView& clocksLayoutView,
        ClockSymbols& clockSymbols) :
    QObject(parent),
    mClocksLayoutView(clocksLayoutView),
    mClockSymbols(clockSymbols)
{
}
}
