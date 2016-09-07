#pragma once

#include "model/clock.hpp"
#include <QGraphicsItem>

namespace twentysixapps
{
class ClockGraphicsItem : public QGraphicsItem
{
public:
    const static qreal ClockHandLength;
    const static qreal ClockDiameter ;
    const static qreal ClockRadius;
    const static Qt::GlobalColor LineColor ;
    const static Qt::GlobalColor BackColor ;

    explicit ClockGraphicsItem( QPointF sourcePoint = {ClockDiameter, ClockDiameter}, int angle = {Clock::Angle1Default});
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int angle() const;
    void setAngle(int angle);

    int rotationAngle() const;
    void setRotationAngle(int rotationAngle);

private:
    QPointF mSourcePoint;
    int  mAngle;
    int mRotationAngle;
    explicit ClockGraphicsItem(const ClockGraphicsItem& rhs) = delete;
    ClockGraphicsItem& operator= (const ClockGraphicsItem& rhs) = delete;



};
}
