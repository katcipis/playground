#include "window.h"
#include "matrix.h"
#include "transform.h"
#include <QTextStream>
#include <iostream>

Window::Window(double h, double w) : height(h), width(w), vUpAngleWithY(0.0),vpnAngleWithX(0.0),vpnAngleWithY(0.0),zoomFactor(1.0)
{
}

Point Window::getMaxPoint() const
{
    double x = this->getCenter().getX() + (this->width / 2.0);
    double y = this->getCenter().getY() + (this->height / 2.0);
    return Point(x,y);
}

void Window::rotateAroundY(double angle)
{
    this->vpnAngleWithY += angle;
    this->refresh();
}

void Window::rotateAroundX(double angle)
{
    this->vpnAngleWithX += angle;
    this->refresh();
}

void Window::clear()
{
    this->points.clear();
    this->curves.clear();
    this->wires.clear();
    this->wireframes.clear();
}

void Window::rotateAroundZ(double angle)
{
    this->vUpAngleWithY += angle;
    this->refresh();
}

Point Window::getMinPoint() const
{
    double x = this->getCenter().getX() - (this->width / 2.0);
    double y = this->getCenter().getY() - (this->height / 2.0);
    return Point(x,y);
}

void Window::translateRight(double points)
{
    this->setCenter(this->adjustMovementVector(Wire(this->getCenter(),
                                                    Point(this->getCenter().getX() + points, this->getCenter().getY(), this->getCenter().getZ()))).getSecondPoint());
    this->refresh();
}

void Window::translateLeft(double points)
{
    this->setCenter(this->adjustMovementVector(Wire(this->getCenter(),
                                                    Point(this->getCenter().getX() - points, this->getCenter().getY(), this->getCenter().getZ()))).getSecondPoint());
    this->refresh();
}

void Window::translateDown(double points)
{
    this->setCenter(this->adjustMovementVector(Wire(this->getCenter(),
                                                    Point(this->getCenter().getX(), this->getCenter().getY() - points, this->getCenter().getZ()))).getSecondPoint());
    this->refresh();
}

void Window::translateUp(double points)
{
    this->setCenter(this->adjustMovementVector(Wire(this->getCenter(),
                                                    Point(this->getCenter().getX(), this->getCenter().getY() + points, this->getCenter().getZ()))).getSecondPoint());
    this->refresh();
}

void Window::translateIn(double points)
{
    this->setCenter(this->adjustMovementVector(Wire(this->getCenter(),
                                                    Point(this->getCenter().getX(), this->getCenter().getY(), this->getCenter().getZ() - points))).getSecondPoint());
    this->refresh();
}

void Window::translateOut(double points)
{
    this->setCenter(this->adjustMovementVector(Wire(this->getCenter(),
                                                    Point(this->getCenter().getX(), this->getCenter().getY(), this->getCenter().getZ() + points))).getSecondPoint());
    this->refresh();
}

void Window::zoomPlus()
{
    this->zoomFactor = this->zoomFactor * 1.1;
    this->setHeight(this->height);
    this->setWidth(this->width);
}

void Window::zoomMinus()
{
    this->zoomFactor = this->zoomFactor * 0.9;
    this->setHeight(this->height);
    this->setWidth(this->width);
}

int Window::getPointsCount() const
{
    return this->points.size();
}

int Window::getWiresCount() const
{
    return this->wires.size();
}

void Window::insertCurve(const Curve& curve)
{
    return this->curves.append(curve);
}

void Window::removeCurve(const Curve& curve)
{
    this->curves.removeOne(curve);
    this->refresh();
}

const QList<Curve>& Window::getCurves() const
{
    return this->curves;
}

int Window::getWireFramesCount() const
{
    return this->wireframes.size();
}

int Window::getCurvesCount() const
{
    return this->curves.size();
}

void Window::insertPoint(const Point& point)
{
    this->points.append(point);
    this->refresh();
}

void Window::insertWire(const Wire& wire)
{
    this->wires.append(wire);
    this->refresh();
}

void Window::insertWireFrame(const WireFrame& wireframe)
{
    this->wireframes.append(wireframe);
    this->refresh();
}

void Window::removePoint(const Point& point)
{
    this->points.removeOne(point);
    this->refresh();
}

void Window::removeWire(const Wire& wire)
{
    this->wires.removeOne(wire);
    this->refresh();
}

void Window::removeWireFrame(const WireFrame& wireframe)
{
    this->wireframes.removeOne(wireframe);
    this->refresh();
}

const QList<WireFrame>& Window::getWireFrames() const
{
    return this->wireframes;
}

const QList<Wire>& Window::getWires() const
{
    return this->wires;
}

const QList<Point>& Window::getPoints() const
{
    return this->points;
}

void Window::setHeight(double height)
{
    this->height = height * this->zoomFactor;
    this->refresh();
}

void Window::setWidth(double width)
{
    this->width = width * this->zoomFactor;
    this->refresh();
}


bool Window::hasPoint(const Point& point) const
{
    return this->points.contains(point);
}

bool Window::hasWire(const Wire& wire) const
{
    return this->wires.contains(wire);
}

bool Window::hasWireFrame(const WireFrame& wireframe) const
{
    return this->wireframes.contains(wireframe);
}

bool Window::hasCurve(const Curve& curve) const
{
    return this->curves.contains(curve);
}

QString Window::toXML() const
{
    QString xmlRepr;
    QTextStream stream(&xmlRepr);

    stream << "\n" << this->getTab() << "<window>\n";

    stream << this->getTab() << this->getTab() << "<cop " << " x=\"" << this->getCenter().getX() << "\"";
    stream << " y=\"" << this->getCenter().getY() << "\"";
    stream << " z=\"" << this->getCenter().getZ() << "\"" << "/>\n";

    stream << this->getTab() << this->getTab() << "<wmin " << " x=\"" << this->getMinPoint().getX() << "\"";
    stream << " y=\"" << this->getMinPoint().getY() << "\"";
    stream << " z=\"" << this->getMinPoint().getZ() << "\"" << "/>\n";

    stream << this->getTab() << this->getTab() << "<wmax " << " x=\"" << this->getMaxPoint().getX() << "\"";
    stream << " y=\"" << this->getMaxPoint().getY() << "\"";
    stream << " z=\"" << this->getMaxPoint().getZ() << "\"" << "/>\n";

    stream << this->getTab() << this->getTab() << "<vpn x=\"0.0\"  y=\"0.0\" z=\"0.0\"/>\n";
    stream << this->getTab() << this->getTab() << "<vup x=\"0.0\"  y=\"0.0\" z=\"0.0\"/>\n";

    stream << this->getTab() << "</" << this->getTagName() << ">\n";

    return xmlRepr;
}

QString Window::getTagName() const
{
    return QString("window");
}

const QString Window::toString() const
{
    QString windowRepr;
    QTextStream stream(&windowRepr);

    stream << "Window \n" << "Maximum Point[" << this->getMaxPoint().toString() << "] Minimum Point[" << this->getMinPoint().toString() << "]\n";
    stream << "Center[" << this->getCenter().toString() << "]\n";
    stream << "height[" << this->height << "] width[" << this->width << "]\n";

    stream << "Points: \n";
    for (int i = 0; i < this->points.size(); i++) {
        stream << this->points[i].toString() << "\n";
    }

    stream << "Wires: \n";
    for (int i = 0; i < this->wires.size(); i++) {
        stream << this->wires[i].toString();
    }

    stream << "WireFrames: \n";
    for (int i = 0; i < this->wireframes.size(); i++) {
        stream << this->wireframes[i].toString();
    }

    stream << "Curves: \n";
    for (int i = 0; i < this->curves.size(); i++) {
        stream << this->curves[i].toString();
    }

    return windowRepr;
}
