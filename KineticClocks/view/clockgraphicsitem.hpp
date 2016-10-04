#pragma once

#include "model/clock.hpp"
#include <QGraphicsItem>
#include <QColor>
#include <QPen>


namespace twentysixapps
{
class ClockGraphicsItem : public QGraphicsItem
{
public:
    const static qreal ClockHandLength;
    const static qreal ClockDiameter;
    const static qreal ClockRadius;

    ClockGraphicsItem( bool isPortraitOrientation, QColor& penColor,  QPointF sourcePoint = {
            ClockDiameter, ClockDiameter
        }, int targetAngle = {Clock::Angle1Default});
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QColor penColor() const;
    int targetAngle() const;
    void setTargetAngle(int targetAngle);
    int rotationAngle() const;
    void setRotationAngle(int rotationAngle);
    void setOrientation(bool isPortraitOrientation);

    explicit ClockGraphicsItem(const ClockGraphicsItem& rhs) = delete;
    ClockGraphicsItem& operator= (const ClockGraphicsItem& rhs) = delete;
    ClockGraphicsItem(ClockGraphicsItem&&) =delete;
    ClockGraphicsItem& operator=(ClockGraphicsItem&&) =delete;

private:
    QPen mPen;
    QColor mPenColor;
    QPointF mSourcePoint;
    QLineF mAngledLine;
    int mTargetAngle;
    int mRotationAngle;



};
}
