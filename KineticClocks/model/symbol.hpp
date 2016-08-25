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
        static const int RowCount = 6;
        static const int ColCount = 5;
        static const int ItemCount = RowCount* ColCount   ;

        typedef  Grid<Clock, RowCount, ColCount> _GridArray;
        typedef _GridArray::_Iterator _Iterator;

        Symbol(std::array<Clock,  ItemCount>&& clocks) noexcept: mSymbol (std::move(clocks))
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
