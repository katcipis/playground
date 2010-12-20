#include "transform_test.h"
#include "transform.h"
#include "math.h"

TransformTest::TransformTest()
{
}

void TransformTest::givenASXAndASYCanGenerateTheScaleMatrix()
{
    Matrix expected;
    double sX = 5.5;
    double sY = 7.3;

    expected.add(0,0,sX);
    expected.add(0,1,0);
    expected.add(0,2,0);

    expected.add(1,0,0);
    expected.add(1,1,sY);
    expected.add(1,2,0);

    expected.add(2,0,0);
    expected.add(2,1,0);
    expected.add(2,2,1);

    QCOMPARE(expected, transform::getScaleMatrix(sX,sY));
}

void TransformTest::givenADXAndADYCanGenerateTheTranslateMatrix()
{
    Matrix expected;
    double dX = 35.5;
    double dY = 789.3;

    expected.add(0,0,1);
    expected.add(0,1,0);
    expected.add(0,2,0);

    expected.add(1,0,0);
    expected.add(1,1,1);
    expected.add(1,2,0);

    expected.add(2,0,dX);
    expected.add(2,1,dY);
    expected.add(2,2,1);

    QCOMPARE(expected, transform::getTranslateMatrix(dX, dY));
}

void TransformTest::givenAnAngleAndANumberOfDimensionsCanCreateTheRotateMatrix()
{
    Matrix expected;
    double angle = 1.5;

    expected.add(0,0,  cos(angle));
    expected.add(0,1,- sin(angle));
    expected.add(0,2,0);

    expected.add(1,0, sin(angle));
    expected.add(1,1, cos(angle));
    expected.add(1,2,0);

    expected.add(2,0,0);
    expected.add(2,1,0);
    expected.add(2,2,1);

    QCOMPARE(expected, transform::getRotateMatrix(angle));
}
