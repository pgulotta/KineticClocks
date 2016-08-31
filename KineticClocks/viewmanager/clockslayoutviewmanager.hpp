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
class ClockGraphicsItem;
class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    ClocksLayoutViewManager(QScreen* primaryScreen);
    void showTime() ;

signals:
    void rotationChanged(qreal rotation);

private slots:
    void onTimeChanged();
    void onOrientationChanged(Qt::ScreenOrientation newOrientation);

private:
    QScreen& mPrimaryScreen;
    ClocksLayoutView mClocksLayoutView;
    ClockSymbols mClockSymbols;
    QTimer& mTimeTimer;
    std::array<ClockGraphicsItem*,Symbol::ItemCount*10> mClockGraphicsItems;

    void createSceneItems();
    void setDisplayTime() ;
    QRectF GetScreenRect() const;
    QRectF GetScreenRect(Qt::ScreenOrientation orientation) const;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;

};
}
