#include "clockgraphicsitem.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{
const int ClockGraphicsItem::ClockHandLength =4;
const qreal ClockGraphicsItem::ClockDiameter = 10.0f;
const qreal ClockGraphicsItem::ClockRadius = 5.0f;
const qreal ClockGraphicsItem::XPosDelta = 0.0f;
const qreal ClockGraphicsItem::YPosDelta = 0.0f;
const Qt::GlobalColor ClockGraphicsItem::LineColor  = Qt::GlobalColor::white;
const Qt::GlobalColor ClockGraphicsItem::BackColor  = Qt::GlobalColor::black;

ClockGraphicsItem::ClockGraphicsItem(QPointF sourcePoint,int angle) :
    QGraphicsItem(0),
    mSourcePoint(QPointF( sourcePoint.x()+ ClockRadius , sourcePoint.y()+ClockRadius)),
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
