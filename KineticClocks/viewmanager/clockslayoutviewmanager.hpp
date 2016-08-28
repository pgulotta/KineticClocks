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
    void ShowView() const;
private:
    ClocksLayoutView& mClocksLayoutView;
    ClockSymbols mClockSymbols;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
};
}
