
#pragma once
#include <QWidget>

namespace twentysixapps
{
class  Platform
{
public:
   const  static   int  rotationAngleDelta();

private:
    explicit Platform(const Platform& rhs) = delete;
    Platform& operator= (const Platform& rhs) = delete;
    Platform(Platform&&) =delete;
    Platform& operator=(Platform&&) =delete;
};
}
