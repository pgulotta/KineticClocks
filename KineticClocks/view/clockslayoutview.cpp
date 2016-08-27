#include "clockslayoutview.hpp"
#include "clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\symbol.hpp"
#include "model\clocksymbols.hpp"
#include <QGraphicsItem>
#include <QDebug>

namespace twentysixapps
{
ClocksLayoutView::ClocksLayoutView(QGraphicsScene* scene) :
    QGraphicsView(scene, 0)
{
    scene->setBackgroundBrush(Qt::color1);

    for(int ypos = 0; ypos < 6; ypos++)
        {
            qreal xpos = 20.0f;
            ClockSymbols cs;
            std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Seven,ypos);
            auto first =  std::get<0>(tuple);
            auto last =  std::get<1>(tuple);

            std::for_each(first, last, [&scene, &ypos, &xpos](const Clock &clock)
            {
                qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                scene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                scene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
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

            std::for_each(first, last, [&scene, &ypos, &xpos](const Clock &clock)
            {
                qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                scene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                scene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
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

            std::for_each(first, last, [&scene, &ypos, &xpos](const Clock &clock)
            {
                qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                scene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                scene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
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

            std::for_each(first, last, [&scene, &ypos, &xpos](const Clock &clock)
            {
                qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
                scene->addItem(new ClockGraphicsItem( QPointF(xpos,ypos*10.f),clock.Angle1));
                scene->addItem(new ClockGraphicsItem( QPointF(xpos, ypos*10.f),clock.Angle2));
                xpos+= 10.f;
            });

        }
}


void twentysixapps::ClocksLayoutView::resizeEvent(QResizeEvent *event)
{
    fitInView(scene()->sceneRect());
    QGraphicsView::resizeEvent(event);
}


}
