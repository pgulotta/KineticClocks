#pragma once

#include <array>
#include <iterator>
#include <cassert>
#include <tuple>

namespace twentysixapps
{
template<typename T , size_t TSymbolsCount>
class Display
{
public:
    typedef std::array<SymbolName, TSymbolsCount> Array;
    typedef  typename Array::const_iterator CIterator;

    explicit Display(const T&& t):mDisplay( std::move(t))
    {
    }

    constexpr   CIterator getSymbols() const
    {
        return mDisplay.getSymbols();
    }

    const QString& toString() const
    {
        return mDisplay.toString();
    }


private:
    T  mDisplay;



};

}
