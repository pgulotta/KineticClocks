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

ClocksLayoutViewManager::ClocksLayoutViewManager(QScreen* primaryScreen):
    QObject(nullptr),mPrimaryScreen(*primaryScreen), mClocksLayoutView(nullptr),mTimeTimer (*new QTimer(this))
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();

    mClocksLayoutView.setScene(new QGraphicsScene(GetScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(BackColor);
    mClocksLayoutView.resize(virtualSize );
    createSceneItems();
    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    connect(&mTimeTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::onTimeChanged);
    mTimeTimer.setInterval(60000);
    mTimeTimer.start();
}

void ClocksLayoutViewManager::onTimeChanged()
{
    setDisplayTime();
}

void ClocksLayoutViewManager::showTime()
{
    setDisplayTime();
    mClocksLayoutView.show();
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation )
{
    mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}
void ClocksLayoutViewManager::createSceneItems()
{
    int index=0;
    for(int ypos = 0; ypos < Symbol::RowCount; ypos++)
        {
            qreal xpos = 20.0f;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    xpos+= 10.f;
                }
        }
    for(int ypos = 0; ypos < Symbol::RowCount; ypos++)
        {
            qreal xpos = 70.0f;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    xpos+= 10.f;
                }
        }
    for(int ypos = 0; ypos < Symbol::RowCount; ypos++)
        {
            qreal xpos = 120.0f;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    xpos+= 10.f;
                }
        }

    for(int ypos = 0; ypos < Symbol::RowCount; ypos++)
        {
            qreal xpos = 170.0f;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    xpos+= 10.f;
                }
        }
    for(int ypos = 0; ypos < Symbol::RowCount; ypos++)
        {
            qreal xpos = 220.0f;
            for(int xIndex = 0; xIndex < Symbol::ColCount; xIndex++)
                {
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    mClockGraphicsItems[index++] = new ClockGraphicsItem( QPointF(xpos,ypos*10.f),0);
                    xpos+= 10.f;
                }
        }
    for(int itemIndex = 0; itemIndex < mClockGraphicsItems.size(); itemIndex++)
        {
            mClocksLayoutView.scene()->addItem(mClockGraphicsItems[itemIndex]);
        }
}

void ClocksLayoutViewManager::setDisplayTime()
{
    ClockTime ct;
    int index=0;
    for(int ypos = 0; ypos < Symbol::RowCount; ypos++)
        {
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[0],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);
            std::for_each(first, last, [&index,this](const Clock &clock)
            {
                //  qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                mClockGraphicsItems[index++]->setAngle(clock.Angle1);
                mClockGraphicsItems[index++]->setAngle(clock.Angle2);
            });
        }

    for(int ypos = 0; ypos < 6; ypos++)
        {
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[1],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);
            std::for_each(first, last, [&index,this](const Clock &clock)
            {
                //  qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                mClockGraphicsItems[index++]->setAngle(clock.Angle1);
                mClockGraphicsItems[index++]->setAngle(clock.Angle2);
            });
        }
    for(int ypos = 0; ypos < 6; ypos++)
        {
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[2],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);
            std::for_each(first, last, [&index,this](const Clock &clock)
            {
                //  qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                mClockGraphicsItems[index++]->setAngle(clock.Angle1);
                mClockGraphicsItems[index++]->setAngle(clock.Angle2);
            });
        }

    for(int ypos = 0; ypos < 6; ypos++)
        {
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[3],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);
            std::for_each(first, last, [&index,this](const Clock &clock)
            {
                //  qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                mClockGraphicsItems[index++]->setAngle(clock.Angle1);
                mClockGraphicsItems[index++]->setAngle(clock.Angle2);
            });
        }
    for(int ypos = 0; ypos < 6; ypos++)
        {
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[4],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);
            std::for_each(first, last, [&index,this](const Clock &clock)
            {
                //  qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                mClockGraphicsItems[index++]->setAngle(clock.Angle1);
                mClockGraphicsItems[index++]->setAngle(clock.Angle2);
            });
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
