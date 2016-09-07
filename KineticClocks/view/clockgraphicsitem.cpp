#include "clockgraphicsitem.hpp"
#include "model/symbol.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{

const qreal ClockGraphicsItem::ClockRadius = 6.85f;
const qreal ClockGraphicsItem::ClockDiameter = ClockRadius *2.0f;
const qreal ClockGraphicsItem::ClockHandLength = ClockRadius - 1.2f;
const Qt::GlobalColor ClockGraphicsItem::LineColor  = Qt::GlobalColor::yellow;
const Qt::GlobalColor ClockGraphicsItem::BackColor  = Qt::GlobalColor::black;

ClockGraphicsItem::ClockGraphicsItem(QPointF sourcePoint,int angle) :
    QGraphicsItem(0),
    mSourcePoint(QPointF( sourcePoint.x()+ ClockRadius , sourcePoint.y()+ClockRadius)),
    mAngle(angle),
    mRotationAngle(angle)
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
    angledLine.setAngle(mRotationAngle);
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

int ClockGraphicsItem::rotationAngle() const
{
    return mRotationAngle;
}

void ClockGraphicsItem::setRotationAngle(int rotationAngle)
{
    mRotationAngle = rotationAngle;
}
}
