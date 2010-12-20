#ifndef CURVE_HERMITE_H
#define CURVE_HERMITE_H

#include <QList>
#include "wire.h"
#include "curve.h"

/**
 *  Class that defines an hermite curve.
 */
class CurveHermite : public Curve
{
private:
    Point p1, p4, r1, r4;
    double precision;
    double calculateCoordinate(double t, double p1V, double p4V, double r1V, double r4V);
    void defineString ();
    void buildXmlRepresentation();

public:

    /**
     *  \brief Class constructor.
     *  Constructs a hermite curve.
     *  @param p1        - The p1 point that forms this curve.
     *  @param p4        - The p4 point that forms this curve.
     *  @param r1        - The r1 point that forms this curve.
     *  @param r4        - The r4 point that forms this curve.
     *  @param precision - The precision used to build this curve.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    CurveHermite(const Point& p1, const Point& p4, const Point& r1, const Point& r4, double precision,
                 int red = 0, int green = 0, int blue = 0);

    /**
     *  \brief Class constructor.
     *  Constructs a curve.
     *  @param wires     - The wires that forms this curve.
     *  @param precision - The precision used to build this curve.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    CurveHermite(const QList<Wire>& wires,int red = 0, int green = 0, int blue = 0) : Curve(wires, red, green, blue), precision(0.0){};


    /**
     *  Get the P1 point.
     *  @return the P1 point.
     */
    Point getP1() const;

    /**
     *  Get the P4 point.
     *  @return the P4 point.
     */
    Point getP4() const;

    /**
     *  Get the R1 point.
     *  @return the R1 point.
     */
    Point getR1() const;

    /**
     *  Get the R4 point.
     *  @return the R4 point.
     */
    Point getR4() const;

    /**
     *  Get the precision used to build this curve.
     *  @return the precision.
     */
    double getPrecision() const;
};

#endif // CURVE_HERMITE_H
