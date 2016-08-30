#pragma once

#include <QObject>
#include <QTime>

#include <array>


namespace twentysixapps
{
class ClockTime : public QObject
{
    Q_OBJECT


public:
    ClockTime (QTime displayTime,QObject *parent=0);
    QTime displayTime() const;
    void setDisplayTime(const QTime &displayTime);
    std::array<int, 5>::const_iterator digits() const;

signals:
    void displayTimeChanged();

public slots:


private:
    QTime mDisplayTime;
    std::array<int,5> mDigits;


    explicit ClockTime(const ClockTime& rhs) = delete;
    ClockTime& operator= (const ClockTime& rhs) = delete;
};
}
