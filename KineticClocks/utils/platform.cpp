#include "platform.hpp"

namespace twentysixapps
{
#ifdef Q_OS_ANDROID
constexpr static int RotationAngleDelta = 8;
#else
static int RotationAngleDelta = 2;
#endif


int Platform::rotationAngleDelta()
{
    return RotationAngleDelta;
}

QSize Platform::windowDefaultSize(QSize virtualSize)
{
#ifdef Q_OS_ANDROID
    return virtualSize;
#else
    return QSize(virtualSize.width()/4, virtualSize.height()/4);
#endif
}


}
