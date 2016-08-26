#include "clockgraphicsitem.hpp"
#include <QPainter>
namespace twentysixapps
{


ClockGraphicsItem::ClockGraphicsItem(int itemId,
                                     QPointF sourcePoint,
                                     QPointF destPoint) :
    QGraphicsItem(0),
    mSourcePoint(sourcePoint),
    mDestPoint(destPoint)
{
}

QRectF twentysixapps::ClockGraphicsItem::boundingRect() const
{
    return  QRectF (0,0,200,200);
}

void twentysixapps::ClockGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLineF line(mSourcePoint, mDestPoint);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);


}
}

