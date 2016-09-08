#pragma once

#include <QChar>
#include <memory>
#include <array>
#include <iterator>
#include "symbol.hpp"
#include "grid.hpp"

namespace twentysixapps
{

enum class SymbolName
{
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Colon,
    HorizontalLine
};

class ClockSymbols
{
public:
    typedef Symbol::ClocksArray::GridCIterator SymbolClocksCIterator;
    typedef  std::pair<SymbolClocksCIterator ,SymbolClocksCIterator>  Citerators;
    Citerators GetRow(SymbolName name, int row) ;
    static const int RowCount = (int)SymbolName::HorizontalLine +1;
    static SymbolName GetSymbolName(QChar symbol);
private:


};

}
