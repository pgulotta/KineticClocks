#include "clockslayoutviewmanager.hpp"
#include "utils/consts.hpp"
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

void ClocksLayoutViewManager::InitializeUpdateDisplayTimer()
{
    connect(&mUpdateDisplayTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::updateDisplayTimerChanged);
    mUpdateDisplayTimer.setInterval(60000);
    mUpdateDisplayTimer.start();
}

ClocksLayoutViewManager::ClocksLayoutViewManager(QScreen* primaryScreen):
    QObject(nullptr),mPrimaryScreen(*primaryScreen), mClocksLayoutView(nullptr),mUpdateDisplayTimer (*new QTimer(this))
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();

    mClocksLayoutView.setScene(new QGraphicsScene(GetScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(ClockGraphicsItem::BackColor);
    mClocksLayoutView.resize(virtualSize );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    InitializeUpdateDisplayTimer();
}

void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    updateDisplayTime();
}

void ClocksLayoutViewManager::showTime()
{
    updateDisplayTime();
    mClocksLayoutView.show();
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation )
{
    mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}

int ClocksLayoutViewManager::createSceneItems(int itemIndex, qreal xposStart)
{
    qreal xpos = xposStart;
    for(int row = ClockGraphicsItem::YStartPosisiton; row < Symbol::RowCount; row+= 1)
        {
            xpos = xposStart;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[itemIndex] = new ClockGraphicsItem( QPointF(xpos,row*ClockGraphicsItem::ClockDiameter),0);
                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                    mClockGraphicsItems[itemIndex] = new ClockGraphicsItem( QPointF(xpos,row*ClockGraphicsItem::ClockDiameter),0);
                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                    xpos+= ClockGraphicsItem::ClockDiameter;
                }
        }
    return itemIndex;
}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=0;
    qreal xpos = ClockGraphicsItem::XStartPosisiton;
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
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);
            for( auto it = first; it != last; ++it)
           {
                Clock clock = *it;
                mClockGraphicsItems[itemIndex++]->setAngle(clock.Angle1);
                mClockGraphicsItems[itemIndex++]->setAngle(clock.Angle2);
            }
//            std::for_each(first, last, [&itemIndex,this](const Clock &clock)
//            {
//                mClockGraphicsItems[itemIndex++]->setAngle(clock.Angle1);
//                mClockGraphicsItems[itemIndex++]->setAngle(clock.Angle2);
//            });
        }
    return itemIndex;
}

void ClocksLayoutViewManager::updateDisplayTime()
{
    ClockTime clockTime;
    int itemIndex=0;
    for(int colIndex = 0; colIndex < Symbol::ColCount; ++colIndex )
        {
            itemIndex = updateDisplayTime(itemIndex, colIndex, clockTime);
        }
    mClocksLayoutView.scene()->update();
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
