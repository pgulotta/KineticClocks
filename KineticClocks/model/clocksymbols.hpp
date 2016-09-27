#pragma once

#include "symbol.hpp"
#include <QChar>
#include <array>
#include <iterator>



namespace twentysixapps
{

enum class SymbolName : size_t
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
    static constexpr size_t RowCount = (size_t)SymbolName::HorizontalLine +1;

    using Array = std::array<Symbol,ClockSymbols::RowCount>;
    using CIterator =  Symbol::Array::CIterator;
    using Citerators =  std::pair<CIterator,CIterator>;

    Citerators getRow(SymbolName name, size_t row)  const;
    static SymbolName getSymbolName(QChar symbol);

private:


};

}
