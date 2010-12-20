#include "object3d.h"
#include <QTextStream>

Object3D::Object3D(const QList<Wire>& wires_list, bool fill, int red, int green, int blue) :
          ColoredGeometricShape(fill, red, green, blue),
          wires(wires_list)
{
}

Object3D::Object3D(const QList<Wire>& wires_list, int red, int green, int blue) :
          ColoredGeometricShape(false, red, green, blue),
          wires(wires_list)
{
}

Object3D::Object3D(const QList<Point>& points, bool fill, int red, int green, int blue):
          ColoredGeometricShape(fill, red, green, blue)
{
    for (int i = 1; i < points.size(); i++) {
        this->wires.append(Wire(points[i - 1], points[i]));
    }
}

Object3D::Object3D() : ColoredGeometricShape()
{

}

const QList<Wire>& Object3D::getWires() const
{
    return this->wires;
}

bool Object3D::operator==(const Object3D &other) const
{
    if(this->wires.size() != other.wires.size()){
        return false;
    }

    for(int i = 0; i < this->wires.size(); i++){
        if(!other.wires.contains(this->wires[i])){
            return false;
        }
        if(!this->wires.contains(other.wires[i])){
            return false;
        }
    }

    return ColoredGeometricShape::operator ==(other);
}

Point Object3D::getCenter() const
{
    double x(0.0);
    double y(0.0);
    double n = this->wires.size() * 2;

    for(int i = 0; i < this->wires.size(); i++) {
        x += wires[i].getFirstPoint().getX() + wires[i].getSecondPoint().getX();
        y += wires[i].getFirstPoint().getY() + wires[i].getSecondPoint().getY();
    }

    return Point(x/n, y/n);
}

QString Object3D::toXML() const
{
    QString xmlRepr;
    QString wires;

    QTextStream stream(&xmlRepr);
    QTextStream wiresStream(&wires);

    QString internalTab = this->getTab() + this->getTab() + this->getTab();
    QList<Point> visitedPoints;

    stream << " cor=\"" << this->getColorAsHex() << "\">\n";

    stream << this->getTab() << this->getTab() << "<pontos>\n";

    for (int i = 0; i < this->wires.size(); i++) {
        Point firstPoint = this->wires[i].getFirstPoint();
        Point secondPoint = this->wires[i].getSecondPoint();

        if (!visitedPoints.contains(firstPoint)) {
            stream << internalTab << "<" << firstPoint.getTagName()  << firstPoint.toXMLColorless();
            visitedPoints.append(firstPoint);
        }
        if (!visitedPoints.contains(secondPoint)) {
            stream << internalTab << "<" << secondPoint.getTagName() << secondPoint.toXMLColorless();
            visitedPoints.append(secondPoint);
        }

        wiresStream << internalTab << "<aresta" << " v1=\"" << QString().setNum(visitedPoints.indexOf(firstPoint)) << "\""
                                                 << " v2=\"" << QString().setNum(visitedPoints.indexOf(secondPoint)) << "\"" << "/>\n";

    }
    stream << this->getTab() << this->getTab() << "</pontos>\n";

    stream << this->getTab() << this->getTab() << "<arestas>\n";
    stream << wires;
    stream << this->getTab() << this->getTab() << "</arestas>\n";

    stream << this->getTab() << "</" << this->getTagName() << ">\n";

    return xmlRepr;
}


QString Object3D::getTagName() const
{
    return QString("objeto3d");
}

const QString Object3D::toString() const
{
    QString Object3DRepr;
    QTextStream stream(&Object3DRepr);

    stream << "Object3D: \n";
    for (int i = 0; i< this->wires.size(); i++) {
        stream << this->wires[i].toString();
    }

    return ColoredGeometricShape::toString() + Object3DRepr;
}

bool Object3D::operator!=(const Object3D &other) const
{
    return !(*this == other);
}
