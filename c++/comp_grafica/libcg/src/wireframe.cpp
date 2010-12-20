#include "wireframe.h"
#include <QTextStream>

WireFrame::WireFrame(const QList<Wire>& wires_list, bool fill, int red, int green, int blue) :
        Object3D(wires_list, fill, red, green, blue)
{
}

WireFrame::WireFrame(const Object3D& obj) : Object3D(obj)
{
    /* Workaround to not have to remake the entire system to add object3D (clipping, transforming, etc).
       This constructor does not check if it is a closed polygon !!
       Wireframe should be renamed to Polygon, but that would require too much time :-( (tight schedule) */
}

WireFrame::WireFrame() : Object3D()
{
}

WireFrame::WireFrame(const QList<Point>& points, bool fill, int red, int green, int blue) :
           Object3D(points, fill, red, green, blue)
{
    this->wires.append(Wire(points[points.size() - 1], points[0]));
}

bool WireFrame::isAClosedPolygon() const
{
    for(int i = 0; i < this->wires.size() - 1; i++){
        if(!this->checkIfWiresAreConnected(this->wires[i], this->wires[i + 1])){
            return false;
        }
    }

    if(!this->checkIfWiresAreConnected(this->wires[this->wires.size() - 1], this->wires[0])){
        return false;
    }

    return true;
}

bool WireFrame::checkIfWiresAreConnected(const Wire& wire1, const Wire& wire2) const
{
    bool check1 = wire1.getFirstPoint() == wire2.getFirstPoint();
    bool check2 = wire1.getFirstPoint() == wire2.getSecondPoint();
    bool check3 = wire1.getSecondPoint() == wire2.getFirstPoint();
    bool check4 = wire1.getSecondPoint() == wire2.getSecondPoint();

    return check1 || check2 || check3 || check4;
}

QString WireFrame::toXML() const
{
    QString xmlRepr;
    QTextStream stream(&xmlRepr);
    QString internalTab = this->getTab() + this->getTab();
    QString cheioStr = this->isFilled() ? "verdadeiro" : "falso";

    if (!this->isAClosedPolygon()) {
        /* another workaround */
        return Object3D::toXML();
    }

    stream << " cor=\"" << this->getColorAsHex() << "\" cheio=\"" << cheioStr << "\">\n";

    for (int i = 0; i < this->wires.size(); i++) {
        Point firstPoint = this->wires[i].getFirstPoint();
        Point secondPoint = this->wires[i].getSecondPoint();
        stream << internalTab << "<" << firstPoint.getTagName()  << firstPoint.toXMLColorless();
        stream << internalTab << "<" << secondPoint.getTagName() << secondPoint.toXMLColorless();
    }

    stream << this->getTab() << "</" << this->getTagName() << ">\n";

    return xmlRepr;
}


QString WireFrame::getTagName() const
{
    if (!this->isAClosedPolygon()) {
        return QString("objeto3d");
    }
    return QString("poligono");
}


