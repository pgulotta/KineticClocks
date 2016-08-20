#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <array>
#include <iterator>


class Layout
{
public:
    static const  int Rows = 12;
    static const  int Columns = 24;
    static const int mClocksCount = RowCount* ColCount   ;


private:
    std::array<int,mClocksCount> mClocks;
};

#endif // LAYOUT_HPP
