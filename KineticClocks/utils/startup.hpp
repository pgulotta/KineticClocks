#pragma once
#include "viewmanager/clockslayoutviewmanager.hpp"
#include <QObject>

namespace twentysixapps
{
class ClockSymbols;
class ClocksLayoutViewManager;
class ClocksLayoutView;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(ClocksLayoutView& clocksLayoutView);
    ~Startup();
    void show() const;


private:
    ClocksLayoutViewManager mClocksLayoutViewManager;


    explicit Startup(const Startup& rhs) = delete;
    Startup& operator= (const Startup& rhs) = delete;
};
}
