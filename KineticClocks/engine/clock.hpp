#ifndef CLOCK_HPP
#define CLOCK_HPP

class Clock
{
public:
    Clock() = default;
    Clock(int angle1, int angle2) : Angle1 (angle1), Angle2 (angle2) {}
    const int Angle1{0};
    const int Angle2 {180};

private:

};

#endif // CLOCK_HPP
