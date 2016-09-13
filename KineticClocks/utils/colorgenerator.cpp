#include "colorgenerator.hpp"
#include <ctime>
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QDebug>


namespace twentysixapps
{
void ColorGenerator::generateOffsetColors()
{
    QColor baseColor{mBaseColors[mBaseArrayIndex]};

    for (int index = 0; index < OffsetColorsCount; index++)
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

void ColorGenerator::initialize()
{
    qsrand(static_cast<uint>(time(0)));

    mBaseColors[0] =  QColor (255,128,0);
    mBaseColors[1] =  QColor (128,255,64);
    mBaseColors[2] =  QColor (64,128,255);
    mBaseArrayIndex = qrand() %3;
}

ColorGenerator::ColorGenerator()
{
    initialize();
    generateOffsetColors();
}


}
