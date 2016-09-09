#include "clockslayoutviewmanager.hpp"
#include "model\clock.hpp"
#include "model\clocktime.hpp"
#include "model/display.hpp"
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
  //mClocksLayoutView.resize(virtualSize );
    mClocksLayoutView.resize(virtualSize.width(), virtualSize.height() );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    connect(&mRotateClocksTimer, &QTimer::timeout, this, &ClocksLayoutViewManager::rotateClocksTimerChanged);
    connect(&mUpdateDisplayTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::updateDisplayTimerChanged);
}

void ClocksLayoutViewManager::showTime()
{
    updateDisplayTimerChanged();
    mClocksLayoutView.show();
    mRotateClocksTimer.start(5);
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation )
{
    mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=0;
    qreal xposClock =0.0f;
    qreal yposClock = 0.0f;
    for( int rankIndex = 0;  rankIndex< GridRanks; ++rankIndex)
        {
            for(int symbolColIndex= 0; symbolColIndex < ClockTime::SymbolsCount; ++symbolColIndex )
                {
                    for(int rowIndex = 0; rowIndex < Symbol::RowsPerSymbol; rowIndex+= 1)
                        {
                            yposClock = (rankIndex * ClockGraphicsItem::ClockDiameter * Symbol::RowsPerSymbol) + (rowIndex * ClockGraphicsItem::ClockDiameter );
                            xposClock = symbolColIndex* ClockGraphicsItem::ClockDiameter * Symbol::ColsPerSymbol;
                            for(int colIndex = 0; colIndex < Symbol::ColsPerSymbol; colIndex++)
                                {
                                    mClockGraphicsItems[itemIndex] = new ClockGraphicsItem( QPointF(xposClock, yposClock),Clock::Angle1Default);
                                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                                    mClockGraphicsItems[itemIndex] =new ClockGraphicsItem( QPointF(xposClock, yposClock),Clock::Angle2Default);
                                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                                    xposClock += ClockGraphicsItem::ClockDiameter;
                                }
                            yposClock+=  ClockGraphicsItem::ClockDiameter;
                        }
                }
        }
}

void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    mRotateClocksTimer.stop();
    Display<ClockTime, ClockTime::SymbolsCount> clockTime{ClockTime{}} ;
    if ( mCurrentDisplayTime != clockTime.toString())
        {
            InvalidateAllClocks( );
            mCurrentDisplayTime = clockTime.toString();
            int itemIndex= Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock * ClockTime::SymbolsCount  * SymbolClockRanks;
            for(int colIndex = 0; colIndex < Symbol::ColsPerSymbol; ++colIndex )
                {
                    for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowsPerSymbol; symbolRowIndex++)
                        {
                            ClockSymbols cs;
                            ClockSymbols::Citerators  pair =cs.GetRow(clockTime.symbols()[colIndex],symbolRowIndex);
                            for( ClockSymbols::CIterator  it = std::get<0>(pair) ; it <  std::get<1>(pair) ; ++it)
                                {
                                    Clock clock = *it;
                                    mClockGraphicsItems[itemIndex++]->setAngle(clock.Angle1);
                                    mClockGraphicsItems[itemIndex++]->setAngle(clock.Angle2);
                                }
                        }
                }
        }

    auto interval = 1000 * (60-QTime::currentTime().second());
    if ( interval != mUpdateDisplayTimer.interval())
        mUpdateDisplayTimer.start(interval);
    mRotateClocksTimer.start();
}
void ClocksLayoutViewManager::rotateClocksTimerChanged()
{
    size_t clocksUpdated = 0;
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
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(),1,1);
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(),2,9);
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(), -1,3);
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(), -1,5);
}

void ClocksLayoutViewManager::InvalidateClocks(ClocksLayoutViewManager::ClockItemsCIterator start, ClocksLayoutViewManager::ClockItemsCIterator end, int angleDelta  , int indexIncrement)
{
    for( auto cit =start ; cit <  end; cit+= indexIncrement)
        {
            auto* item = *cit;
            item->setRotationAngle((item->rotationAngle()+angleDelta)%360);
        }
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
    return QRectF{0, 0, width, height };
}
}
