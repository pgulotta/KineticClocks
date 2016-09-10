#pragma once

#include "clocksymbols.hpp"
#include <QTime>
#include <array>


namespace twentysixapps
{
class ClockTime
{
public:
    static const size_t SymbolsCount = 5;
    typedef std::array<SymbolName, SymbolsCount> Array;
    typedef  Array::const_iterator  CIterator;

    ClockTime ();
    ClockTime (const QTime& displayTime);
    void setDisplayTime(const QTime& displayTime);
    CIterator  symbols() const
    {
        return mSymbols.cbegin();
    }

    const QString& toString() const
    {
        return mText;
    }

private:
    Array mSymbols;
    QString mText;

};
}
