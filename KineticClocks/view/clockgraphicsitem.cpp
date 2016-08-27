#include "clockgraphicsitem.hpp"
#include <QPainter>
#include <QDebug>


namespace twentysixapps
{


ClockGraphicsItem::ClockGraphicsItem(QPointF sourcePoint,int angle) :
    QGraphicsItem(0),
    mSourcePoint(sourcePoint),
    mAngle(angle)
{
   // setPos(sourcePoint);
}

QRectF twentysixapps::ClockGraphicsItem::boundingRect() const
{

    QRectF rect =  QRectF (0,0,10.f,10.f);
    qDebug() << "******************  boundingRect:" << rect;
    return rect;
}

void twentysixapps::ClockGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLineF angleline;

    /* Set the origin: */
    angleline.setP1(mSourcePoint);
    angleline.setAngle(mAngle);
    angleline.setLength(4);
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::color0, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(angleline);
//    QLineF line(mSourcePoint, mDestPoint);


}
}
