#pragma once

namespace twentysixapps
{
class Clock
{
public:
    constexpr static int Angle1Default = 45;
    constexpr static int Angle2Default = 225;
    constexpr static int  AnglesPerClock = 2;

    Clock() = default;
    Clock(int angle1, int angle2) : mAngle1 (angle1), mAngle2 (angle2) {}

    constexpr   int angle1() const
    {
        return mAngle1;
    }

    constexpr  int angle2() const
    {
        return mAngle2;
    }

private:
    const int mAngle1 {Angle1Default };
    const int mAngle2 {Angle2Default};


};

}
