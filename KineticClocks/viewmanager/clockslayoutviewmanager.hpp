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
    static const int LayoutRank = 3 ;
    const int SymbolRank= 1;
    ClocksLayoutViewManager(QObject*  parent,   QScreen* primaryScreen);
    void showTime() ;


signals:


private slots:
    void rotateClocksTimerChanged();
    void updateDisplayTimerChanged();
    void onOrientationChanged(Qt::ScreenOrientation newOrientation);

private:
    typedef std::array<ClockGraphicsItem*, LayoutRank  *   ClockTime::SymbolsCount  * Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock> ClockItems;
    typedef ClockItems::const_iterator  ClockItemsCIterator;

    const int ClockLayoutWidth= 500;
    const int ClockLayoutHeight = 360;

    QScreen& mPrimaryScreen;
    ClocksLayoutView mClocksLayoutView;
    QTimer& mRotateClocksTimer;
    QTimer& mUpdateDisplayTimer;
    ClockSymbols mClockSymbols;
    ClockItems mClockGraphicsItems;
    QString mDisplayedSymbols;

    void createSceneItems();
    void invalidatelClocks();
    void invalidatelClocks(ClockItemsCIterator start, ClockItemsCIterator end,  int angleDelta=1 , int indexIncrement=1);
    QRectF getScreenRect() const;
    QRectF getScreenRect(Qt::ScreenOrientation orientation) const;


    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;



};
}
