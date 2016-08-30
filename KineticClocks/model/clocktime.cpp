#include "clocktime.hpp"

namespace twentysixapps
{
    ClockTime::ClockTime( QTime displayTime,QObject *parent):  QObject(parent)
{
    setDisplayTime(displayTime);
}

QTime ClockTime::displayTime() const
{
    return mDisplayTime;
}

void ClockTime::setDisplayTime(const QTime &displayTime)
{
    if ( displayTime== mDisplayTime)
        return;
    mDisplayTime = displayTime;
    mDigits[0] = mDisplayTime.hour()%10;
    mDigits[1] = mDisplayTime.hour() - mDigits[0];
    mDigits[2] = mDisplayTime.minute()%10;
    mDigits[3] = mDisplayTime.minute()- mDigits[2];

    emit displayTimeChanged();
}

std::array<int, 5>::const_iterator ClockTime::digits() const
{
    return mDigits.cbegin();
}


}
