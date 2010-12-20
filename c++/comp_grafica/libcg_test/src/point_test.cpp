#include "point_test.h"
#include "point.h"
#include "cg_exception.h"

void PointTest::knowsItsXCoordinate()
{
    Point point(1.0, 2.5, 5.0);
    QCOMPARE(1.0, point.getX());
}

void PointTest::knowsItsYCoordinate()
{
    Point point(1.3, 2.7, 3.8);
    QCOMPARE(2.7, point.getY());
}

void PointTest::knowsItsZCoordinate()
{
    Point point(1.3, 2.7, 3.8);
    QCOMPARE(3.8, point.getZ());
}

void PointTest::knowsItsRepresentationAsAMatrix()
{
    Matrix matrix_representation;
    Point point(1.3, 2.7, 3.8);

    matrix_representation.add(0, 0, 1.3);
    matrix_representation.add(0, 1, 2.7);
    matrix_representation.add(0, 2, 3.8);

    QCOMPARE(matrix_representation, point.toMatrix());
}

void PointTest::canBeCreatedFromA1X3Matrix()
{
    Matrix point_matrix;
    point_matrix.add(0,0, double(5.3));
    point_matrix.add(0,1, double(7.5));
    point_matrix.add(0,2, double(9.5));

    Point point(point_matrix);

    QCOMPARE(double(5.3), point.getX());
    QCOMPARE(double(7.5), point.getY());
    QCOMPARE(double(9.5), point.getZ());
}

void PointTest::ifItIsNotGivenAtLeastA1X3MatrixOnConstructionRaisesAnException()
{
    bool has_been_throw = false;
    Matrix point_matrix;

    point_matrix.add(0,0, 5);

    try{
       Point point(point_matrix);
    } catch(CGException e) {
        has_been_throw = true;
    }

    QVERIFY(has_been_throw);
    has_been_throw = false;
    point_matrix.add(0,1, 9);

    try{
       Point point(point_matrix);
    } catch(CGException e) {
        has_been_throw = true;
    }

    QVERIFY(has_been_throw);
    point_matrix.add(0,2, 9);
    point_matrix.add(0,3, 9);

    Point p(point_matrix);
}

void PointTest::twoPointsAreEqualIfTheyHaveTheSameXAndSameYAndSameZ()
{
    Point point(150.30, 300.50, 50.3);
    Point another_point(150.30, 300.50, 50.3);

    QCOMPARE(point, another_point);
}

void PointTest::twoPointsAreNotEqualIfTheyDonHaveTheSameX()
{
    Point point(150.30, 300.50, 50.3);
    Point another_point(150.29, 300.50, 50.3);
    Point another_point2(150.31, 300.50, 50.3);

    QVERIFY(point != another_point);
    QVERIFY(point != another_point2);
    QVERIFY(another_point != another_point2);
}

void PointTest::twoPointsAreNotEqualIfTheyDonHaveTheSameY()
{
    Point point(150.30, 300.50, 50.3);
    Point another_point(150.30, 300.51, 50.3);
    Point another_point2(150.30, 300.49, 50.3);

    QVERIFY(point != another_point);
    QVERIFY(point != another_point2);
    QVERIFY(another_point != another_point2);
}

void PointTest::twoPointsAreNotEqualIfTheyDonHaveTheSameZ()
{
    Point point(150.30, 300.50, 50.3);
    Point another_point(150.30, 300.50, 50.29);
    Point another_point2(150.30, 300.50, 50.31);

    QVERIFY(point != another_point);
    QVERIFY(point != another_point2);
    QVERIFY(another_point != another_point2);
}

void PointTest::twoPointsAreNotEqualIfTheyDontHaveTheSameXAndSameYAndSameZ()
{
    Point point(150.30, 300.50, 50.30);
    Point another_point(150.31, 300.51, 50.31);
    Point another_point2(150.29, 300.49, 50.29);

    QVERIFY(point != another_point);
    QVERIFY(point != another_point2);
    QVERIFY(another_point != another_point2);
}

ColoredGeometricShape PointTest::getColoredGeometricShape(int red, int green, int blue)
{
    return Point(red, green, blue, 1, 1);
}

PointTest::PointTest()
{
}
