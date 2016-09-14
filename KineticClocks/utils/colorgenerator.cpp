#include "colorgenerator.hpp"
#include <ctime>
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QDebug>


namespace twentysixapps
{
 std::array<QColor, ColorGenerator::BaseColorsSize> ColorGenerator::mBaseColors(
{
    QColor (255,128,0),
    QColor (128,255,64),
    QColor (64,128,255)
});

void ColorGenerator::generateOffsetColors()
{
    QColor baseColor{nextBaseColor()};

    for (int index = 0; index < OffsetColorsSize; index++)
        {
            mOffsetColors[index]   = QColor(
                                         colorComponentOffset(baseColor.red() ,mMaxRange),
                                         colorComponentOffset(baseColor.green() ,mMaxRange),
                                         colorComponentOffset(baseColor.blue(),mMaxRange));
            qDebug() << "index = " << index << "  red = " << mOffsetColors[index] .red() << "  green = " << mOffsetColors[index] .green() << "  blue = " << mOffsetColors[index] .blue();
        }
}

qreal ColorGenerator::randomNextDouble()
{
    return (qrand()/(RAND_MAX+1.0));
}

int ColorGenerator::colorComponentOffset(int colorComponenet, qreal maxRange)
{
    return   (int) (  floatToByte(  ( byteToFloat(colorComponenet )+  randomNextDouble() * 2  * maxRange  - maxRange) ));
}

int ColorGenerator::saturateByte(int byteValue)
{
    if (byteValue > 255)
        {
            byteValue = 255;
        }
    else if (byteValue < 0)
        {
            byteValue = 0;
        }
    return byteValue;
}

qreal ColorGenerator::byteToFloat(int byteValue)
{
    return byteValue / 256.0f;
}

int ColorGenerator::floatToByte(qreal value)
{
    int byteValue = (int)(value * 256);
    byteValue = saturateByte(byteValue);
    return byteValue;
}

int getRandomSign()
{
    return  qrand() % 2 == 0 ? 1 : -1;
}

ColorGenerator::ColorGenerator()
{
    qsrand(static_cast<uint>(time(0)));
    generateOffsetColors();
}

QColor ColorGenerator::nextOffsetColor()
{
    return mOffsetColors[qrand() % OffsetColorsSize];
}

QColor ColorGenerator::nextBaseColor()
{
    return mBaseColors[qrand() % BaseColorsSize];
}

}
