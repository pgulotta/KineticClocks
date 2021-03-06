#pragma once

#include <array>
#include <iterator>
#include <tuple>
#include "clock.hpp"
#include "grid.hpp"

namespace twentysixapps
{
class Symbol final
{
public:
    static constexpr size_t RowsPerSymbol = 6;
    static constexpr size_t ColsPerSymbol = 5;
    static constexpr size_t ItemsPerSymbolCount = RowsPerSymbol* ColsPerSymbol;

    using Array = Grid<Clock, RowsPerSymbol, ColsPerSymbol>;
    using CIterator= Array::CIterator;

    Symbol(std::array<Clock,  ItemsPerSymbolCount>&& clocks) noexcept : mSymbolClocks (std::move(clocks))
    {
    }

    std::pair<CIterator,CIterator> getCIterators(int row) const
    {
        return mSymbolClocks.getCIterators(row);
    }

private:
    Array mSymbolClocks;

};


}
