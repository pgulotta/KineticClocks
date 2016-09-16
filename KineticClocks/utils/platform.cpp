#include "platform.hpp"

namespace twentysixapps
{
#ifdef Q_OS_ANDROID
static int mRotationAngleDelta = 4;
#elif Q_OS_IOS
static int mRotationAngleDelta = 4;
#else
static int mRotationAngleDelta = 2;

#endif


int Platform::rotationAngleDelta()
{
    return mRotationAngleDelta;
}


}
