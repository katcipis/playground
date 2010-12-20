#include "window_perspective.h"
#include "window_ortogonal.h"
#include "transform.h"
#include "clipper.h"
#include <QTextStream>

WindowPerspective::WindowPerspective(double height, double width) : Window(height, width), cop(0,0,1), d(1.0)
{
    clipper::init();
}


Point WindowPerspective::getPointProjection(const Point& point)
{
    double zD = point.getZ() / this->d;

    if (zD < 0.0) {
        zD = -zD;
    }

    if (zD == 0.0) {
        zD = 1.0;
    }

    return Point(point.getRed(), point.getGreen(), point.getBlue(),
                 point.getX() / zD, point.getY() / zD, this->d);
}


WireFrame WindowPerspective::getWireFrameProjection(const WireFrame& wireframe)
{
    QList<Wire> wires = this->getWiresProjection(wireframe.getWires());
    return WireFrame(wires, wireframe.isFilled(), wireframe.getRed(), wireframe.getGreen(), wireframe.getBlue());
}

QList<Wire> WindowPerspective::getWiresProjection(const QList<Wire>& wires)
{
    QList<Wire> newWires;

    for (int i = 0; i < wires.size(); i++) {
        newWires.append(Wire(this->getPointProjection(wires[i].getFirstPoint()),
                             this->getPointProjection(wires[i].getSecondPoint()),
                             wires[i].getRed(), wires[i].getGreen(), wires[i].getBlue()));
    }
    
    return newWires;
}


void WindowPerspective::refresh()
{
    const QList<Point>& points = Window::getPoints();
    const QList<Wire>& wires   = Window::getWires();
    const QList<WireFrame>& wireframes = Window::getWireFrames();
    const QList<Curve>& curves = Window::getCurves();

    Matrix trans = transform::getTranslateMatrix(-this->cop.getX(), -this->cop.getY(), -this->cop.getZ());
    trans = trans * transform::getZAxisRotateMatrix(-this->vUpAngleWithY);
    trans = trans * transform::getXAxisRotateMatrix(-this->vpnAngleWithX);
    trans = trans * transform::getYAxisRotateMatrix(-this->vpnAngleWithY);

    this->points3D.clear();
    this->wires3D.clear();
    this->wireframes3D.clear();

    for (int i = 0; i < points.size(); i ++) {
        this->points3D.append(this->getPointProjection(transform::getTransformedPoint(points[i], trans)));
    }

    for (int i = 0; i < wires.size(); i ++) {
        this->wires3D.append(transform::getTransformedWire(wires[i], trans));
    }
    this->wires3D = this->getWiresProjection(this->wires3D);

    for (int i = 0; i < wireframes.size(); i ++) {
        WireFrame wireframe = this->getWireFrameProjection(transform::getTransformedWireFrame(wireframes[i], trans));
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
        this->wires3D.append(this->getWiresProjection(transform::getTransformedCurve(curves[i], trans).getWires()));
    }

    this->points3D     = clipper::clipPoints(this->points3D, this->getMinPoint(), this->getMaxPoint());
    this->wires3D      = clipper::clipWires(this->wires3D,  this->getMinPoint(), this->getMaxPoint());
    this->wireframes3D = clipper::clipWireFrames(this->wireframes3D, this->getMinPoint(), this->getMaxPoint());
}

Wire WindowPerspective::adjustMovementVector(const Wire& base) {
    Point pBase = base.getFirstPoint();
    Matrix trans =  transform::getTranslateMatrix(-pBase.getX(), -pBase.getY(), -pBase.getZ());
    trans = trans * transform::getZAxisRotateMatrix(this->vUpAngleWithY);
    trans = trans * transform::getTranslateMatrix(pBase.getX(), pBase.getY(), pBase.getZ());

    return transform::getTransformedWire(base, trans);
}

void WindowPerspective::setCenter(const Point& center)
{
    this->cop = center;
}

Point WindowPerspective::getCenter() const
{
    return this->cop;
}

const QList<WireFrame>& WindowPerspective::getWireFrames() const
{
    return this->wireframes3D;
}

const QList<Wire>& WindowPerspective::getWires() const
{
    return this->wires3D;
}

const QList<Point>& WindowPerspective::getPoints() const
{
    return this->points3D;
}

const QString WindowPerspective::toString() const
{
    QString windowRepr;
    QTextStream stream(&windowRepr);

    stream << "Window 3D Perspective \n" << "COP[" << this->cop.toString() << "]\n";

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
