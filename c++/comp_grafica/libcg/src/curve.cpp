#include "curve.h"
#include <QTextStream>

Curve::Curve(int red , int green, int blue) : ColoredGeometricShape(false, red, green, blue)
{

}

Curve::Curve() : ColoredGeometricShape()
{

}

Curve::Curve(const QList<Wire>& w, int red, int green, int blue, const QString& repr) : ColoredGeometricShape(false, red, green, blue), wires(w), curve_repr(repr)
{
}

Point Curve::getCenter() const
{
    return Wire(this->wires[0].getFirstPoint(), this->wires[this->wires.size() - 1].getSecondPoint()).getCenter();
}

const QList<Wire>& Curve::getWires() const
{
    return this->wires;
}

bool Curve::operator==(const Curve &other) const
{
    if (this->wires.size() != other.wires.size()) {
        return false;
    }

    for (int i = 0; i < this->wires.size(); i++) {
        if (!this->wires.contains(other.wires[i]) ||
            !other.wires.contains(this->wires[i])) {
            return false;
        }
    }

    return ColoredGeometricShape::operator==(other);
}

bool Curve::operator!=(const Curve &other) const
{
    return !(*this == other);
}

const QString Curve::toString () const
{
    return this->curve_repr;
}

QString Curve::toXML() const
{
    return this->xmlStart + this->xmlBody + this->getTab() + this->xmlEnd;
}


QString Curve::getTagName() const
{
    return this->tagName;
}

Curve Curve::getContinuosCurveXML(const QList<Curve>& curves)
{
    Curve curve(0,0,0);
    QTextStream stream(&curve.xmlBody);
    QString internalTab = curve.getTab() + curve.getTab();

    if (curves.size() == 0) {
        return Curve();
    }
    curve.tagName  = curves[0].tagName;
    curve.xmlStart = curves[0].xmlStart;
    curve.xmlEnd   = curves[0].xmlEnd;

    for (int i=0; i < curves.size(); i++) {
        stream << curves[i].xmlBody;
    }

    return curve;
}
