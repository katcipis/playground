#include "wire_test.h"
#include "wire.h"
#include "point.h"

void WireTest::knowsTheTwoPointsThatFormsIt()
{
    Point first_point(2,2);
    Point second_point(4,2);
    Wire wire(first_point, second_point);

    QCOMPARE(wire.getFirstPoint(), first_point);
    QCOMPARE(wire.getSecondPoint(), second_point);
}

void WireTest::twoWiresAreEqualIfBothHaveTheSamePoints()
{
    QCOMPARE(Wire(Point(2,2), Point(4,4)), Wire(Point(2,2), Point(4,4)));
    QCOMPARE(Wire(Point(4,4), Point(2,2)), Wire(Point(2,2), Point(4,4)));
}

void WireTest::twoWiresAreNotEqualIfOneOfThePointsIsNotEqual()
{
    QVERIFY(Wire(Point(2,1), Point(4,4)) != Wire(Point(2,2), Point(4,4)));
    QVERIFY(Wire(Point(2,3), Point(4,4)) != Wire(Point(2,2), Point(4,4)));

    QVERIFY(Wire(Point(2,2), Point(4,3)) != Wire(Point(2,2), Point(4,4)));
    QVERIFY(Wire(Point(2,2), Point(4,5)) != Wire(Point(2,2), Point(4,4)));
}

void WireTest::twoWiresAreNotEqualIfBothPointsAreNotEqual()
{
    QVERIFY(Wire(Point(2,1), Point(4,3)) != Wire(Point(2,2), Point(4,4)));
    QVERIFY(Wire(Point(2,3), Point(4,5)) != Wire(Point(2,2), Point(4,4)));
    QVERIFY(Wire(Point(2,3), Point(4,3)) != Wire(Point(2,2), Point(4,4)));
    QVERIFY(Wire(Point(2,1), Point(4,5)) != Wire(Point(2,2), Point(4,4)));
}

void WireTest::knowsItsCenter()
{
    Wire wire(Point(1,1), Point(3,7));
    Point center(2, 4);
    QCOMPARE(center, wire.getCenter());
}

ColoredGeometricShape WireTest::getColoredGeometricShape(int red, int green, int blue)
{
    return Wire(Point(1,1), Point(1,1), red, green, blue);
}

WireTest::WireTest()
{
}
