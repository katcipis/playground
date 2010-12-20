#include "viewport_2d_test.h"

void ViewPort2DTest::canTransformAWindowPointToAViewPortPoint()
{
    Point window_point(3,3);
    Point expected_vp_point(1.5, 8.5);
    Point calculated_point = viewport_2d::transform(window_point, Point(0,0), Point(20,20), Point(0,0), Point(10,10));

    QCOMPARE(expected_vp_point, calculated_point);
}

void ViewPort2DTest::canTransformAWindowWireToAViewPortWire()
{
    // TODO, its really annoing to test this.
}

void ViewPort2DTest::canTransformAWindowWireFramePointToAViewPortWireFrame()
{
    // TODO, its really annoing to test this.
}

ViewPort2DTest::ViewPort2DTest()
{
}
