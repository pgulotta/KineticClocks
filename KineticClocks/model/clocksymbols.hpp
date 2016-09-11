#pragma once

#include <QChar>

#include <array>
#include <iterator>
#include "symbol.hpp"


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
    typedef Symbol::Array::CIterator CIterator;
    typedef  std::pair<CIterator ,CIterator>  Citerators;

      static constexpr size_t RowCount = (size_t)SymbolName::HorizontalLine +1;

    Citerators getRow(SymbolName name, int row)  const;
    static   SymbolName getSymbolName(QChar symbol) ;


private:


};

}
