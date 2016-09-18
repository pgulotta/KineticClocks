#pragma once

#include "clocksymbols.hpp"
#include <QTime>
#include <array>


namespace twentysixapps
{
class ClockTime
{
public:
static constexpr size_t SymbolsCount = 5;
typedef std::array<SymbolName, SymbolsCount> Array;
typedef  Array::const_iterator CIterator;

ClockTime ();
ClockTime (const QTime& displayTime);
void setDisplayTime(const QTime& displayTime);

void refresh();

CIterator  getSymbols() const
{
    return mSymbols.cbegin();
}

SymbolName  getSymbolName(size_t colIndex) const
{
    return getSymbols()[colIndex];
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
