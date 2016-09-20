#include "clocktime.hpp"
#include <QTime>
#include <QDebug>

namespace twentysixapps
{
ClockTime::ClockTime(const QTime& displayTime)
{
    mSymbols[2] = SymbolName::Colon;
    setDisplayTime(displayTime);
}

ClockTime::ClockTime()
{
    mSymbols[2] = SymbolName::Colon;
    updateDisplayTime();
}

void ClockTime::setDisplayTime(const QTime& displayTime)
{
    mText = displayTime.toString("HHmm");
    mSymbols[0]  =  ClockSymbols::getSymbolName( mText.at(0));
    mSymbols[1]  =  ClockSymbols::getSymbolName( mText.at(1));
    mSymbols[3]  =  ClockSymbols::getSymbolName( mText.at(2));
    mSymbols[4]  =  ClockSymbols::getSymbolName( mText.at(3));
}

void ClockTime::updateDisplayTime()
{
     setDisplayTime(QTime::currentTime());
}


}
