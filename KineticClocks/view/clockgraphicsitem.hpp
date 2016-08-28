#pragma once
#include "utils/consts.hpp"
#include <QGraphicsItem>

namespace twentysixapps
{
class ClockGraphicsItem : public QGraphicsItem
{
public:


    explicit ClockGraphicsItem( QPointF sourcePoint ={ClockDiameter, ClockDiameter}, int angle ={DefaultClockAngle});
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF mSourcePoint;
    int  mAngle;
    explicit ClockGraphicsItem(const ClockGraphicsItem& rhs) = delete;
    ClockGraphicsItem& operator= (const ClockGraphicsItem& rhs) = delete;



};
}

