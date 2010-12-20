#include "colored_geometric_shape.h"
#include <QTextStream>
#include <QColor>

ColoredGeometricShape::ColoredGeometricShape(bool f, int r, int g, int b) :
                       red(cropValue(r)), green(cropValue(g)), blue(cropValue(b)), filled(f), null(false)
{
}

ColoredGeometricShape::ColoredGeometricShape() :
                       red(0), green(0), blue(0), filled(false), null(true)
{
}

bool ColoredGeometricShape::isNull() const
{
    return this->null;
}

int ColoredGeometricShape::getRed() const
{
    return this->red;
}

int ColoredGeometricShape::getGreen() const
{
    return this->green;
}

int ColoredGeometricShape::getBlue() const
{
    return this->blue;
}

bool ColoredGeometricShape::isFilled() const
{
    return this->filled;
}

QString ColoredGeometricShape::getColorAsHex() const
{
    QColor color(this->red, this->green, this->blue);
    return color.name().remove(QString("#"));
}

bool ColoredGeometricShape::operator==(const ColoredGeometricShape &other) const
{
    return this->red == other.red &&
           this->green == other.green &&
           this->blue == other.blue &&
           this->filled == other.filled;
}

bool ColoredGeometricShape::operator!=(const ColoredGeometricShape &other) const
{
    return !(*this == other);
}

const QString ColoredGeometricShape::toString() const
{
    QString repr;
    QTextStream stream(&repr);

    if (this->isNull()) {
        return QString("ColoredGeometricShape: NULL !!!");
    }

    stream << "ColoredGeometricShape: ";
    stream << "red[" << this->red << "] ";
    stream << "green[" << this->green << "] ";
    stream << "blue[" << this->blue << "] ";
    stream << "filled[" << this->filled << "]\n";

    return  repr;
}

int ColoredGeometricShape::cropValue(int val) const
{
    if (val > 255) {
        return 255;
    }
    if (val < 0) {
        return 0;
    }
    return val;
}
