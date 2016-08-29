#pragma once
#include "model\clocksymbols.hpp"
#include "view\clockslayoutview.hpp"
#include <QObject>
#include <QRectF>
namespace twentysixapps
{
class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    ClocksLayoutViewManager(QScreen* primaryScreen);
    void showTime() ;

signals:
    void rotationChanged(qreal rotation);

private slots:
    void orientationChanged(Qt::ScreenOrientation newOrientation);

private:
    QScreen& mPrimaryScreen;
    ClocksLayoutView mClocksLayoutView;
    ClockSymbols mClockSymbols;

    void initialize() ;
    QRectF GetScreenRect() const;
    QRectF GetScreenRect(Qt::ScreenOrientation orientation) const;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
};
}
