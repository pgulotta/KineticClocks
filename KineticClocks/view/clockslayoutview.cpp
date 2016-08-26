#include "clockslayoutview.hpp"
#include "clockgraphicsitem.hpp"
#include <QGraphicsItem>


namespace twentysixapps
{
ClocksLayoutView::ClocksLayoutView(QGraphicsScene* scene) :
    QGraphicsView(scene, 0)
{
    scene->setBackgroundBrush(Qt::yellow);
    scene->addItem(new ClockGraphicsItem(0, QPointF(120.0f, 199.9f)));
    scene->addItem(new ClockGraphicsItem(0, QPointF(20.0f, 99.9f)));
    scene->addItem(new ClockGraphicsItem(0, QPointF(-20.0f, -99.9f)));
}


void twentysixapps::ClocksLayoutView::resizeEvent(QResizeEvent *event)
{
    fitInView(scene()->sceneRect());
    QGraphicsView::resizeEvent(event);
}


}
