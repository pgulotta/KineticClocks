#pragma once

#include "clocksymbols.hpp"
#include <QObject>
#include <QTime>

#include <array>


namespace twentysixapps
{
static const int SymbolsPerDisplayTime = 5;
typedef std::array<SymbolName, SymbolsPerDisplayTime>::const_iterator SymbolsIterator;

class ClockTime : public QObject
{
    Q_OBJECT


public:


    ClockTime ();
    ClockTime (const QTime& displayTime,QObject *parent=0);
    void setDisplayTime(const QTime& displayTime);
    SymbolsIterator symbols() const;
    const QString& toString()
    {
        return mText;
    }
signals:

public slots:


private:
    std::array<SymbolName, SymbolsPerDisplayTime> mSymbols;
    QString mText;
    explicit ClockTime(const ClockTime& rhs) = delete;
    ClockTime& operator= (const ClockTime& rhs) = delete;
};
}
