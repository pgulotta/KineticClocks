#include "platform.hpp"

namespace twentysixapps
{
#ifdef Q_OS_ANDROID
constexpr static int RotationAngleDelta = 4;
#elif Q_OS_IOS
sconstexpr tatic int RotationAngleDelta = 4;
#else
static int RotationAngleDelta = 2;

#endif


int Platform::rotationAngleDelta()
{
    return RotationAngleDelta;
}


}
