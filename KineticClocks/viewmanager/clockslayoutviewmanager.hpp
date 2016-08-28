#pragma once
#include "model\clocksymbols.hpp"
#include "view\clockslayoutview.hpp"
#include <QObject>

namespace twentysixapps
{
class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    ClocksLayoutViewManager(int screenWidth, int screenHeight);
    void showTime() ;



private:
    ClocksLayoutView mClocksLayoutView;
    ClockSymbols mClockSymbols;

    void initialize() ;


    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
};
}
