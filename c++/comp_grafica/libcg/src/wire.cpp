#include "wire.h"
#include <QTextStream>

Wire::Wire(const Point& point1, const Point& point2, int red, int green, int blue) :
        ColoredGeometricShape(false, red, green, blue),
        first_point(point1), second_point(point2), isNull(false)
{
}

Wire::Wire() : ColoredGeometricShape(false, 0, 0, 0), isNull(true)
{
}

const Point& Wire::getFirstPoint() const
{
    return this->first_point;
}

const Point& Wire::getSecondPoint() const
{
    return this->second_point;
}

bool Wire::operator==(const Wire &other) const
{
    if(this->first_point == other.first_point){
        return (this->second_point == other.second_point) && ColoredGeometricShape::operator ==(other);
    }

    if(this->first_point == other.second_point){
        return (this->second_point == other.first_point) && ColoredGeometricShape::operator ==(other);
    }

    return false;
}

Point Wire::getCenter() const
{
    double x = (this->first_point.getX() + this->second_point.getX()) / 2.0;
    double y = (this->first_point.getY() + this->second_point.getY()) / 2.0;
    return Point(x,y);
}

bool Wire::operator!=(const Wire &other) const
{
    return !(*this == other);
}

const QString Wire::toString () const
{
    QString wire_repr;
    QTextStream stream(&wire_repr);

    stream << "wire: point 1: [" << this->first_point.toString() << "] ";
    stream << "point 2: [ " << this->second_point.toString() << " ]\n";

    return wire_repr;
}

QString Wire::toXML() const
{
    QString xml_repr;
    QTextStream stream(&xml_repr);

    stream << " cor=\"" << this->getColorAsHex() << "\">\n";
    stream << this->getTab() << this->getTab() << "<" << this->first_point.getTagName() << this->first_point.toXMLColorless();
    stream << this->getTab() << this->getTab() << "<" << this->second_point.getTagName() << this->second_point.toXMLColorless();
    stream << this->getTab() << "</" << this->getTagName() << ">\n";

    return xml_repr;
}


QString Wire::getTagName() const
{
    return QString("reta");
}
