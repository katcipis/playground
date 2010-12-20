#ifndef COLORED_GEOMETRIC_SHAPE_TEST_H
#define COLORED_GEOMETRIC_SHAPE_TEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "colored_geometric_shape.h"

class ColoredGeometricShapeTest : public QObject
{
    Q_OBJECT
public:
    ColoredGeometricShapeTest();

protected:
    virtual ColoredGeometricShape getColoredGeometricShape(int red, int green, int blue) = 0;

private slots:
    void knowsItsOwnAmountOfRed();
    void knowsItsOwnAmountOfGreen();
    void knowsItsOwnAmountOfBlue();

    void ifAColorIsSetNegativeTheValueWillBeZero();
    void ifAColorIsSetGreaterThan255TheValueWillBe255();
};

#endif // COLORED_GEOMETRIC_SHAPE_TEST_H
