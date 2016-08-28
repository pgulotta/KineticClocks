#include "clockgraphicsitem.hpp"
#include "utils/consts.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{


ClockGraphicsItem::ClockGraphicsItem(QPointF sourcePoint,int angle) :
    QGraphicsItem(0),
    mSourcePoint(sourcePoint),
    mAngle(angle)
{
}

QRectF twentysixapps::ClockGraphicsItem::boundingRect() const
{
    return QRectF (0,0,ClockDiameter,ClockDiameter);
}

void twentysixapps::ClockGraphicsItem::paint(QPainter *painter,
                                             const QStyleOptionGraphicsItem *, QWidget *)
{
    QLineF angledLine;
    angledLine.setP1(mSourcePoint);
    angledLine.setAngle(mAngle);
    angledLine.setLength(ClockHandLength);
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(QPen(LineColor, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(angledLine);
}
}
