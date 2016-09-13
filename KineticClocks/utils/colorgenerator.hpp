
#pragma once
#include <QColor>
#include <array>



namespace twentysixapps
{
class ColorGenerator
{
public:
    static constexpr size_t BaseColorsCount = 3;
    typedef std::array<QColor, BaseColorsCount> BaseArray;
    typedef  BaseArray::const_iterator  BaseCIterator;

    static constexpr size_t OffsetColorsCount = 20;
    typedef std::array<QColor, OffsetColorsCount> OffsetArray;
    typedef  OffsetArray::const_iterator  OffsetCIterator;

    ColorGenerator() ;
    QColor nextOffsetColor()  ;
    static QColor nextBaseColor();

private:
    explicit ColorGenerator(const ColorGenerator& rhs) = delete;
    ColorGenerator& operator= (const ColorGenerator& rhs) = delete;
    ColorGenerator(ColorGenerator&&) =delete;
    ColorGenerator& operator=(ColorGenerator&&) =delete;

    const  qreal mMaxRange = 0.4f;

    static  BaseArray mBaseColors;
    static int  mBaseArrayIndex;
    OffsetArray mOffsetColors;
    int mOffsetArrayIndex{0};

    void generateOffsetColors();
    int floatToByte(qreal value);
    int saturateByte(int byteValue);
    qreal byteToFloat(int byteValue);
    qreal randomNextDouble();
    int colorComponentOffset(int colorComponenet, qreal maxRange);



};
}
