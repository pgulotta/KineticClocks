#pragma once
#include "model\clocksymbols.hpp"
#include <QObject>

namespace twentysixapps
{
class ClocksLayoutView;
class ClockSymbols;

class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    ClocksLayoutViewManager(ClocksLayoutView& clocksLayoutView);
    void showTime() const;
    void initialize() ;


private:
    ClocksLayoutView& mClocksLayoutView;
    ClockSymbols mClockSymbols;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
};
}
