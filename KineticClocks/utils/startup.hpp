#pragma once
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
    ClocksLayoutView& mClocksLayoutView;

    explicit Startup(const Startup& rhs) = delete;
    Startup& operator= (const Startup& rhs) = delete;
};
}
