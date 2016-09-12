#include "clockgraphicsitem.hpp"
#include "model/symbol.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{

const qreal ClockGraphicsItem::ClockRadius =10.0f;
const qreal ClockGraphicsItem::ClockDiameter = ClockRadius *2.0f;
const qreal ClockGraphicsItem::ClockHandLength = ClockRadius * 0.8f;


ClockGraphicsItem::ClockGraphicsItem(QColor& penColor,  QPointF sourcePoint,int angle) :
    QGraphicsItem(0),
    mPen(penColor),
    mSourcePoint(QPointF( sourcePoint.x()+ ClockRadius , sourcePoint.y()+ClockRadius)),
    mAngledLine(sourcePoint.x()+ ClockRadius , sourcePoint.y()+ClockRadius, 0,0 ),
    mAngle(angle),
    mRotationAngle(angle)
{
    mAngledLine.setLength(ClockHandLength);
}

QRectF twentysixapps::ClockGraphicsItem::boundingRect() const
{
    return QRectF (0.f,0.f,ClockDiameter,ClockDiameter);
}

void twentysixapps::ClockGraphicsItem::paint(QPainter *painter,
        const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(mPen);
    mAngledLine.setAngle(mRotationAngle);
    painter->drawLine(mAngledLine);
}

void ClockGraphicsItem::setPenColor(QColor color)
{
     mPen.setColor(color);
}

QColor ClockGraphicsItem::penColor() const
{
    return mPen.color();
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
