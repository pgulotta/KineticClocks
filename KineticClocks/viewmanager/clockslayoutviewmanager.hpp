#pragma once
#include "model\clocksymbols.hpp"
#include "model\symbol.hpp"
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
    ClockSymbols mClockSymbols;
    QTimer& mRotateClocksTimer;
    QTimer& mUpdateDisplayTimer;

    const int mStartItemIndexFillerTop = 0;
    const int mStartItemIndexSymbols = Symbol::ItemCount*10;
    const int mStartItemIndexFillerBottom= Symbol::ItemCount*10 *2;
    const qreal mYTopFillerStartPos  = 0.0f;
    const qreal mYSymbolsStartPos  = ClockGraphicsItem::ClockDiameter * Symbol::RowCount;
    const qreal mYBottomFillerStartPos  = ClockGraphicsItem::ClockDiameter * Symbol::RowCount*2;

    typedef std::array<ClockGraphicsItem*, Symbol::ItemCount*10*3>  ClockItems;
    typedef ClockItems::const_iterator  CIterator;

    ClockItems mClockGraphicsItems;
    QString mCurrentDisplayTime;

    void createSceneFiller();
    void createSceneSymbols();
    void InvalidateAllClocks();
    void InvalidateClocks(CIterator start, CIterator end,  int angleDelta=1 , int indexIncrement=1);
    QRectF GetScreenRect() const;
    QRectF GetScreenRect(Qt::ScreenOrientation orientation) const;


    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;



};
}
