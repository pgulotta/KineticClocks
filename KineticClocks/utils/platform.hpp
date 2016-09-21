
#pragma once
#include <QWidget>

namespace twentysixapps
{
class Platform
{

public:
    static int  rotationAngleDelta();
    static QSize windowDefaultSize(QSize virtualSize);

private:
    explicit Platform(const Platform& rhs) = delete;
    Platform& operator= (const Platform& rhs) = delete;
    Platform(Platform&&) =delete;
    Platform& operator=(Platform&&) =delete;
};
}
