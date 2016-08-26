#pragma once
#include <QGraphicsItem>

namespace twentysixapps
{
class ClockGraphicsItem : public QGraphicsItem
{
public:
    explicit ClockGraphicsItem(int itemId, QPointF sourcePoint ={10.0f, 100.0f}, QPointF destPoint ={110.0f, 185.5f});
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF mSourcePoint;
    QPointF mDestPoint;
    explicit ClockGraphicsItem(const ClockGraphicsItem& rhs) = delete;
    ClockGraphicsItem& operator= (const ClockGraphicsItem& rhs) = delete;



};
}

