#include <QtTest>
#include <QString>
#include <QDebug>
#include <memory>
#include <tuple>
#include <iterator>
#include "..\KineticClocks\engine\clock.hpp"
#include "..\KineticClocks\engine\symbol.hpp"
#include "..\KineticClocks\engine\clocksymbols.hpp"


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
    QVERIFY2(c.Angle1 == 0, "Failure");
    QVERIFY2(c.Angle2 == 180, "Failure");
    \
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
    std::tuple<Symbol::_Iterator ,Symbol::_Iterator>  tuple =  s.GetIterators(5);
    auto first =  std::get<0>(tuple);
    QVERIFY2(first[4].Angle2 == 88, "Failure");
}
void TestKineticClocks::TestClockSymbols()
{
    ClockSymbols cs;
    std::tuple<ClockSymbols::_Iterator ,ClockSymbols::_Iterator>  tuple =  cs.GetRow(SymbolName::Zero,1);
    auto first =  std::get<0>(tuple);
    auto last =  std::get<1>(tuple);
    QVERIFY2(first[0].Angle1 == 90, "Failure");
    std::for_each(first, last, [](const Clock &clock)
    {
        qDebug() << "angle1=" << clock.Angle1 << "  angle2=" << clock.Angle2;
    });
}

QTEST_APPLESS_MAIN(TestKineticClocks)

#include "testkineticclocks.moc"
