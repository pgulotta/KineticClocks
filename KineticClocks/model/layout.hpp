#pragma once

#include <array>
#include <iterator>

namespace twentysixapps
{
    class Layout
    {
    public:
        static const  int Rows = 12;
        static const  int Columns = 24;
        static const int mClocksCount = RowCount* ColCount   ;


    private:
        QTime mDisplayTime;
        std::array<int,mClocksCount> mClocks;
    };

}
