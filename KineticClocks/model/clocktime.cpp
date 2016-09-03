#include "clocktime.hpp"

#include <QDebug>

namespace twentysixapps
{
ClockTime::ClockTime(const QTime& displayTime,QObject *parent):  QObject(parent)
{
    mSymbols[2] = SymbolName::Colon;
    setDisplayTime(displayTime);
}

ClockTime::ClockTime():  QObject(0)
{
    mSymbols[2] = SymbolName::Colon;
    setDisplayTime(QTime::currentTime());
}

void ClockTime::setDisplayTime(const QTime& displayTime)
{
    mText = displayTime.toString("HHmm");
    mSymbols[0]  =  ClockSymbols::GetSymbolName( mText.at(0));
    mSymbols[1]  =  ClockSymbols::GetSymbolName( mText.at(1));
    mSymbols[3]  =  ClockSymbols::GetSymbolName( mText.at(2));
    mSymbols[4]  =  ClockSymbols::GetSymbolName( mText.at(3));
}

SymbolsIterator ClockTime::symbols() const
{
    return mSymbols.cbegin();
}
}
