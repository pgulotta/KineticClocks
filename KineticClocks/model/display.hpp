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

    Display(const T& t):mDisplay(t)
    {
    }

    CIterator symbols() const
    {
        return mDisplay.symbols();
    }

    const QString& toString()
    {
        return mDisplay.toString();
    }


private:
    const T&  mDisplay;



};

}
