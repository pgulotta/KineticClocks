#include "clocktime.hpp"

namespace twentysixapps
{
ClockTime::ClockTime(const QTime& displayTime,QObject *parent):  QObject(parent)
{
    setDisplayTime(displayTime);
}

void ClockTime::setDisplayTime(const QTime& displayTime)
{
    mDigits[0] = displayTime.hour()/10;
    mDigits[1] = displayTime.hour() -(10 * mDigits.at(0));
    mDigits[2] = displayTime.minute() / 10;
    mDigits[3] = displayTime.minute() -(10 * mDigits.at(2));

    emit displayTimeChanged();
}

std::array<int, 5>::const_iterator ClockTime::digits() const
{
    return mDigits.cbegin();
}


}
