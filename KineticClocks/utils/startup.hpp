#pragma once
#include "viewmanager/clockslayoutviewmanager.hpp"
#include "model/clocksymbols.hpp"
#include <QObject>

namespace twentysixapps
{
class ClockSymbols;
class ClocksLayoutViewManager;


class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(ClocksLayoutView& clocksLayoutView);
    ~Startup();
    void showTime() const;


private:
    ClocksLayoutViewManager mClocksLayoutViewManager;
    ClockSymbols mClockSymbols;

    explicit Startup(const Startup& rhs) = delete;
    Startup& operator= (const Startup& rhs) = delete;
};
}
