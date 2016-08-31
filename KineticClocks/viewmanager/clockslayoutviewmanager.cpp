#include "clockslayoutviewmanager.hpp"
#include "utils/consts.hpp"
#include "view\clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\symbol.hpp"
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

    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::onOrientationChanged);
    connect(&mTimeTimer, &QTimer::timeout,this, &ClocksLayoutViewManager::onTimeChanged);
    mTimeTimer.setInterval(60000);
    mTimeTimer.start();
}

void ClocksLayoutViewManager::onTimeChanged()
{
    qDebug() << "ClocksLayoutViewManager::onTimeChanged";
    setDisplayTime();
}


void ClocksLayoutViewManager::showTime()
{
    setDisplayTime();
    mClocksLayoutView.show();
}

void ClocksLayoutViewManager::onOrientationChanged(Qt::ScreenOrientation newOrientation)
{
    mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}

void ClocksLayoutViewManager::setDisplayTime()
{
    ClockTime ct;
    QGraphicsScene* graphicsScene = mClocksLayoutView.scene() ;
    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 20.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[0],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);

            std::for_each(first, last, [&graphicsScene, &ypos, &xpos](const Clock &clock)
            {
                //     qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
                xpos+= 10.f;
            });

        }

    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 70.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[1],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);

            std::for_each(first, last, [&graphicsScene, &ypos, &xpos](const Clock &clock)
            {
                //  qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
                xpos+= 10.f;
            });

        }
    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 120.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[2],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);

            std::for_each(first, last, [&graphicsScene, &ypos, &xpos](const Clock &clock)
            {
                //    qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
                xpos+= 10.f;
            });

        }

    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 170.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[3],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);

            std::for_each(first, last, [&graphicsScene, &ypos, &xpos](const Clock &clock)
            {
                // qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
                xpos+= 10.f;
            });

        }
    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 220.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(ct.symbols()[4],ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);

            std::for_each(first, last, [&graphicsScene, &ypos, &xpos](const Clock &clock)
            {
                // qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                graphicsScene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
                xpos+= 10.f;
            });

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
    return QRectF{0, 0, width, height};
}
}
