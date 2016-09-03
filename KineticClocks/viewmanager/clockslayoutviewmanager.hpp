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
    void rotationChanged(qreal rotation);

private slots:
    void updateDisplayTimerChanged();
    void onOrientationChanged(Qt::ScreenOrientation newOrientation);

private:
    QScreen& mPrimaryScreen;
    ClocksLayoutView mClocksLayoutView;
    ClockSymbols mClockSymbols;
    QTimer& mUpdateDisplayTimer;
    std::array<ClockGraphicsItem*,Symbol::ItemCount*10> mClockGraphicsItems;
    QString mCurrentDisplayTime;

    void createSceneItems();
    QRectF GetScreenRect() const;
    QRectF GetScreenRect(Qt::ScreenOrientation orientation) const;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;


};
}
