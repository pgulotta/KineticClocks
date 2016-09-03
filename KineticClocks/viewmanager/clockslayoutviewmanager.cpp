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
    QObject(nullptr),mPrimaryScreen(*primaryScreen), mClocksLayoutView(nullptr),mUpdateDisplayTimer (*new QTimer(this))
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();

    mClocksLayoutView.setScene(new QGraphicsScene(GetScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(ClockGraphicsItem::BackColor);
    //mClocksLayoutView.resize(virtualSize );
    mClocksLayoutView.resize(QSize(800,600) );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
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

int ClocksLayoutViewManager::createSceneItems(int itemIndex, qreal xposStart)
{
    qreal xpos = xposStart;
    for(int row = 0; row < Symbol::RowCount; row+= 1)
        {
            xpos = xposStart;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[itemIndex] =
                        new ClockGraphicsItem( QPointF(xpos,ClockGraphicsItem::YPosDelta + row*ClockGraphicsItem::ClockDiameter));
                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                    mClockGraphicsItems[itemIndex] =
                        new ClockGraphicsItem( QPointF(xpos,ClockGraphicsItem::YPosDelta  + row*ClockGraphicsItem::ClockDiameter));
                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                    xpos+= ClockGraphicsItem::ClockDiameter;
                }
        }
    return itemIndex;
}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=0;
    qreal xpos = ClockGraphicsItem::XPosDelta;
    for(int colIndex= 0; colIndex < Symbol::ColCount; ++colIndex )
        {
            itemIndex =createSceneItems(itemIndex, xpos);
            xpos+= ClockGraphicsItem::ClockDiameter * Symbol::ColCount;
        }
}

int ClocksLayoutViewManager::updateDisplayTime(int itemIndex,int symbolNameIndex, const ClockTime& clockTime)
{
    for(int row = 0; row < Symbol::RowCount; row++)
        {
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(clockTime.symbols()[symbolNameIndex],row);
            for_each(std::get<0>(tuple), std::get<1>(tuple),
                     [&itemIndex,&items = mClockGraphicsItems](const Clock &clock)
            {
                items[itemIndex++]->setAngle(clock.Angle1);
                items[itemIndex++]->setAngle(clock.Angle2);
            });
        }
    return itemIndex;
}

void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    ClockTime clockTime;
    if ( mCurrentDisplayTime != clockTime.toString())
        {
            mCurrentDisplayTime = clockTime.toString();
            int itemIndex=0;
            for(int colIndex = 0; colIndex < Symbol::ColCount; ++colIndex )
                {
                    itemIndex = updateDisplayTime(itemIndex, colIndex, clockTime);
                }
            mClocksLayoutView.scene()->update();
        }

    auto interval = 1000 * (60-QTime::currentTime().second());
    if ( interval != mUpdateDisplayTimer.interval())
        mUpdateDisplayTimer.start(interval);

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
