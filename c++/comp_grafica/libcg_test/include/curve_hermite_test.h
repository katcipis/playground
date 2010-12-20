#ifndef CURVES_HERMITE_TEST_H
#define CURVES_HERMITE_TEST_H

#include "colored_geometric_shape_test.h"

class CurveHermiteTest : public ColoredGeometricShapeTest
{
    Q_OBJECT
private slots:
    void twoCurvesAreEqualIfTheyHaveTheSameP1P4R1R4AndPrecision();
    void twoCurvesAreNotEqualIfTheyDontHaveTheSameP1P4R1R4AndPrecision();
    void knowsItsP1();
    void knowsItsP4();
    void knowsItsR1();
    void knowsItsR4();
    void knowItsPrecision();
    void ifHasAPrecisionOfNItWillHaveNMinusOneOrNWiresFormingIt();

protected:
    ColoredGeometricShape getColoredGeometricShape(int red, int green, int blue);

public:
    CurveHermiteTest();
};

#endif // CURVES_HERMITE_TEST_H
