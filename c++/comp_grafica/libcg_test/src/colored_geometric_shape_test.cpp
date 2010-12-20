#include "colored_geometric_shape_test.h"

ColoredGeometricShapeTest::ColoredGeometricShapeTest()
{
}

void ColoredGeometricShapeTest::knowsItsOwnAmountOfRed()
{
    ColoredGeometricShape shape = this->getColoredGeometricShape(137,0,0);
    QCOMPARE(137, shape.getRed());
}

void ColoredGeometricShapeTest::knowsItsOwnAmountOfGreen()
{
    ColoredGeometricShape shape = this->getColoredGeometricShape(0,50,0);
    QCOMPARE(50, shape.getGreen());
}

void ColoredGeometricShapeTest::knowsItsOwnAmountOfBlue()
{
    ColoredGeometricShape shape = this->getColoredGeometricShape(0,0,208);
    QCOMPARE(208, shape.getBlue());
}

void ColoredGeometricShapeTest::ifAColorIsSetNegativeTheValueWillBeZero()
{
    ColoredGeometricShape shape = this->getColoredGeometricShape(-3,-1,-208);
    QCOMPARE(0, shape.getRed());
    QCOMPARE(0, shape.getGreen());
    QCOMPARE(0, shape.getBlue());
}

void ColoredGeometricShapeTest::ifAColorIsSetGreaterThan255TheValueWillBe255()
{
    ColoredGeometricShape shape = this->getColoredGeometricShape(300,256,25789);
    QCOMPARE(255, shape.getRed());
    QCOMPARE(255, shape.getGreen());
    QCOMPARE(255, shape.getBlue());
}
