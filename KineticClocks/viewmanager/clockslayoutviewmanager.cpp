#include "clockslayoutviewmanager.hpp"
#include "utils/consts.hpp"
#include "view\clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\symbol.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QScreen>
#include <QDebug>

namespace twentysixapps
{

ClocksLayoutViewManager::ClocksLayoutViewManager(QScreen* primaryScreen):
    QObject(nullptr),mPrimaryScreen(*primaryScreen), mClocksLayoutView(nullptr)
{
    auto virtualSize = mPrimaryScreen.availableVirtualSize();

    mClocksLayoutView.setScene(new QGraphicsScene(GetScreenRect()));
    mClocksLayoutView.scene()->setBackgroundBrush(BackColor);
    mClocksLayoutView.resize(virtualSize );

    connect(&mPrimaryScreen, &QScreen::primaryOrientationChanged, this, &ClocksLayoutViewManager::orientationChanged);
}

void ClocksLayoutViewManager::showTime()
{
    initialize();
    mClocksLayoutView.show();
}

void ClocksLayoutViewManager::orientationChanged(Qt::ScreenOrientation newOrientation)
{
  mClocksLayoutView.scene()->setSceneRect(GetScreenRect());
}

void ClocksLayoutViewManager::initialize()
{
    QGraphicsScene* graphicsScene = mClocksLayoutView.scene() ;
    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 20.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Seven,ypos);
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
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Colon,ypos);
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
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Four,ypos);
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
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Zero,ypos);
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
