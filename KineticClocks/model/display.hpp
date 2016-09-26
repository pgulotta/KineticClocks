#pragma once

#include "clocktime.hpp"


namespace twentysixapps
{
template<typename T, size_t TSymbolsCount>
class Display
{
public:
    using Array = std::array<SymbolName, TSymbolsCount>;
    using CIterator =  typename Array::const_iterator;

    Display( const T&& t) : mDisplay( std::move(t))
    {
    }

    void update()
    {
        mDisplay.updateDisplayTime();
    }

    SymbolName  getSymbolName(size_t colIndex) const
    {
        return mDisplay.getSymbols()[colIndex];
    }

    const QString& toString() const
    {
        return mDisplay.toString();
    }

private:
    T mDisplay;

};

class DisplayAdapter
{
public:
    virtual void update() = 0;

    virtual SymbolName  getSymbolName(size_t colIndex) const = 0;

    virtual const QString& toString() const = 0;


};

class TimeDisplayAdapter : public DisplayAdapter
{
public:

    TimeDisplayAdapter( ) : mDisplayClockTime(ClockTime {
        }) {}

    virtual void update()
    {
        mDisplayClockTime.update();
    }

    virtual SymbolName  getSymbolName(size_t colIndex) const
    {
        return mDisplayClockTime.getSymbolName(colIndex);
    }

    virtual const QString& toString() const
    {
        return mDisplayClockTime.toString();
    }

private:
    Display<ClockTime, ClockTime::SymbolsCount> mDisplayClockTime;


};

}
