#pragma once
#include "model\clocksymbols.hpp"
#include "model\symbol.hpp"
#include "view\clockslayoutview.hpp"

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

    std::array<ClockGraphicsItem*,Symbol::ItemCount*10*2> mClockGraphicsItems;
    QString mCurrentDisplayTime;

    void createSceneFiller();
    void createSceneSymbols();
    void InvalidateAllClocks();
    QRectF GetScreenRect() const;
    QRectF GetScreenRect(Qt::ScreenOrientation orientation) const;


    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;



};
}
