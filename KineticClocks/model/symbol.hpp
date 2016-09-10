#pragma once

#include <array>
#include <iterator>
#include <cassert>
#include <tuple>

#include "clock.hpp"
#include "grid.hpp"

namespace twentysixapps
{
    class Symbol
    {
    public:
        static const size_t RowsPerSymbol = 6;
        static const size_t ColsPerSymbol = 5;
        static const size_t ItemsPerSymbolCount = RowsPerSymbol* ColsPerSymbol   ;

        typedef  Grid<Clock, RowsPerSymbol, ColsPerSymbol> Array;
        typedef Array::CIterator CIterator;

        Symbol(std::array<Clock,  ItemsPerSymbolCount>&& clocks) noexcept: mSymbolClocks (std::move(clocks))
        {
        }


       std::pair<CIterator ,CIterator> getCIterators(int row)
        {
            return mSymbolClocks.getCIterators(row);
        }


    private:
        Array mSymbolClocks;

    };


}
