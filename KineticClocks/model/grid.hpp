#pragma once

#include <array>
#include <iterator>
#include <tuple>
#include <cassert>

namespace twentysixapps
{
template<typename T,int TRowCount , int TColumnCount>
class Grid
{
public:
    static constexpr size_t ItemCount = TRowCount*TColumnCount;
    typedef typename std::array<T ,ItemCount> Array;
    typedef typename Array::const_iterator CIterator;

    explicit Grid(Array && items) noexcept: mGrid (std::move(items)) {}

    std::pair<CIterator ,CIterator> getCIterators(int row) const
    {
        assert(row < TRowCount || row>=0);
        auto begin = mGrid.cbegin() + (row * TColumnCount);
        auto end = begin + TColumnCount;
        return std::make_pair(begin, end);
    }

private:
    Array mGrid;



};

}
