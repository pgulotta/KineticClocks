#include "clockslayoutviewmanager.hpp"
#include "view\clockslayoutview.hpp"


namespace twentysixapps
{
ClocksLayoutViewManager::ClocksLayoutViewManager(ClocksLayoutView& clocksLayoutView) :
    QObject(nullptr),
    mClocksLayoutView(clocksLayoutView)
{
}

void ClocksLayoutViewManager::ShowView()const
{
    mClocksLayoutView.show();
}
}
