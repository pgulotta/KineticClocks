#include "clocksymbols.hpp"
#include "symbol.hpp"
#include "clock.hpp"

#include <array>
#include <iterator>
#include <cassert>
#include <tuple>

std::array<Symbol,ClockSymbols::RowCount> gArray(
{
    Symbol({ //Zero
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(90,270),
        Clock(0,270),
        Clock(0,180),
        Clock(180,270),
        Clock(90,270),

        Clock(90,270),
        Clock(90,270),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),

        Clock(90,270),
        Clock(90,270),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),

        Clock(90,270),
        Clock(0,90),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180)
    }),
    Symbol({ //HorizontalLine
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180)
    })
});


std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  ClockSymbols::GetRow(SymbolName name, int row)
{
    return gArray[(int)name].GetIterators(row);
}
