
#pragma once
#include <QColor>

namespace twentysixapps
{
class ColorGenerator
{
public:
    ColorGenerator();
    static void initialize();

private:


    QColor mBaseColor  = Qt::GlobalColor::white;

    explicit ColorGenerator(const ColorGenerator& rhs) = delete;
    ColorGenerator& operator= (const ColorGenerator& rhs) = delete;
    ColorGenerator(ColorGenerator&&) =delete;
    ColorGenerator& operator=(ColorGenerator&&) =delete;
};
}

