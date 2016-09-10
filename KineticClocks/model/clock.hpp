#pragma once

namespace twentysixapps
{
class Clock
{
public:
    const static int Angle1Default = 45;
    const static int Angle2Default = 225;
    const static int  AnglesPerClock = 2;

    Clock() = default;
    Clock(int angle1, int angle2) : mAngle1 (angle1), mAngle2 (angle2) {}

    int getAngle1() const
    {
        return mAngle1;
    }

    int getAngle2() const
    {
        return mAngle2;
    }

private:
    const int mAngle1 {Angle1Default};
    const int mAngle2 {Angle2Default};


};

}
