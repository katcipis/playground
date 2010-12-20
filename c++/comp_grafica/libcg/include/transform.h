#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"
#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "curve_hermite.h"
#include "curve_bspline.h"

/**
 * \namespace transform
 * \brief Define functions that can be used to generate matrices that will transform points and usefull math functions.
 */
namespace transform
{
    /**
     *  Get the scale matrix, it will return a 3x3 matrix with homogeneous coordinate.
     *  @param sX  - The x scale.
     *  @param sY  - The y scale.
     *  @return - the transformation matrix.
     */
    Matrix getScaleMatrix(double sX, double sY);

    /**
     *  Get the scale matrix, it will return a 4x4 matrix with homogeneous coordinate.
     *  @param sX  - The x scale.
     *  @param sY  - The y scale.
     *  @param sZ  - The z scale.
     *  @return - the transformation matrix.
     */
    Matrix getScaleMatrix(double sX, double sY, double sZ);

    /**
     *  Get the rotate matrix, it will return a 3 x 3 matrix with homogeneous coordinate.
     *  @param angle      - The rotate angle in radians.
     *  @return - the transformation matrix.
     */
    Matrix getRotateMatrix(double angle);

    /**
     *  Get the rotate matrix around the X axis, it will return a 4 x 4 matrix with homogeneous coordinate.
     *  @param angle - The rotate angle in radians.
     *  @return - the transformation matrix.
     */
    Matrix getXAxisRotateMatrix(double angle);

    /**
     *  Get the rotate matrix around the Y axis, it will return a 4 x 4 matrix with homogeneous coordinate.
     *  @param angle - The rotate angle in radians.
     *  @return - the transformation matrix.
     */
    Matrix getYAxisRotateMatrix(double angle);

    /**
     *  Get the rotate matrix around the Z axis, it will return a 4 x 4 matrix with homogeneous coordinate.
     *  @param angle - The rotate angle in radians.
     *  @return - the transformation matrix.
     */
    Matrix getZAxisRotateMatrix(double angle);

    /**
     *  Get the rotate matrix around an arbitrary axis, it will return a 4 x 4 matrix with homogeneous coordinate.
     *  @param angle - The rotate angle in radians.
     *  @param axis  - The point that defines the axis.
     *  @return - the transformation matrix.
     */
    Matrix getArbAxisRotateMatrix(double angle, const Point& axis);


    /**
     *  Get the translate matrix, it will return a 3x3 matrix with homogeneous coordinate.
     *  @param dX  - The x translate.
     *  @param dY  - The y translate.
     *  @return - the transformation matrix.
     */
    Matrix getTranslateMatrix(double dX, double dY);

    /**
     *  Get the translate matrix, it will return a 4x4 matrix with homogeneous coordinate.
     *  @param dX  - The x translate.
     *  @param dY  - The y translate.
     *  @param dZ  - The z translate.
     *  @return - the transformation matrix.
     */
    Matrix getTranslateMatrix(double dX, double dY, double dZ);

    /**
     *  Get a new point applying the given transformation matrix.
     *  @param point  - The point.
     *  @param trans  - The matrix.
     *  @return - the new point.
     */
    Point getTransformedPoint(const Point& point, const Matrix& trans);

    /**
     *  Get a new wire applying the given transformation matrix.
     *  @param wire   - The wire.
     *  @param trans  - The matrix.
     *  @return - the new wire.
     */
    Wire getTransformedWire(const Wire& wire, const Matrix& trans);

    /**
     *  Get a new curve applying the given transformation matrix.
     *  @param curve  - The curve.
     *  @param trans  - The matrix.
     *  @return - the new curve.
     */
    Curve getTransformedCurve(const Curve& curve, const Matrix& trans);

    /**
     *  Get a new wireframe applying the given transformation matrix.
     *  @param wireframe   - The wireframe.
     *  @param trans       - The matrix.
     *  @return - the new wireframe.
     */
    WireFrame getTransformedWireFrame(const WireFrame& wireframe, const Matrix& trans);

    /**
     *  Get the given degree angle as a radian angle.
     *  @param degree - the degree angle
     *  @return - the radian angle.
     */
    double fromDegreeToRadian(double degree);
    
    /**
     *  Get the angle in radian between two vectors (both vectors are supposed to start at the origin).
     *  @param v1   - the point that defines the direction of v1.
     *  @param v2   - the point that defines the direction of v2.
     *  @return - the radian angle.
     */
    double getAngleBetweenVectors(const Point& v1, const Point& v2);
    
}

#endif // TRANSFORM_H
