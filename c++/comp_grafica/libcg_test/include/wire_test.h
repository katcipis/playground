#ifndef WIRE_TEST_H
#define WIRE_TEST_H

#include <QObject>
#include "colored_geometric_shape_test.h"

class WireTest : public ColoredGeometricShapeTest
{
    Q_OBJECT
private slots:
    void knowsTheTwoPointsThatFormsIt();
    void knowsItsCenter();
    void twoWiresAreEqualIfBothHaveTheSamePoints();
    void twoWiresAreNotEqualIfOneOfThePointsIsNotEqual();
    void twoWiresAreNotEqualIfBothPointsAreNotEqual();

protected:
    ColoredGeometricShape getColoredGeometricShape(int red, int green, int blue);

public:
    WireTest();
};

#endif // WIRE_TEST_H
