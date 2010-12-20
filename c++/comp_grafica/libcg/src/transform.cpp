#include "transform.h"
#include <cmath>
#include <math.h>

Matrix transform::getScaleMatrix(double sX, double sY)
{
    Matrix scale;

    scale.add(0,0,sX);
    scale.add(0,1,0);
    scale.add(0,2,0);

    scale.add(1,0,0);
    scale.add(1,1,sY);
    scale.add(1,2,0);

    scale.add(2,0,0);
    scale.add(2,1,0);
    scale.add(2,2,1);

    return scale;
}

Matrix transform::getScaleMatrix(double sX, double sY, double sZ)
{
    Matrix scale;

    scale.add(0,0,sX);
    scale.add(0,1,0);
    scale.add(0,2,0);
    scale.add(0,3,0);

    scale.add(1,0,0);
    scale.add(1,1,sY);
    scale.add(1,2,0);
    scale.add(1,3,0);


    scale.add(2,0,0);
    scale.add(2,1,0);
    scale.add(2,2,sZ);
    scale.add(2,3,0);

    scale.add(3,0,0);
    scale.add(3,1,0);
    scale.add(3,2,0);
    scale.add(3,3,1);

    return scale;
}

Matrix transform::getRotateMatrix(double angle)
{
    Matrix rotate;

    rotate.add(0,0,cos(angle));
    rotate.add(0,1,-sin(angle));
    rotate.add(0,2,0);

    rotate.add(1,0,sin(angle));
    rotate.add(1,1,cos(angle));
    rotate.add(1,2,0);

    rotate.add(2,0,0);
    rotate.add(2,1,0);
    rotate.add(2,2,1);

    return rotate;
}

Matrix transform::getTranslateMatrix(double dX, double dY)
{
    Matrix translate;

    translate.add(0,0,1);
    translate.add(0,1,0);
    translate.add(0,2,0);

    translate.add(1,0,0);
    translate.add(1,1,1);
    translate.add(1,2,0);

    translate.add(2,0,dX);
    translate.add(2,1,dY);
    translate.add(2,2,1);

    return translate;
}

Matrix transform::getXAxisRotateMatrix(double angle)
{
    Matrix rotate;

    rotate.add(0,0,1);
    rotate.add(0,1,0);
    rotate.add(0,2,0);
    rotate.add(0,3,0);

    rotate.add(1,0,0);
    rotate.add(1,1,cos(angle));
    rotate.add(1,2,sin(angle));
    rotate.add(1,3,0);

    rotate.add(2,0,0);
    rotate.add(2,1,-sin(angle));
    rotate.add(2,2,cos(angle));
    rotate.add(2,3,0);

    rotate.add(3,0,0);
    rotate.add(3,1,0);
    rotate.add(3,2,0);
    rotate.add(3,3,1);

    return rotate;
}

Matrix transform::getYAxisRotateMatrix(double angle)
{
    Matrix rotate;

    rotate.add(0,0,cos(angle));
    rotate.add(0,1,0);
    rotate.add(0,2,-sin(angle));
    rotate.add(0,3,0);

    rotate.add(1,0,0);
    rotate.add(1,1,1);
    rotate.add(1,2,0);
    rotate.add(1,3,0);

    rotate.add(2,0,sin(angle));
    rotate.add(2,1,0);
    rotate.add(2,2,cos(angle));
    rotate.add(2,3,0);

    rotate.add(3,0,0);
    rotate.add(3,1,0);
    rotate.add(3,2,0);
    rotate.add(3,3,1);

    return rotate;
}

Matrix transform::getZAxisRotateMatrix(double angle)
{
    Matrix rotate;

    rotate.add(0,0,cos(angle));
    rotate.add(0,1,sin(angle));
    rotate.add(0,2,0);
    rotate.add(0,3,0);

    rotate.add(1,0,-sin(angle));
    rotate.add(1,1,cos(angle));
    rotate.add(1,2,0);
    rotate.add(1,3,0);

    rotate.add(2,0,0);
    rotate.add(2,1,0);
    rotate.add(2,2,1);
    rotate.add(2,3,0);

    rotate.add(3,0,0);
    rotate.add(3,1,0);
    rotate.add(3,2,0);
    rotate.add(3,3,1);

    return rotate;
}

Matrix transform::getArbAxisRotateMatrix(double angle, const Point& axis)
{
    Matrix rotate;
    Point xAxis(0,1,0);
    Point zAxis(0,0,1);

    double xAngle = transform::getAngleBetweenVectors(xAxis, axis);
    double zAngle = transform::getAngleBetweenVectors(zAxis, axis);

    rotate = transform::getXAxisRotateMatrix(xAngle);
    rotate = rotate * transform::getZAxisRotateMatrix(zAngle);
    rotate = rotate * transform::getYAxisRotateMatrix(angle);
    rotate = rotate * transform::getZAxisRotateMatrix(-zAngle);
    rotate = rotate * transform::getXAxisRotateMatrix(-xAngle);

    return rotate;
}

Matrix transform::getTranslateMatrix(double dX, double dY, double dZ)
{
    Matrix translate;

    translate.add(0,0,1);
    translate.add(0,1,0);
    translate.add(0,2,0);
    translate.add(0,3,0);

    translate.add(1,0,0);
    translate.add(1,1,1);
    translate.add(1,2,0);
    translate.add(1,3,0);

    translate.add(2,0,0);
    translate.add(2,1,0);
    translate.add(2,2,1);
    translate.add(2,3,0);

    translate.add(3,0,dX);
    translate.add(3,1,dY);
    translate.add(3,2,dZ);
    translate.add(3,3,1);

    return translate;
}

double transform::fromDegreeToRadian(double degree)
{
    return degree * (std::atan2(0.0,-1.0) / 180.0);
}

double transform::getAngleBetweenVectors(const Point& v1, const Point& v2)
{
    double v1V2DotProduct = (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ());
    double v1Magnitude = sqrt((v1.getX() * v1.getX()) + (v1.getY() * v1.getY()) + (v1.getZ() * v1.getZ()));
    double v2Magnitude = sqrt((v2.getX() * v2.getX()) + (v2.getY() * v2.getY()) + (v2.getZ() * v2.getZ()));

    return acos(v1V2DotProduct / (v1Magnitude * v2Magnitude));
}

Point transform::getTransformedPoint(const Point& point, const Matrix& trans)
{
    Matrix pointM = point.toMatrix();
    if (trans.rowCount() == 4) {
        pointM.add(0,3, 1.0);
        return Point(pointM * trans, point.getRed(), point.getGreen(), point.getBlue());
    }
    pointM.add(0,2, 1.0);
    pointM = pointM * trans;
    return Point(point.getRed(), point.getGreen(), point.getBlue(), pointM.get(0,0), pointM.get(0,1), point.getZ());
}

Curve transform::getTransformedCurve(const Curve& curve, const Matrix& trans)
{
    QList<Wire> wires = curve.getWires();
    QList<Wire> newWires;

    for (int i = 0; i < wires.size(); i++) {
        newWires.append(transform::getTransformedWire(wires[i], trans));
    }
    return Curve(newWires, curve.getRed(), curve.getGreen(), curve.getBlue(), curve.toString());
}

Wire transform::getTransformedWire(const Wire& wire, const Matrix& trans)
{
    return Wire(transform::getTransformedPoint(wire.getFirstPoint(), trans), transform::getTransformedPoint(wire.getSecondPoint(), trans),
                wire.getRed(), wire.getGreen(), wire.getBlue());
}


WireFrame transform::getTransformedWireFrame(const WireFrame& wireframe, const Matrix& trans)
{
    QList<Wire> oldWires = wireframe.getWires();
    QList<Wire> newWires;

    for (int i = 0; i < oldWires.size(); i++) {
        newWires.append(transform::getTransformedWire(oldWires[i], trans));
    }

    return WireFrame(newWires, wireframe.isFilled(), wireframe.getRed(), wireframe.getGreen(), wireframe.getBlue());
}
