#include "clockslayoutviewmanager.hpp"
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
    //  mClocksLayoutView.resize(virtualSize.width()/2, virtualSize.height()/2 );
    createSceneItems();
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
//void ClocksLayoutViewManager::createSceneItems()
//{
//    int itemIndex=mStartItemIndexFillerTop;
//    qreal xposStart = 0.0f;
//    for(int symbolColIndex= 0; symbolColIndex < Symbol::ColCount; ++symbolColIndex )
//        {
//            qreal xpos = xposStart;
//            for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowCount; symbolRowIndex+= 1)
//                {
//                    xpos = xposStart;
//                    for(int symbolIndex = 0; symbolIndex < Symbol::ColCount; symbolIndex++)
//                        {
//                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop] =
//                                new ClockGraphicsItem( QPointF(xpos, mYTopFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
//                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop]);
//                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom] =
//                                new ClockGraphicsItem( QPointF(xpos, mYBottomFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
//                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom]);
//                            itemIndex++;

//                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop] =
//                                new ClockGraphicsItem( QPointF(xpos, mYTopFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter),Clock::Angle2Default);
//                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop]);
//                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom] =
//                                new ClockGraphicsItem( QPointF(xpos, mYBottomFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter),Clock::Angle2Default);
//                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom]);
//                            itemIndex++;

//                            xpos+= ClockGraphicsItem::ClockDiameter;
//                        }
//                }
//            xposStart+= ClockGraphicsItem::ClockDiameter * Symbol::ColCount;
//        }
//}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=mStartItemIndexFillerTop;
    qreal xposStart = 0.0f;

    qreal xposClock =0.0f;
    qreal yposClock = 0.0f;
    for(int symbolColIndex= 0; symbolColIndex < Symbol::ColsPerSymbol; ++symbolColIndex )
        {
            xposClock =0.0f;
            for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowsPerSymbol; symbolRowIndex+= 1)
                {
                    xposClock = xposStart;
                    for(int symbolIndex = 0; symbolIndex < Symbol::ColsPerSymbol; symbolIndex++)
                        {
                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop] =
                                new ClockGraphicsItem( QPointF(xposClock, mYTopFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop]);
                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom] =
                                new ClockGraphicsItem( QPointF(xposClock, mYBottomFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom]);
                            itemIndex++;

                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop] =
                                new ClockGraphicsItem( QPointF(xposClock, mYTopFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter),Clock::Angle2Default);
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerTop]);
                            mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom] =
                                new ClockGraphicsItem( QPointF(xposClock, mYBottomFillerStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter),Clock::Angle2Default);
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex+mStartItemIndexFillerBottom]);
                            itemIndex++;

                            xposClock+= ClockGraphicsItem::ClockDiameter;
                        }
                }
            xposStart+= ClockGraphicsItem::ClockDiameter * Symbol::ColsPerSymbol;
        }
}

void ClocksLayoutViewManager::createSceneSymbols()
{
    int itemIndex=mStartItemIndexSymbols;
    qreal xposStart = 0.0f;
    for(int symbolColIndex= 0; symbolColIndex < Symbol::ColsPerSymbol; ++symbolColIndex )
        {
            qreal xpos = xposStart;
            for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowsPerSymbol; symbolRowIndex+= 1)
                {
                    xpos = xposStart;
                    for(int symbolIndex = 0; symbolIndex < Symbol::ColsPerSymbol; symbolIndex++)
                        {
                            mClockGraphicsItems[itemIndex] =
                                new ClockGraphicsItem( QPointF(xpos,mYSymbolsStartPos + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                            mClockGraphicsItems[itemIndex] =
                                new ClockGraphicsItem( QPointF(xpos,mYSymbolsStartPos  + symbolRowIndex*ClockGraphicsItem::ClockDiameter));
                            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                            xpos+= ClockGraphicsItem::ClockDiameter;
                        }
                }
            xposStart+= ClockGraphicsItem::ClockDiameter * Symbol::ColsPerSymbol;
        }
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
        {
            mClocksLayoutView.scene()->update();
        }
}


void ClocksLayoutViewManager::InvalidateAllClocks()
{
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(),1,1);
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(),3,3);
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(), -2,5);
    InvalidateClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end() ,-1, 9);
}

void ClocksLayoutViewManager::InvalidateClocks(ClocksLayoutViewManager::ClockItemsCIterator start, ClocksLayoutViewManager::ClockItemsCIterator end, int angleDelta  , int indexIncrement)
{
    auto cit =start ;
    while ( cit <  end)
        {
            auto* item = *cit;
            item->setRotationAngle((item->rotationAngle()+angleDelta)%360);
            cit+= indexIncrement;
        }
}

void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    mRotateClocksTimer.stop();
    ClockTime clockTime;
    if ( mCurrentDisplayTime != clockTime.toString())
        {
            mCurrentDisplayTime = clockTime.toString();
            int itemIndex=mStartItemIndexSymbols;
            for(int symbolColIndex = 0; symbolColIndex < Symbol::ColsPerSymbol; ++symbolColIndex )
                {
                    InvalidateAllClocks( );
                    for(int symbolRowIndex = 0; symbolRowIndex < Symbol::RowsPerSymbol; symbolRowIndex++)
                        {

                            ClockSymbols cs;
                            ClockSymbols::Citerators  pair =cs.GetRow(clockTime.symbols()[symbolColIndex],symbolRowIndex);
                            for( ClockSymbols::SymbolClocksCIterator  it = std::get<0>(pair) ; it <  std::get<1>(pair) ; ++it)
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
