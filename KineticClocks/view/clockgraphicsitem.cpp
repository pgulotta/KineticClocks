#include "clockgraphicsitem.hpp"
#include "model/symbol.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{

const qreal ClockGraphicsItem::ClockRadius =10.0f;
const qreal ClockGraphicsItem::ClockDiameter = ClockRadius *2.0f;
const qreal ClockGraphicsItem::ClockHandLength = ClockRadius;


ClockGraphicsItem::ClockGraphicsItem( bool isPortraitOrientation, QColor& penColor,  QPointF sourcePoint,int targetAngle) :
    QGraphicsItem(0),
    mPen(penColor),
    mSourcePoint(QPointF( sourcePoint.x()+ ClockRadius, sourcePoint.y()+ClockRadius)),
    mAngledLine(sourcePoint.x()+ ClockRadius, sourcePoint.y()+ClockRadius, 0,0 ),
    mTargetAngle(targetAngle),
    mRotationAngle(targetAngle)
{
    setOrientation( isPortraitOrientation);
    mPen.setCapStyle(Qt::RoundCap);
    mPen.setJoinStyle(Qt::RoundJoin);
    mPen.setStyle(Qt::DotLine);
    mAngledLine.setLength(ClockHandLength);
}

QRectF twentysixapps::ClockGraphicsItem::boundingRect() const
{
    return QRectF (0.f,0.f,ClockDiameter,ClockDiameter);
}

void twentysixapps::ClockGraphicsItem::paint(QPainter *painter,
                                             const QStyleOptionGraphicsItem *, QWidget *)
{
    // painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(mPen);
    mAngledLine.setAngle(mRotationAngle);
    painter->drawLine(mAngledLine);
}

QColor ClockGraphicsItem::penColor() const
{
    return mPen.color();
}

int ClockGraphicsItem::targetAngle() const
{
    return mTargetAngle;
}

void ClockGraphicsItem::setTargetAngle(int targetAngle)
{
    mTargetAngle = targetAngle;
}

int ClockGraphicsItem::rotationAngle() const
{
    return mRotationAngle;
}

void ClockGraphicsItem::setRotationAngle(int rotationAngle)
{
    mRotationAngle = rotationAngle;
}

void ClockGraphicsItem::setOrientation(bool isPortraitOrientation)
{
    mPen.setWidth( isPortraitOrientation ? 2 : 3);
}
}
