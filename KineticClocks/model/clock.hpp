#pragma once

namespace twentysixapps
{
class Clock
{
public:
    const static int AngleDefault = 45;

    Clock() = default;
    Clock(int angle1, int angle2) : Angle1 (angle1), Angle2 (angle2) {}
    const int Angle1{AngleDefault};
    const int Angle2 {AngleDefault};

private:

};

}
