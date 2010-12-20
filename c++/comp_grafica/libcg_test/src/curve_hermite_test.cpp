#include "curve_hermite_test.h"
#include "curve_hermite.h"

CurveHermiteTest::CurveHermiteTest()
{

}

void CurveHermiteTest::twoCurvesAreEqualIfTheyHaveTheSameP1P4R1R4AndPrecision()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);

    QCOMPARE(curve, CurveHermite(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100));
}

void CurveHermiteTest::twoCurvesAreNotEqualIfTheyDontHaveTheSameP1P4R1R4AndPrecision()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);

    QVERIFY(curve != CurveHermite (Point(0,0), Point(200,0), Point(0,50), Point(200,50), 101));
    QVERIFY(curve != CurveHermite (Point(0,0), Point(200,0), Point(0,50), Point(200,50), 99));

    QVERIFY(curve != CurveHermite (Point(0,0), Point(200.5,0), Point(0,50), Point(200,50), 100));
    QVERIFY(curve != CurveHermite (Point(0.4,0), Point(200,0), Point(0,50), Point(200,50), 100));
    QVERIFY(curve != CurveHermite (Point(0,0), Point(200,0), Point(0,50.5), Point(200,50), 100));
    QVERIFY(curve != CurveHermite (Point(0,0), Point(200,0), Point(0,50), Point(200.3,50), 100));
}

void CurveHermiteTest::knowsItsP1()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);
    QCOMPARE(curve.getP1(), Point(0,0));
}

void CurveHermiteTest::knowsItsP4()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);
    QCOMPARE(curve.getP4(), Point(200,0));
}

void CurveHermiteTest::knowsItsR1()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);
    QCOMPARE(curve.getR1(), Point(0,50));
}

void CurveHermiteTest::knowsItsR4()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);
    QCOMPARE(curve.getR4(), Point(200,50));
}

void CurveHermiteTest::knowItsPrecision()
{
    CurveHermite curve(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100);
    QCOMPARE(curve.getPrecision(), 100.0);
}

void CurveHermiteTest::ifHasAPrecisionOfNItWillHaveNMinusOneOrNWiresFormingIt()
{
    QCOMPARE(100, CurveHermite(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100).getWires().size());
    QCOMPARE(52, CurveHermite(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 52).getWires().size());
    QCOMPARE(86, CurveHermite(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 85).getWires().size());
}

ColoredGeometricShape CurveHermiteTest::getColoredGeometricShape(int red, int green, int blue)
{
    return CurveHermite(Point(0,0), Point(200,0), Point(0,50), Point(200,50), 100, red,green, blue);
}
