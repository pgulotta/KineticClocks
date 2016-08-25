#pragma once

#include <array>
#include <iterator>
#include <cassert>
#include <tuple>

namespace twentysixapps
{
    template<typename T,int TRowCount , int TColumnCount>
    class Grid
    {
    public:
        static const int ItemCount = TRowCount*TColumnCount;
        typedef typename std::array<T ,ItemCount> _Grid;
        typedef typename _Grid::const_iterator _Iterator;

        // Grid() : mGrid ( std::array<T ,ItemCount>) {}

        explicit Grid(std::array<T, ItemCount >&& items) noexcept: mGrid (std::move(items)) {}

        std::tuple<_Iterator ,_Iterator> GetIterators(int row)
        {
            assert(row < TRowCount || row>=0);
            auto begin = mGrid.cbegin() + (row * TColumnCount);
            auto end = begin + TColumnCount;
            return std::make_tuple(begin, end);
        }



    private:
        _Grid mGrid;



    };

}
