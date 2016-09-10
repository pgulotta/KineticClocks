#include <QtTest>
#include <QString>
#include <QDebug>
#include <memory>
#include <tuple>
#include <iterator>
#include "..\KineticClocks\model\clock.hpp"
#include "..\KineticClocks\model\symbol.hpp"
#include "..\KineticClocks\model\clocksymbols.hpp"
#include "..\KineticClocks\model\clocktime.hpp"
#include "..\KineticClocks\model\display.hpp"


using namespace twentysixapps;

class TestKineticClocks : public QObject
{
    Q_OBJECT

public:
    TestKineticClocks();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void TestCreateClock();
    void TestCreateSymbol();
    void TestClockSymbols();
    void TestClockTime1();
    void TestClockTime2();

};

TestKineticClocks::TestKineticClocks()
{
}

void TestKineticClocks::initTestCase()
{
}

void TestKineticClocks::cleanupTestCase()
{
}

void TestKineticClocks::TestCreateClock()
{
    Clock c;
    QVERIFY2(c.getAngle1() == Clock::Angle1Default, "Failure");
    QVERIFY2(c.getAngle2() == Clock::Angle2Default, "Failure");
}

void TestKineticClocks::TestCreateSymbol()
{
    Symbol s(
    {
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
        Clock(90,88)
    });
    std::pair<Symbol::CIterator ,Symbol::CIterator>  pair =  s.getCIterators(5);
    auto first =  std::get<0>(pair);
    QVERIFY2(first[4].getAngle2() == 88, "Failure");
}
void TestKineticClocks::TestClockSymbols()
{
    ClockSymbols cs;
    ClockSymbols::Citerators  pair =  cs.getRow(SymbolName::Zero,1);
    auto first =  std::get<0>(pair);
    auto last =  std::get<1>(pair);
    QVERIFY2(first[0].getAngle1() == 90, "Failure");
    std::for_each(first, last, [](const Clock &clock)
    {
        qDebug() << "angle1=" << clock.getAngle1() << "  angle2=" << clock.getAngle2();
    });
}
void TestKineticClocks::TestClockTime1()
{
    QTime time;
    time.setHMS(12, 34, 0);
    qDebug() << "Time: " << time.toString();
    Display<ClockTime,  ClockTime::SymbolsCount>  ct{ClockTime {time}};
    auto symbols = ct.getSymbols();

    QVERIFY2(symbols[0] == SymbolName::One, "Failure != 1");
    QVERIFY2(symbols[1] == SymbolName::Two, "Failure != 2");
    QVERIFY2(symbols[2] == SymbolName::Colon, "Failure != :");
    QVERIFY2(symbols[3] == SymbolName::Three, "Failure != 3");
    QVERIFY2(symbols[4] == SymbolName::Four, "Failure != 4");

    QVERIFY2(symbols[0] != SymbolName::Zero, "Failure != 0");
    QVERIFY2(symbols[1] != SymbolName::Zero, "Failure != 0");
    QVERIFY2(symbols[3] != SymbolName::Zero, "Failure != 0");
    QVERIFY2(symbols[4] != SymbolName::Zero, "Failure != 0");
}

void TestKineticClocks::TestClockTime2()
{
    QTime time;
    time.setHMS(00, 00, 0);
    qDebug() << "Time: " << time.toString();

    Display<ClockTime, ClockTime::SymbolsCount > display( ClockTime {time} );
    auto symbols =display.getSymbols();

    QVERIFY2(symbols[0] == SymbolName::Zero, "Failure != 0");
    QVERIFY2(symbols[1] == SymbolName::Zero, "Failure != 0");
    QVERIFY2(symbols[2] == SymbolName::Colon, "Failure != :");
    QVERIFY2(symbols[3] == SymbolName::Zero, "Failure != 0");
    QVERIFY2(symbols[4] == SymbolName::Zero, "Failure != 0");

/*
    Display<ClockTime, 5 > displayNow{ClockTime{}} ;
    auto currentTimeSymbols =displayNow.symbols();
    QVERIFY2(currentTimeSymbols[0] == SymbolName::One, "Failure");
    QVERIFY2(currentTimeSymbols[1] == SymbolName::Eight, "Failure");
    QVERIFY2(currentTimeSymbols[2] == SymbolName::Colon, "Failure");
    QVERIFY2(currentTimeSymbols[3] == SymbolName::One, "Failure");
    QVERIFY2(currentTimeSymbols[4] == SymbolName::Eight, "Failure");
*/
}
QTEST_APPLESS_MAIN(TestKineticClocks)

#include "testkineticclocks.moc"
