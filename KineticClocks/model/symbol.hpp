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

        typedef  Grid<Clock, RowsPerSymbol, ColsPerSymbol> ClocksArray;
        typedef ClocksArray::GridCIterator ClocksIterator;

        Symbol(std::array<Clock,  ItemsPerSymbolCount>&& clocks) noexcept: mSymbolClocks (std::move(clocks))
        {
        }


        std::pair<ClocksArray::GridCIterator ,ClocksArray::GridCIterator> GetCIterators(int row)
        {
            return mSymbolClocks.GetCIterators(row);
        }


    private:
        ClocksArray mSymbolClocks;

    };


}
