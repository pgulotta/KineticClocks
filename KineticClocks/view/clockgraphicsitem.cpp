#include "clockgraphicsitem.hpp"
#include "utils/consts.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{
const Qt::GlobalColor ClockGraphicsItem::LineColor  = Qt::GlobalColor::white;
const Qt::GlobalColor ClockGraphicsItem::BackColor  = Qt::GlobalColor::black;
const qreal ClockGraphicsItem::ClockDiameter = 10.0f;
const qreal ClockGraphicsItem::XStartPosisiton = 0.0f;
const qreal ClockGraphicsItem::YStartPosisiton = 0.0f;

ClockGraphicsItem::ClockGraphicsItem(QPointF sourcePoint,int angle) :
    QGraphicsItem(0),
    mSourcePoint(QPointF( sourcePoint.x()+5.f , sourcePoint.y()+5.f)),
    mAngle(angle)
{
}

QRectF twentysixapps::ClockGraphicsItem::boundingRect() const
{
    return QRectF (0.f,0.f,ClockDiameter,ClockDiameter);
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

int ClockGraphicsItem::angle() const
{
    return mAngle;
}

void ClockGraphicsItem::setAngle(int angle)
{
    mAngle = angle;
}
}
