#pragma once

#include <array>
#include <iterator>
#include <cassert>
#include <tuple>

namespace twentysixapps
{
template<typename T , int TSymbolsCount>
class Display
{
public:
    typedef std::array<SymbolName, TSymbolsCount> Array;
    typedef  typename Array::const_iterator CIterator;

    Display(const T&& t):mDisplay( std::move(t))
    {
    }

    CIterator getSymbols() const
    {
        return mDisplay.symbols();
    }

    const QString& toString() const
    {
        return mDisplay.toString();
    }


private:
    const T  mDisplay;



};

}
