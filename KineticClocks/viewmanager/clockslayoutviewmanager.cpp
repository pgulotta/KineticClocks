#include "clockslayoutviewmanager.hpp"
#include "utils/consts.hpp"
#include "view\clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\symbol.hpp"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>

namespace twentysixapps
{

ClocksLayoutViewManager::ClocksLayoutViewManager(int screenWidth, int screenHeight):
    QObject(nullptr),
    mClocksLayoutView(new QGraphicsScene(0, 0, screenWidth /ClockDiameter,screenHeight/ClockDiameter))
{
    mClocksLayoutView.scene()->setBackgroundBrush(BackColor);
    mClocksLayoutView.resize(screenWidth ,screenHeight);
}

void ClocksLayoutViewManager::showTime()
{
    initialize();
    mClocksLayoutView.show();
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
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Eight,ypos);
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
}
