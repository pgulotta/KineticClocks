#pragma once

#include "clocksymbols.hpp"
#include <QObject>
#include <QTime>

#include <array>


namespace twentysixapps
{


class ClockTime : public QObject
{
    Q_OBJECT
public:
    static const int SymbolsPerDisplay = 5;
    typedef std::array<SymbolName, SymbolsPerDisplay> Array;
    typedef  Array::const_iterator  CIterator;

    ClockTime ();
    ClockTime (const QTime& displayTime,QObject *parent=0);
    void setDisplayTime(const QTime& displayTime);
    CIterator  symbols() const { return mSymbols.cbegin(); }

    const QString& toString()
    {
        return mText;
    }
signals:

public slots:


private:

    Array mSymbols;
    QString mText;
    explicit ClockTime(const ClockTime& rhs) = delete;
    ClockTime& operator= (const ClockTime& rhs) = delete;
};
}
