#pragma once

#include "clocksymbols.hpp"
#include <QObject>
#include <QTime>

#include <array>


namespace twentysixapps
{
typedef std::array<SymbolName, 5>::const_iterator SymbolsIterator;

class ClockTime : public QObject
{
    Q_OBJECT


public:
    ClockTime ();
    ClockTime (const QTime& displayTime,QObject *parent=0);
    void setDisplayTime(const QTime& displayTime);
    SymbolsIterator symbols() const;

signals:
    void displayTimeChanged();

public slots:


private:
    std::array<SymbolName,5> mSymbols;

    explicit ClockTime(const ClockTime& rhs) = delete;
    ClockTime& operator= (const ClockTime& rhs) = delete;
};
}
