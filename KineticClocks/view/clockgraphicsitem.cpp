#include "clockgraphicsitem.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{

const qreal ClockGraphicsItem::ClockRadius = 8.0f;
const qreal ClockGraphicsItem::ClockDiameter = ClockRadius * 2.0f;
const qreal ClockGraphicsItem::ClockHandLength = ClockRadius - 0.00f;
const qreal ClockGraphicsItem::XPosDelta = 0.0f;
const qreal ClockGraphicsItem::YPosDelta = 0.0f;
const Qt::GlobalColor ClockGraphicsItem::LineColor  = Qt::GlobalColor::darkMagenta;
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
