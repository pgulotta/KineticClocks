#pragma once
#include <QObject>

namespace twentysixapps
{
class ClocksLayoutView;
class ClockSymbols;

class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    explicit ClocksLayoutViewManager(QObject* parent,
                                     ClocksLayoutView& clocksLayoutView,
                                     ClockSymbols& clockSymbols);

private:
    ClocksLayoutView& mClocksLayoutView;
    ClockSymbols& mClockSymbols;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
};
}

