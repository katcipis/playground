#ifndef POINT_TEST_H
#define POINT_TEST_H

#include <QObject>
#include "colored_geometric_shape_test.h"

class PointTest : public ColoredGeometricShapeTest
{
    Q_OBJECT
private slots:
    void knowsItsXCoordinate();
    void knowsItsYCoordinate();
    void knowsItsZCoordinate();
    void knowsItsRepresentationAsAMatrix();
    void canBeCreatedFromA1X3Matrix();
    void ifItIsNotGivenAtLeastA1X3MatrixOnConstructionRaisesAnException();
    void twoPointsAreEqualIfTheyHaveTheSameXAndSameYAndSameZ();
    void twoPointsAreNotEqualIfTheyDonHaveTheSameX();
    void twoPointsAreNotEqualIfTheyDonHaveTheSameY();
    void twoPointsAreNotEqualIfTheyDonHaveTheSameZ();
    void twoPointsAreNotEqualIfTheyDontHaveTheSameXAndSameYAndSameZ();

protected:
    ColoredGeometricShape getColoredGeometricShape(int red, int green, int blue);

public:
    PointTest();
};

#endif // POINT_TEST_H
