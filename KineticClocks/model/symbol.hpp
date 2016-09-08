#pragma once

#include <array>
#include <iterator>
#include <cassert>
#include "clock.hpp"
#include "grid.hpp"

namespace twentysixapps
{
    class Symbol
    {
    public:
        static const int RowsPerSymbol = 6;
        static const int ColsPerSymbol = 5;
        static const int ItemsPerSymbolCount = RowsPerSymbol* ColsPerSymbol   ;

        typedef  Grid<Clock, RowsPerSymbol, ColsPerSymbol> _GridArray;
        typedef _GridArray::_Iterator _Iterator;

        Symbol(std::array<Clock,  ItemsPerSymbolCount>&& clocks) noexcept: mSymbol (std::move(clocks))
        {
        }


        std::tuple<_GridArray::_Iterator ,_GridArray::_Iterator> GetIterators(int row)
        {
            return mSymbol.GetIterators(row);
        }


    private:
        _GridArray mSymbol;

    };


}
