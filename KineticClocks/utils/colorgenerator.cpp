#include "colorgenerator.hpp"
#include <ctime>
#include <QDebug>
#include <QTimer>
#include <QColor>

namespace twentysixapps
{
    ColorGenerator::ColorGenerator()
    {
    }

    void ColorGenerator::initialize()
    {
    qsrand(static_cast<uint>(time(0)));
    }
}
