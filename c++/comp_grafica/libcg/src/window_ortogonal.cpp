#include "window_ortogonal.h"
#include "transform.h"
#include "clipper.h"
#include <QTextStream>
#include <iostream>

WindowOrtogonal::WindowOrtogonal(double height, double width) : Window(height, width), vrp(0,0,0)
{
    clipper::init();
}

WindowOrtogonal::WindowOrtogonal(const Point& min, const Point& max, const Point& center) :
                   Window(max.getY() - min.getY(), max.getX() - min.getX()), vrp(center)
{
}

void WindowOrtogonal::refresh()
{
    const QList<Point>& points = Window::getPoints();
    const QList<Wire>& wires = Window::getWires();
    const QList<WireFrame>& wireframes = Window::getWireFrames();
    const QList<Curve>& curves = Window::getCurves();

    Matrix trans = transform::getTranslateMatrix(-this->vrp.getX(), -this->vrp.getY(), -this->vrp.getZ());
    trans = trans * transform::getZAxisRotateMatrix(-this->vUpAngleWithY);
    trans = trans * transform::getXAxisRotateMatrix(-this->vpnAngleWithX);
    trans = trans * transform::getYAxisRotateMatrix(-this->vpnAngleWithY);
    trans = trans * transform::getTranslateMatrix(this->vrp.getX(), this->vrp.getY(), this->vrp.getZ());

    this->points3D.clear();
    this->wires3D.clear();
    this->wireframes3D.clear();

    for (int i = 0; i < points.size(); i ++) {
        this->points3D.append(transform::getTransformedPoint(points[i], trans));
    }

    for (int i = 0; i < wires.size(); i ++) {
        this->wires3D.append(transform::getTransformedWire(wires[i], trans));
    }

    for (int i = 0; i < wireframes.size(); i ++) {
        WireFrame wireframe = transform::getTransformedWireFrame(wireframes[i], trans);
        if (wireframe.isAClosedPolygon()) {
            this->wireframes3D.append(wireframe);
        } else {
            QList<Wire> obj3d = wireframe.getWires();
            for (int j = 0; j < obj3d.size(); j++) {
                Wire tmp(obj3d[j].getFirstPoint(), obj3d[j].getSecondPoint(),
                         wireframe.getRed(),
                         wireframe.getGreen(),
                         wireframe.getBlue());
                this->wires3D.append(tmp);
            }
        }
    }

    for (int i = 0; i < curves.size(); i ++) {
        this->wires3D.append(transform::getTransformedCurve(curves[i], trans).getWires());
    }

    this->points3D     = clipper::clipPoints(this->points3D, this->getMinPoint(), this->getMaxPoint());
    this->wires3D      = clipper::clipWires(this->wires3D,  this->getMinPoint(), this->getMaxPoint());
    this->wireframes3D = clipper::clipWireFrames(this->wireframes3D, this->getMinPoint(), this->getMaxPoint());
}

Wire WindowOrtogonal::adjustMovementVector(const Wire& base) {
    Point pBase = base.getFirstPoint();
    Matrix trans =  transform::getTranslateMatrix(-pBase.getX(), -pBase.getY(), -pBase.getZ());
    trans = trans * transform::getZAxisRotateMatrix(this->vUpAngleWithY);
    trans = trans * transform::getTranslateMatrix(pBase.getX(), pBase.getY(), pBase.getZ());

    return transform::getTransformedWire(base, trans);
}

void WindowOrtogonal::setCenter(const Point& center)
{
    this->vrp = center;
}

Point WindowOrtogonal::getCenter() const
{
    return this->vrp;
}

const QList<WireFrame>& WindowOrtogonal::getWireFrames() const
{
    return this->wireframes3D;
}

const QList<Wire>& WindowOrtogonal::getWires() const
{
    return this->wires3D;
}

const QList<Point>& WindowOrtogonal::getPoints() const
{
    return this->points3D;
}

const QString WindowOrtogonal::toString() const
{
    QString windowRepr;
    QTextStream stream(&windowRepr);

    stream << "Window 3D Ortogonal \n" << "VRP[" << this->vrp.toString() << "]\n";

    stream << "3D Points: \n";
    for (int i = 0; i < this->points3D.size(); i++) {
        stream << this->points3D[i].toString() << "\n";
    }

    stream << "3D Wires: \n";
    for (int i = 0; i < this->wires3D.size(); i++) {
        stream << this->wires3D[i].toString();
    }

    stream << "3D WireFrames: \n";
    for (int i = 0; i < this->wireframes3D.size(); i++) {
        stream << this->wireframes3D[i].toString();
    }

    return Window::toString() + windowRepr;
}
