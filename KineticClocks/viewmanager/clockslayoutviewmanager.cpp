#include "clockslayoutviewmanager.hpp"
#include "model\clock.hpp"
#include "utils/colorgenerator.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QScreen>
#include <QDebug>
#include <QTimer>
#include <QColor>

namespace twentysixapps
{

ClocksLayoutViewManager::ClocksLayoutViewManager(QObject*  parent,   const QScreen* primaryScreen,    DisplayAdapter* displayAdapter):
    QObject(parent ),
    mPrimaryScreen(*primaryScreen),
    mDisplayAdapter(*displayAdapter),
    mRotateClocksTimer(*new QTimer(this)),
    mUpdateDisplayTimer (*new QTimer(this))
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();

    mClocksLayoutView.setScene(new QGraphicsScene(getScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(mBackColor);
    mClocksLayoutView.resize(virtualSize.width()/2 , virtualSize.height()/2 );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    connect(&mRotateClocksTimer, &QTimer::timeout, this, &ClocksLayoutViewManager::rotateClocksTimerChanged);
    connect(&mUpdateDisplayTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::updateDisplayTimerChanged);
    displaySymbols();
}

void ClocksLayoutViewManager::displaySymbols()
{
    updateDisplayTimerChanged();
    mClocksLayoutView.show();
    mRotateClocksTimer.start(25);
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation )
{
    mClocksLayoutView.scene()->setSceneRect(getScreenRect());
}

void ClocksLayoutViewManager::createSceneItems()
{
    int itemIndex=0;
    qreal xposClock =0.0f;
    qreal yposClock = 0.0f;
    mLineColor = mColorGenerator.nextOffsetColor();
    for( int gridIndex = 0;  gridIndex< GridsDepth; ++gridIndex)
        {
            for(size_t symbolColIndex= 0; symbolColIndex < ClockTime::SymbolsCount; ++symbolColIndex )
                {
                    for(size_t rowIndex = 0; rowIndex < Symbol::RowsPerSymbol; rowIndex+= 1)
                        {
                            yposClock = (gridIndex * ClockGraphicsItem::ClockDiameter * Symbol::RowsPerSymbol) + (rowIndex * ClockGraphicsItem::ClockDiameter );
                            xposClock = symbolColIndex* ClockGraphicsItem::ClockDiameter * Symbol::ColsPerSymbol;
                            for(size_t colIndex = 0; colIndex < Symbol::ColsPerSymbol; colIndex++)
                                {
                                    mClockGraphicsItems[itemIndex] = new ClockGraphicsItem( mLineColor, QPointF(xposClock, yposClock),Clock::Angle1Default);
                                    mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex++]);
                                    mClockGraphicsItems[itemIndex] =new ClockGraphicsItem( mLineColor, QPointF(xposClock, yposClock),Clock::Angle2Default);
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
    mDisplayAdapter.refresh();
    if ( mDisplayedSymbols != mDisplayAdapter.toString())
        {
            invalidatelClocks( );
            changePenColor();
            mDisplayedSymbols = mDisplayAdapter.toString();
            int itemIndex= Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock * ClockTime::SymbolsCount  * DisplayGridIndex;
            for(size_t colIndex = 0; colIndex < Symbol::ColsPerSymbol; ++colIndex )
                {
                    for(size_t symbolRowIndex = 0; symbolRowIndex < Symbol::RowsPerSymbol; symbolRowIndex++)
                        {
                            ClockSymbols cs;
                            ClockSymbols::Citerators  pair =cs.getRow(mDisplayAdapter.getSymbolName(colIndex),symbolRowIndex);
                            for( ClockSymbols::CIterator  cit = std::get<0>(pair) ; cit <  std::get<1>(pair) ; ++cit)
                                {
                                    mClockGraphicsItems[itemIndex++]->setAngle(cit->angle1());
                                    mClockGraphicsItems[itemIndex++]->setAngle(cit->angle2());
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
            if (  it->rotationAngle()  == it->angle())
                {
                    clocksUpdated++;
                }
            else
                {
                    it->setRotationAngle(( it->rotationAngle() +1)%360);
#ifdef Q_OS_ANDROID
                    if (  it->rotationAngle()  != it->angle())
                        it->setRotationAngle(( it->rotationAngle() +1)%360);
#elif Q_OS_IOS
                    if (  it->rotationAngle()  != it->angle())
                        it->setRotationAngle(( it->rotationAngle() +1)%360);
#endif
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
    invalidatelClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(),1,1);
    invalidatelClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(), 1,3);
    invalidatelClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(), -1,5);
    invalidatelClocks(mClockGraphicsItems.begin(), mClockGraphicsItems.end(),-2 ,4);
}

void ClocksLayoutViewManager::changePenColor()
{
    QColor color {mColorGenerator.nextOffsetColor()};
    qDebug() << "changing color to " << color;
    for( auto item : mClockGraphicsItems)
        {
            item->setPenColor( color);
        }
}

void ClocksLayoutViewManager::invalidatelClocks(ClockItemsIterator start, ClockItemsIterator end, int angleDelta  , int indexIncrement)
{
    for( ClockItemsIterator it =start ;  it <  end;  it+= indexIncrement)
        {
            ClockGraphicsItem* item = *it;
            item->setRotationAngle((item->rotationAngle()+angleDelta)%360);
        }
}

QRectF ClocksLayoutViewManager::getScreenRect() const
{
    return getScreenRect(mPrimaryScreen.primaryOrientation());
}

QRectF ClocksLayoutViewManager::getScreenRect(Qt::ScreenOrientation ) const
{
    qreal width = ClockLayoutWidth;
    qreal height =ClockLayoutHeight;
    return QRectF{0, 0, width, height };
}
}
