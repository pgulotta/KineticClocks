#pragma once

#include "clocksymbols.hpp"
#include <QTime>
#include <array>


namespace twentysixapps
{
class ClockTime
{
public:
    static const int SymbolsPerClockTime = 5;
    typedef std::array<SymbolName, SymbolsPerClockTime> Array;
    typedef  Array::const_iterator  CIterator;

    ClockTime ();
    ClockTime (const QTime& displayTime);
    void setDisplayTime(const QTime& displayTime);
    CIterator  symbols() const
    {
        return mSymbols.cbegin();
    }

    const QString& toString()
    {
        return mText;
    }

private:

    Array mSymbols;
    QString mText;
    explicit ClockTime(const ClockTime& rhs) = delete;
    ClockTime& operator= (const ClockTime& rhs) = delete;
};
}
