#pragma once

#include "symbol.hpp"
#include <QChar>
#include <array>
#include <iterator>



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

    Citerators getRow(SymbolName name, size_t row)  const;
    static   SymbolName getSymbolName(QChar symbol) ;


private:


};

}
