#include "clockslayoutviewmanager.hpp"
#include "model\clock.hpp"
#include "utils/colorgenerator.hpp"
#include "utils/platform.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QScreen>
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QtConcurrent>

namespace twentysixapps
{

int RotationAngleDelta = Platform::rotationAngleDelta();

ClocksLayoutViewManager::ClocksLayoutViewManager(QObject*  parent,   const QScreen* primaryScreen,    DisplayAdapter* displayAdapter) :
    QObject(parent ),
    mPrimaryScreen(*primaryScreen),
    mDisplayAdapter(*displayAdapter),
    mRotateClocksTimer(*new QTimer(this)),
    mUpdateDisplayTimer (*new QTimer(this))
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();
    mClocksLayoutView.setScene(new QGraphicsScene(getScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(mBackColor);
    mClocksLayoutView.resize(virtualSize.width()/4, virtualSize.height()/4 );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &onOrientationChanged);
    connect(&mRotateClocksTimer, &QTimer::timeout, this, &rotateClocksTimerChanged);
    connect(&mUpdateDisplayTimer, &QTimer::timeout,this, &updateDisplayTimerChanged);
    connect(&mUpdateClocksWatcher,  QFutureWatcher<void>::finished,  this, &restartRotateClocksTimer);
    displaySymbols();
}

void ClocksLayoutViewManager::displaySymbols()
{
    updateDisplayTimerChanged();
    mClocksLayoutView.show();
    mRotateClocksTimer.start(50);
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation orientation)
{
    bool isPortraitOrientation = orientation == Qt::ScreenOrientation::PortraitOrientation;
    qDebug() << "Screen orienation changed . Orientation is now portrait = " <<  isPortraitOrientation;
    for( auto item : mClockGraphicsItems)
    {
        item->setOrientation(isPortraitOrientation);
    }
    mClocksLayoutView.scene()->setSceneRect(getScreenRect());
}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=0;
    qreal xposClock =0.0f;
    qreal yposClock = 0.0f;

    bool isPortraitOrientation = mPrimaryScreen.orientation() == Qt::ScreenOrientation::PortraitOrientation;
    for( int gridIndex = 0; gridIndex< GridsDepth; ++gridIndex)
    {
        for(size_t symbolColIndex= 0; symbolColIndex < ClockTime::SymbolsCount; ++symbolColIndex )
        {
            for(size_t rowIndex = 0; rowIndex < Symbol::RowsPerSymbol; rowIndex+= 1)
            {
                yposClock = (gridIndex * ClockGraphicsItem::ClockDiameter * Symbol::RowsPerSymbol) +(rowIndex * ClockGraphicsItem::ClockDiameter );
                xposClock = symbolColIndex* ClockGraphicsItem::ClockDiameter * Symbol::ColsPerSymbol;
                for(size_t colIndex = 0; colIndex < Symbol::ColsPerSymbol; colIndex++)
                {
                    mLineColor = mColorGenerator.nextOffsetColor().lighter(110);
                    mClockGraphicsItems[itemIndex] = new ClockGraphicsItem( isPortraitOrientation, mLineColor,QPointF(xposClock, yposClock),Clock::Angle1Default);
                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                    mClockGraphicsItems[itemIndex] =new ClockGraphicsItem(isPortraitOrientation, mLineColor, QPointF(xposClock, yposClock),Clock::Angle2Default);
                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                    xposClock += ClockGraphicsItem::ClockDiameter;
                }
                yposClock+=  ClockGraphicsItem::ClockDiameter;
            }
        }
    }
}

void ClocksLayoutViewManager::updateClocks()
{
    qDebug() << "updateClocks entered ";
    invalidatelClocks( );
    mDisplayedSymbols = mDisplayAdapter.toString();
    int itemIndex= Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock * ClockTime::SymbolsCount  * DisplayGridIndex;
    for(size_t colIndex = 0; colIndex < Symbol::ColsPerSymbol; ++colIndex )
    {
        for(size_t symbolRowIndex = 0; symbolRowIndex < Symbol::RowsPerSymbol; symbolRowIndex++)
        {
            ClockSymbols cs;
            ClockSymbols::Citerators pair =cs.getRow(mDisplayAdapter.getSymbolName(colIndex),symbolRowIndex);
            for( ClockSymbols::CIterator cit = std::get<0>(pair); cit <  std::get<1>(pair); ++cit)
            {
                mClockGraphicsItems[itemIndex++]->setTargetAngle(cit->angle1());
                mClockGraphicsItems[itemIndex++]->setTargetAngle(cit->angle2());
            }
        }
    }
    qDebug() << "updateClocks exit ";
}

void ClocksLayoutViewManager::restartRotateClocksTimer()
{
    qDebug() << "restartRotateClocksTimer called ";
    auto interval = 1000 * (60-QTime::currentTime().second());
    if ( interval != mUpdateDisplayTimer.interval())
        mUpdateDisplayTimer.start(interval);
    mRotateClocksTimer.start();
}

void ClocksLayoutViewManager::updateDisplayTimerChanged()
{
    mDisplayAdapter.update();
    if ( mDisplayedSymbols != mDisplayAdapter.toString())
    {
        mRotateClocksTimer.stop();
        QFuture<void> future = QtConcurrent::run(this,&updateClocks);
        mUpdateClocksWatcher.setFuture(future);
    }
}

void ClocksLayoutViewManager::rotateClocksTimerChanged()
{
    size_t clocksUpdated = 0;

    for(auto* it : mClockGraphicsItems)
    {
        int targetAngle = it->targetAngle();
        int rotationAngle = it->rotationAngle();
        if (  rotationAngle ==targetAngle)
        {
            clocksUpdated++;
        }
        else
        {
            for( int ctr = 0; ctr <RotationAngleDelta; ++ctr,++rotationAngle)
            {
                if (rotationAngle % 360==  targetAngle)
                    break;
            }
            it->setRotationAngle(rotationAngle);
        }
    }
    if( clocksUpdated == mClockGraphicsItems.size())
    {
        mRotateClocksTimer.stop();
    }
    else
    {
        mClocksLayoutView.scene()->update();
    }
}

void ClocksLayoutViewManager::invalidatelClocks()
{
    invalidatelClocks(mClockGraphicsItems.begin(),mClockGraphicsItems.end(),1,1);
    invalidatelClocks(mClockGraphicsItems.begin(),mClockGraphicsItems.end(),1,3);
    invalidatelClocks(mClockGraphicsItems.begin(),mClockGraphicsItems.end(),2,5);
    invalidatelClocks(mClockGraphicsItems.begin(),mClockGraphicsItems.end(),-1,4);
}

void ClocksLayoutViewManager::invalidatelClocks(ClockItemsIterator start,ClockItemsIterator end,int angleDelta,int indexIncrement)
{
    for( ClockItemsIterator it =start; it <  end; it+= indexIncrement)
    {
        ClockGraphicsItem* item = *it;
        item->setRotationAngle((item->rotationAngle()+angleDelta)%360);
    }
}

QRectF ClocksLayoutViewManager::getScreenRect() const
{
    return getScreenRect(mPrimaryScreen.primaryOrientation());
}

QRectF ClocksLayoutViewManager::getScreenRect(Qt::ScreenOrientation) const
{
    qreal width = ClockLayoutWidth;
    qreal height =ClockLayoutHeight;
    return QRectF {0,0,width,height };
}
}
