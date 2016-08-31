#include "clocksymbols.hpp"
#include "symbol.hpp"
#include "clock.hpp"

#include <array>
#include <iterator>
#include <cassert>
#include <tuple>

namespace twentysixapps
{
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
    Symbol({ //One
        Clock(0,180),
        Clock(0,270),
        Clock(0,180),
        Clock(180,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,90),
        Clock(180,270),
        Clock(90,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,90),
        Clock(90,180),
        Clock(0,180)
    }),
    Symbol({ //Two
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),
        Clock(90,270),

        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(90,270),
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),

        Clock(90,270),
        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180)
    }),
    Symbol({ //Three
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),
        Clock(90,270),

        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),
        Clock(90,270),

        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180)
    }),
    Symbol({ //Four
        Clock(0,270),
        Clock(180,270),
        Clock(0,180),
        Clock(0,270),
        Clock(180,270),

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
        Clock(180,270),
        Clock(90,270),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,90),
        Clock(90,180)
    }),
    Symbol({ //Five
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(90,270),
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),

        Clock(90,270),
        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),
        Clock(90,270),

        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180)
    }),
    Symbol({ //Six
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(90,270),
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),

        Clock(90,270),
        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(90,270),
        Clock(0,270),
        Clock(0,180),
        Clock(180,270),
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
    Symbol({ //Seven
        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,225),
        Clock(90,225),

        Clock(0,180),
        Clock(0,180),
        Clock(45,270),
        Clock(45,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(90,270),
        Clock(90,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,90),
        Clock(180,90),
        Clock(0,180)
    }),
    Symbol({ //Eight
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
        Clock(0,90),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(90,270),
        Clock(0,270),
        Clock(0,180),
        Clock(180,270),
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
    Symbol({ //Nine
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
        Clock(0,90),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(180,270),
        Clock(90,270),

        Clock(0,270),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180),
        Clock(90,270),

        Clock(0,90),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(90,180)
    }),
    Symbol({ //Colon
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,270),
        Clock(0,180),
        Clock(180,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,90),
        Clock(0,180),
        Clock(90,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,270),
        Clock(0,180),
        Clock(180,270),
        Clock(0,180),

        Clock(0,180),
        Clock(0,90),
        Clock(0,180),
        Clock(90,180),
        Clock(0,180),

        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180),
        Clock(0,180)
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


SymbolName ClockSymbols::GetSymbolName(QChar symbol)
{
    SymbolName name = SymbolName::Colon;
    if ( symbol.isDigit())
    {
    switch (symbol.digitValue())
        {
        case 0:
            name = SymbolName::Zero;
            break;
        case 1:
            name = SymbolName::One;
            break;
        case 2:
            name = SymbolName::Two;
            break;
        case 3:
            name = SymbolName::Three;
            break;
        case 4:
            name = SymbolName::Four;
            break;
        case 5:
            name = SymbolName::Five;
            break;
        case 6:
            name = SymbolName::Six;
            break;
        case 7:
            name = SymbolName::Seven;
            break;
        case 8:
            name = SymbolName::Eight;
            break;
        case 9:
            name = SymbolName::Nine;
            break;

        default:
            assert(false); // undefined char symbol
            break;
        }
}
    return name;
}

std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  ClockSymbols::GetRow(SymbolName name, int row)
{
    return gArray[(int)name].GetIterators(row);
}

}
