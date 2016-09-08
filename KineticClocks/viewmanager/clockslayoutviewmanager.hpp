#pragma once
#include "model\clocksymbols.hpp"
#include "model\symbol.hpp"
#include "model/clocktime.hpp"
#include "view\clockslayoutview.hpp"
#include "view\clockgraphicsitem.hpp"
#include <QObject>
#include <QRectF>
#include <array>


class QTimer;

namespace twentysixapps
{
class ClockTime;
class ClockGraphicsItem;
class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    const int ClockLayoutWideEdge= 400;
    const int ClockLayoutNarrowEdge = 250;
    static const int GridRanks = 3 ;
    const int SymbolClockRanks= 1;
    ClocksLayoutViewManager(QScreen* primaryScreen);

    void showTime() ;


signals:


private slots:
    void rotateClocksTimerChanged();
    void updateDisplayTimerChanged();
    void onOrientationChanged(Qt::ScreenOrientation newOrientation);

private:
    QScreen& mPrimaryScreen;
    ClocksLayoutView mClocksLayoutView;
    QTimer& mRotateClocksTimer;
    QTimer& mUpdateDisplayTimer;
    ClockSymbols mClockSymbols;

    typedef std::array<ClockGraphicsItem*, GridRanks  *   ClockTime::SymbolsCount  * Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock> ClockItems;
    typedef ClockItems::const_iterator  ClockItemsCIterator;

    ClockItems mClockGraphicsItems;
    QString mCurrentDisplayTime;

    void createSceneItems();
    void InvalidateAllClocks();
    void InvalidateClocks(ClockItemsCIterator start, ClockItemsCIterator end,  int angleDelta=1 , int indexIncrement=1);
    QRectF GetScreenRect() const;
    QRectF GetScreenRect(Qt::ScreenOrientation orientation) const;


    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;



};
}
