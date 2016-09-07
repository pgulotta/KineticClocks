#include "clockslayoutviewmanager.hpp"
#include "view\clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\clocktime.hpp"
#include "utils/randomgenerator.hpp"
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
    createSceneFiller();
    createSceneSymbols();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    connect(&mRotateClocksTimer, &QTimer::timeout, this, &ClocksLayoutViewManager::rotateClocksTimerChanged);
    connect(&mUpdateDisplayTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::updateDisplayTimerChanged);
}

void ClocksLayoutViewManager::showTime()
{
    updateDisplayTimerChanged();
    mClocksLayoutView.show();
    mRotateClocksTimer.start(50);
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation )
{
    mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}
void ClocksLayoutViewManager::createSceneFiller()
{
    int itemIndex=mStartItemIndexFillerTop;
    qreal xposStart = 0.0f;
    for(int symbolColIndex= 0; symbolColIndex < Symbol::ColCount; ++symbolColIndex )
        {
            qreal xpos = xposStart;
            for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowCount; symbolRowIndex+= 1)
                {
                    xpos = xposStart;
                    for(int symbolIndex = 0; symbolIndex < Symbol::ColCount; symbolIndex++)
                        {
                            mClockGraphicsItems[itemIndex] =
                                new ClockGraphicsItem( QPointF(xpos, symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                            mClockGraphicsItems[itemIndex] =
                                new ClockGraphicsItem( QPointF(xpos,symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                            xpos+= ClockGraphicsItem::ClockDiameter;
                        }
                }
            xposStart+= ClockGraphicsItem::ClockDiameter * Symbol::ColCount;
        }
}

void ClocksLayoutViewManager::createSceneSymbols()
{
    int itemIndex=mStartItemIndexSymbols;
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
    auto clocksUpdated = 0;

    for(auto* it : mClockGraphicsItems)
        {
            if ( it->rotationAngle() == it->angle())
                clocksUpdated++;
            else
                it->setRotationAngle((it->rotationAngle()+1)%360);
        }
    if( clocksUpdated == mClockGraphicsItems.size())
        mRotateClocksTimer.stop();
    else
        mClocksLayoutView.scene()->update();
}

void ClocksLayoutViewManager::InvalidateAllClocks()
{
    int angleDelta =  2;
    int indexIncrement =   1;
    for (auto itemIndex =mStartItemIndexFillerTop; itemIndex <  mStartItemIndexFillerBottom;  itemIndex +=indexIncrement)
        {
            mClockGraphicsItems[itemIndex]->setRotationAngle((mClockGraphicsItems[itemIndex]->rotationAngle()+angleDelta)%360);
        }

    angleDelta =1;
    indexIncrement =2;
    for (auto itemIndex =mStartItemIndexFillerTop; itemIndex <  mStartItemIndexFillerBottom;  itemIndex += indexIncrement)
        {
            mClockGraphicsItems[itemIndex]->setRotationAngle((mClockGraphicsItems[itemIndex]->rotationAngle()+angleDelta)%360);
        }

    angleDelta =-3;
    indexIncrement =4;
    for (auto itemIndex =mStartItemIndexFillerTop; itemIndex <  mStartItemIndexFillerBottom;  itemIndex += indexIncrement)
        {
            mClockGraphicsItems[itemIndex]->setRotationAngle((mClockGraphicsItems[itemIndex]->rotationAngle()+angleDelta)%360);
        }

    angleDelta = 4;
    indexIncrement =5;
    for (auto itemIndex =mStartItemIndexFillerTop; itemIndex <  mStartItemIndexFillerBottom;  itemIndex += indexIncrement)
        {
            mClockGraphicsItems[itemIndex]->setRotationAngle((mClockGraphicsItems[itemIndex]->rotationAngle()+angleDelta)%360);
        }
}


void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    mRotateClocksTimer.stop();
    ClockTime clockTime;
    if ( mCurrentDisplayTime != clockTime.toString())
        {
            mCurrentDisplayTime = clockTime.toString();
            InvalidateAllClocks();
            int itemIndex=mStartItemIndexSymbols;
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
                           InvalidateAllClocks( );
                }
        }

    auto interval = 1000 * (60-QTime::currentTime().second());
    if ( interval != mUpdateDisplayTimer.interval())
        mUpdateDisplayTimer.start(interval);
    mRotateClocksTimer.start();
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
