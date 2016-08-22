#pragma once

#include <memory>
#include <array>
#include <iterator>
#include "symbol.hpp"
#include "grid.hpp"

namespace twentysixapps
{
    enum class SymbolName
    {
        Zero,
        One,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Colon,
        HorizontalLine
    };

    class ClockSymbols
    {
    public:
        typedef Symbol::_GridArray::_Iterator _Iterator;
        static const int RowCount = (int)SymbolName::HorizontalLine +1;

        std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator> GetRow(SymbolName name, int row) ;

    private:


    };

}
