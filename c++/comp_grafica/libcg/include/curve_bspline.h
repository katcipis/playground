#ifndef CURVE_BSPLINE_H
#define CURVE_BSPLINE_H

#include "curve.h"
#include "point.h"
#include "wireframe.h"
#include <QList>
#include <QVector>



/**
 *  Class that defines an spline curve.
 */
class CurveBSpline : public Curve
{
private:
    Matrix deltaMat;
    QList<Point> formingPoints;
    QList<Point> desenhaCurvaFwdDiff(double n, double x, double &delta1x, double &delta2x, double &delta3x, double y, double &delta1y, double &delta2y, double &delta3y);
    void defineString ();
    void buildXmlRepresentation();

 public:

    /**
     *  \brief Class constructor.
     *  Constructs a bspline curve.
     *  @param points  - List of points that forms the curve.
     *  @param red     - Amount of red of the point.
     *  @param green   - Amount of green of the point.
     *  @param blue    - Amount of blue of the point.
     */
    CurveBSpline(QList<Point> points, int red = 0, int green = 0, int blue = 0);

    /**
     *  \brief Class constructor.
     *  Constructs a curve.
     *  @param wires     - The wires that forms this curve.
     *  @param precision - The precision used to build this curve.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    CurveBSpline(const QList<Wire>& wires,int red = 0, int green = 0, int blue = 0) : Curve(wires, red, green, blue) {};
};


#endif // CURVE_BSPLINE_H
