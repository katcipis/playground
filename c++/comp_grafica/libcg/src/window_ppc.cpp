#include "window_ppc.h"
#include "transform.h"
#include "cg_exception.h"
#include "clipper.h"
#include <cmath>
#include <QTextStream>

WindowPPC::WindowPPC(double height, double width) :
           Window(height, width),
           center(0,0),
           minPPC(Point(0,0)),
           maxPPC(Point(1,1))
{
    clipper::init();
}

void WindowPPC::refresh()
{
    this->generatePPCCoordinates();
}

void WindowPPC::setCenter(const Point& center)
{
    this->center = center;
}

void WindowPPC::generatePPCCoordinates()
{
    Matrix trans = transform::getTranslateMatrix(-this->center.getX(), -this->center.getY());
    trans = trans * transform::getRotateMatrix(-this->vUpAngleWithY);
    this->generateWindowPPC();
    this->generateObjectsPPC(trans);
}

Wire WindowPPC::adjustMovementVector(const Wire& base) {
    Point pBase = base.getFirstPoint();

    Matrix trans =  transform::getTranslateMatrix(-pBase.getX(), -pBase.getY());
    trans = trans * transform::getRotateMatrix(this->vUpAngleWithY);
    trans = trans * transform::getTranslateMatrix(pBase.getX(), pBase.getY());

    return transform::getTransformedWire(base, trans);
}

void WindowPPC::generateObjectsPPC(const Matrix& trans)
{
    this->ppcPoints.clear();
    this->ppcWires.clear();
    this->ppcWireFrames.clear();

    for (int i = 0; i < Window::getPoints().size(); i++) {
        this->ppcPoints.append(transform::getTransformedPoint(Window::getPoints()[i], trans));
    }

    for (int i = 0; i < Window::getWires().size(); i++) {
        this->ppcWires.append(transform::getTransformedWire(Window::getWires()[i], trans));
    }

    for (int i = 0; i < Window::getWireFrames().size(); i++) {
        /* more workaround because of the clipping of object3d */
        WireFrame wireframe = Window::getWireFrames()[i];

        if (wireframe.isAClosedPolygon()) {
            this->ppcWireFrames.append(transform::getTransformedWireFrame(wireframe, trans));
        } else {
            QList<Wire> obj3d = wireframe.getWires();
            for (int j = 0; j < obj3d.size(); j++) {
                Wire tmp(obj3d[j].getFirstPoint(), obj3d[j].getSecondPoint(),
                         wireframe.getRed(),
                         wireframe.getGreen(),
                         wireframe.getBlue());
                this->ppcWires.append(transform::getTransformedWire(tmp, trans));
            }
        }
    }

    for (int i = 0; i < Window::getCurves().size(); i++) {
        this->ppcWires.append(transform::getTransformedCurve(Window::getCurves()[i], trans).getWires());
    }

    this->ppcPoints     = clipper::clipPoints(this->ppcPoints, this->getMinPoint(), this->getMaxPoint());
    this->ppcWires      = clipper::clipWires(this->ppcWires, this->getMinPoint(), this->getMaxPoint());
    this->ppcWireFrames = clipper::clipWireFrames(this->ppcWireFrames, this->getMinPoint(), this->getMaxPoint());
}

void WindowPPC::generateWindowPPC()
{
    Matrix windowTrans = transform::getTranslateMatrix(-this->center.getX(), -this->center.getY());
    this->maxPPC = transform::getTransformedPoint(Window::getMaxPoint(), windowTrans);
    this->minPPC = transform::getTransformedPoint(Window::getMinPoint(), windowTrans);
}

Point WindowPPC::getCenter() const
{
    return this->center;
}

const QString WindowPPC::toString() const
{
    QString windowRepr;
    QTextStream stream(&windowRepr);

    stream << "Window PPC \n" << "Maximum PPC Point[" << this->maxPPC.toString() << "] Minimum PPC Point[" << this->minPPC.toString() << "]\n";

    stream << "PPC Points: \n";
    for (int i = 0; i < this->ppcPoints.size(); i++) {
        stream << this->ppcPoints[i].toString() << "\n";
    }

    stream << "PPC Wires: \n";
    for (int i = 0; i < this->ppcWires.size(); i++) {
        stream << this->ppcWires[i].toString();
    }

    stream << "PPC WireFrames: \n";
    for (int i = 0; i < this->ppcWireFrames.size(); i++) {
        stream << this->ppcWireFrames[i].toString();
    }

    return Window::toString() + windowRepr;
}

Point WindowPPC::getMaxPoint() const
{
    return this->maxPPC;
}

Point WindowPPC::getMinPoint() const
{
    return this->minPPC;
}

const QList<WireFrame>& WindowPPC::getWireFrames() const
{
    return this->ppcWireFrames;
}


const QList<Wire>& WindowPPC::getWires() const
{
    return this->ppcWires;
}

const QList<Point>& WindowPPC::getPoints() const
{
    return this->ppcPoints;
}
