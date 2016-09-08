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
        typedef typename std::array<T ,ItemCount> GridArray;
        typedef typename GridArray::const_iterator GridCIterator;

        explicit Grid(std::array<T, ItemCount >&& items) noexcept: mGrid (std::move(items)) {}

        std::pair<GridCIterator ,GridCIterator> GetCIterators(int row)
        {
            assert(row < TRowCount || row>=0);
            auto begin = mGrid.cbegin() + (row * TColumnCount);
            auto end = begin + TColumnCount;
            return std::make_pair(begin, end);
        }



    private:
        GridArray mGrid;



    };

}
