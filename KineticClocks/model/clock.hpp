#pragma once

namespace twentysixapps
{
class Clock
{
public:
    const static int Angle1Default = 45;
    const static int Angle2Default = 225;

    Clock() = default;
    Clock(int angle1, int angle2) : Angle1 (angle1), Angle2 (angle2) {}
    const int Angle1{Angle1Default};
    const int Angle2 {Angle2Default};

private:

};

}
