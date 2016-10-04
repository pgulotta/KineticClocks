
#pragma once
#include <QColor>
#include <array>



namespace twentysixapps
{
class ColorGenerator
{
public:
    static constexpr size_t BaseColorsSize = 3;
    using BaseArray =std::array<QColor, BaseColorsSize>;
    using BaseCIterator = BaseArray::const_iterator;

    static constexpr size_t OffsetColorsSize = 20;
    using OffsetArray = std::array<QColor, OffsetColorsSize>;
    using  OffsetCIterator = OffsetArray::const_iterator;

    ColorGenerator();
    QColor nextOffsetColor() const;
    static QColor nextBaseColor();

private:
    ColorGenerator(const ColorGenerator& rhs) = delete;
    ColorGenerator& operator= (const ColorGenerator& rhs) = delete;
    ColorGenerator(ColorGenerator&&) =delete;
    ColorGenerator& operator=(ColorGenerator&&) =delete;

    const qreal mMaxRange = 0.4f;

    static BaseArray mBaseColors;
    OffsetArray mOffsetColors;

    void generateOffsetColors();
    static int floatToByte(qreal value);
    static int saturateByte(int byteValue);
    static qreal byteToFloat(int byteValue);
    static qreal randomNextDouble();
    static int colorComponentOffset(int colorComponenet, qreal maxRange);



};
}
