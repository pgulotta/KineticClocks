#pragma once

#include "clocksymbols.hpp"
#include <QTime>
#include <array>


namespace twentysixapps
{
class ClockTime final
{
public:
    static constexpr size_t SymbolsCount = 5;
    using Array = std::array<SymbolName, SymbolsCount>;
    using CIterator =  Array::const_iterator;

    ClockTime ();
    explicit ClockTime (const QTime& displayTime);
    void setDisplayTime(const QTime& displayTime);

    void updateDisplayTime();

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
