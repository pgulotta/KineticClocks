#include "clockslayoutviewmanager.hpp"
#include "view\clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\clocktime.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QScreen>
#include <QDebug>
#include <QTimer>

namespace twentysixapps
{

ClocksLayoutViewManager::ClocksLayoutViewManager(QScreen* primaryScreen):
    QObject(nullptr),mPrimaryScreen(*primaryScreen),
    mClocksLayoutView(nullptr),
    mRotateClocksTimer(*new QTimer(this)),
    mUpdateDisplayTimer (*new QTimer(this))
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();

    mClocksLayoutView.setScene(new QGraphicsScene(GetScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(ClockGraphicsItem::BackColor);
    mClocksLayoutView.resize(virtualSize );
    // mClocksLayoutView.resize(QSize(800,600) );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    connect(&mRotateClocksTimer, &QTimer::timeout, this, &ClocksLayoutViewManager::rotateClocksTimerChanged);
    connect(&mUpdateDisplayTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::updateDisplayTimerChanged);
}

void ClocksLayoutViewManager::showTime()
{
    updateDisplayTimerChanged();
    mClocksLayoutView.show();
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation )
{
    mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=0;
    qreal xposStart = ClockGraphicsItem::XPosDelta;
    for(int symbolColIndex= 0; symbolColIndex < Symbol::ColCount; ++symbolColIndex )
        {
            qreal xpos = xposStart;
            for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowCount; symbolRowIndex+= 1)
                {
                    xpos = xposStart;
                    for(int symbolIndex = 0; symbolIndex < Symbol::ColCount; symbolIndex++)
                        {
                            mClockGraphicsItems[itemIndex] =
                                new ClockGraphicsItem( QPointF(xpos,ClockGraphicsItem::YPosDelta + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                            mClockGraphicsItems[itemIndex] =
                                new ClockGraphicsItem( QPointF(xpos,ClockGraphicsItem::YPosDelta  + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                            xpos+= ClockGraphicsItem::ClockDiameter;
                        }
                }
            xposStart+= ClockGraphicsItem::ClockDiameter * Symbol::ColCount;
        }
}
void ClocksLayoutViewManager::rotateClocksTimerChanged()
{
    for(auto* i : mClockGraphicsItems)
        {
            i->setAngle((i->angle()+1)%360);
        }
    mClocksLayoutView.scene()->update();
}

void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    mRotateClocksTimer.stop();
    ClockTime clockTime;
    if ( mCurrentDisplayTime != clockTime.toString())
        {
            mCurrentDisplayTime = clockTime.toString();
            int itemIndex=0;
            for(int symbolColIndex = 0; symbolColIndex < Symbol::ColCount; ++symbolColIndex )
                {
                    for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowCount; symbolRowIndex++)
                        {
                            ClockSymbols cs;
                            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =
                                cs.GetRow(clockTime.symbols()[symbolColIndex],symbolRowIndex);
                            for_each(std::get<0>(tuple), std::get<1>(tuple),
                                     [&itemIndex,&items = mClockGraphicsItems](const Clock &clock)
                            {
                                items[itemIndex++]->setAngle(clock.Angle1);
                                items[itemIndex++]->setAngle(clock.Angle2);
                            });
                        }
                }
            mClocksLayoutView.scene()->update();
        }

    auto interval = 1000 * (60-QTime::currentTime().second());
    if ( interval != mUpdateDisplayTimer.interval())
        mUpdateDisplayTimer.start(interval);

    mRotateClocksTimer.start(100);

}

QRectF ClocksLayoutViewManager::GetScreenRect() const
{
    return GetScreenRect(mPrimaryScreen.primaryOrientation());
}

QRectF ClocksLayoutViewManager::GetScreenRect(Qt::ScreenOrientation orientation) const
{
    bool isPortrait = mPrimaryScreen.isPortrait(orientation);
    qreal width = isPortrait? ClockLayoutNarrowEdge : ClockLayoutWideEdge;
    qreal height = isPortrait? ClockLayoutWideEdge:ClockLayoutNarrowEdge;
    return QRectF{0, 0, width, height};
}
}
