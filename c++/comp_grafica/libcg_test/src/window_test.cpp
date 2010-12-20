#include "window_test.h"

WindowTest::WindowTest() : min_point(-150,-150), max_point(150,150)
{
}

void WindowTest::init()
{
    min_point = Point(-150,-150);
    max_point = Point(150,150);
    window    = getNewWindow(300, 300);
}

void WindowTest::cleanup()
{
    delete window;
    window = NULL;
}

void WindowTest::knowsHowMuchWiresAreInside()
{
    window->insertWire(Wire(Point(2,2), Point(4,4)));
    window->insertWire(Wire(Point(2,1), Point(4,3)));
    window->insertWire(Wire(Point(3,2), Point(4,2)));
    QCOMPARE(3, window->getWiresCount());
}

void WindowTest::knowsHowMuchWireFramesAreInside()
{
    QList<Wire> wires1;
    QList<Wire> wires2;
    QList<Wire> wires3;

    wires1.append(Wire(Point(2,2), Point(30,30)));
    wires1.append(Wire(Point(30,30), Point(50,50)));
    wires1.append(Wire(Point(50,50), Point(2,2)));

    wires2.append(Wire(Point(10,10), Point(30,30)));
    wires2.append(Wire(Point(30,30), Point(50,50)));
    wires2.append(Wire(Point(50,50), Point(10,10)));

    wires3.append(Wire(Point(5,5), Point(30,30)));
    wires3.append(Wire(Point(30,30), Point(50,50)));
    wires3.append(Wire(Point(50,50), Point(100,100)));
    wires3.append(Wire(Point(100,100), Point(5,5)));

    window->insertWireFrame(WireFrame(wires1, false));
    window->insertWireFrame(WireFrame(wires2, false));
    window->insertWireFrame(WireFrame(wires3, false));

    QCOMPARE(3, window->getWireFramesCount());
}

void WindowTest::afterInsertingAWireItWillBeOnTheWindow()
{
    Wire wire(Point(2,2), Point(4,4));
    window->insertWire(wire);
    QVERIFY(window->hasWire(wire));
}

void WindowTest::afterInsertingAWireframeItWillBeOnTheWindow()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));

    WireFrame wireframe(wires, false);
    window->insertWireFrame(wireframe);
    QVERIFY(window->hasWireFrame(wireframe));
}

void WindowTest::ifAWireWasNotInsertedItWillNotBeOnTheWindow()
{
    Wire wire(Point(2,2), Point(4,4));
    QVERIFY(!window->hasWire(wire));
}

void WindowTest::ifAWireFrameWasNotInsertedItWillNotBeOnTheWindow()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));

    WireFrame wireframe(wires, false);
    QVERIFY(!window->hasWireFrame(wireframe));
}

void WindowTest::afterRemovingAWireItWillNotBeOnTheWindow()
{
    Wire wire(Point(2,2), Point(4,4));
    window->insertWire(wire);
    QVERIFY(window->hasWire(wire));
    window->removeWire(wire);
    QVERIFY(!window->hasWire(wire));
}

void WindowTest::afterRemovingACurveItWillNotBeOnTheWindow()
{
    CurveHermite curve(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100);
    window->insertCurve(curve);
    QVERIFY(window->hasCurve(curve));
    window->removeCurve(curve);
    QVERIFY(!window->hasCurve(curve));
}

void WindowTest::afterRemovingAWireframeItWillNotBeOnTheWindow()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));

    WireFrame wireframe(wires, false);
    window->insertWireFrame(wireframe);
    QVERIFY(window->hasWireFrame(wireframe));
    window->removeWireFrame(wireframe);
    QVERIFY(!window->hasWireFrame(wireframe));
}

void WindowTest::ifAWireThatIsNotOnTheWindowIsRemovedNothingHappens()
{
    window->removeWire(Wire(Point(2,2), Point(4,4)));
}

void WindowTest::ifACurveThatIsNotOnTheWindowIsRemovedNothingHappens()
{
    window->removeCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100));
}

void WindowTest::ifAWireFrameThatIsNotOnTheWindowIsRemovedNothingHappens()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));
    window->removeWireFrame(WireFrame(wires, false));
}

void WindowTest::ifTwoEqualCurvesAreInsertedBothWillBeOnTheWindow()
{
    CurveHermite curve1(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100);
    CurveHermite curve2(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100);

    window->insertCurve(curve1);
    window->insertCurve(curve2);

    QVERIFY(window->hasCurve(curve1));
    QVERIFY(window->hasCurve(curve2));
    QCOMPARE(2, window->getCurvesCount());
}

void WindowTest::ifTwoEqualWiresAreInsertedBothWillBeOnTheWindow()
{
    Wire wire1(Point(2,2), Point(4,4));
    Wire wire2(Point(4,4), Point(2,2));

    window->insertWire(wire1);
    window->insertWire(wire2);

    QVERIFY(window->hasWire(wire1));
    QVERIFY(window->hasWire(wire2));
    QCOMPARE(2, window->getWiresCount());
}

void WindowTest::ifTwoEqualWireFramesAreInsertedBothWillBeOnTheWindow()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));

    WireFrame wireframe1(wires, false);
    WireFrame wireframe2(wires, false);

    window->insertWireFrame(wireframe1);
    window->insertWireFrame(wireframe2);

    QVERIFY(window->hasWireFrame(wireframe1));
    QVERIFY(window->hasWireFrame(wireframe2));
    QCOMPARE(2, window->getWireFramesCount());
}

void WindowTest::ifThereIsTwoEqualCurvesAndOneIsRemovedTheOtherStays()
{
    CurveHermite curve1(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100);
    CurveHermite curve2(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100);

    window->insertCurve(curve1);
    window->insertCurve(curve2);

    QVERIFY(window->hasCurve(curve1));
    QVERIFY(window->hasCurve(curve2));
    QCOMPARE(2, window->getCurvesCount());

    window->removeCurve(curve1);

    QVERIFY(window->hasCurve(curve1));
    QVERIFY(window->hasCurve(curve2));
    QCOMPARE(1, window->getCurvesCount());
}

void WindowTest::ifThereIsTwoEqualWiresAndOneIsRemovedTheOtherStays()
{
    Wire wire1(Point(2,2), Point(4,4));
    Wire wire2(Point(4,4), Point(2,2));

    window->insertWire(wire1);
    window->insertWire(wire2);

    QVERIFY(window->hasWire(wire1));
    QVERIFY(window->hasWire(wire2));
    QCOMPARE(2, window->getWiresCount());

    window->removeWire(wire1);

    QVERIFY(window->hasWire(wire1));
    QVERIFY(window->hasWire(wire2));
    QCOMPARE(1, window->getWiresCount());
}

void WindowTest::ifThereIsTwoEqualWireFramessAndOneIsRemovedTheOtherStays()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));

    WireFrame wireframe1(wires, false);
    WireFrame wireframe2(wires, false);

    window->insertWireFrame(wireframe1);
    window->insertWireFrame(wireframe2);

    QVERIFY(window->hasWireFrame(wireframe1));
    QVERIFY(window->hasWireFrame(wireframe2));
    QCOMPARE(2, window->getWireFramesCount());

    window->removeWireFrame(wireframe1);

    QVERIFY(window->hasWireFrame(wireframe1));
    QVERIFY(window->hasWireFrame(wireframe2));
    QCOMPARE(1, window->getWireFramesCount());
}

void WindowTest::knowsHowMuchPointsAreInside()
{
    window->insertPoint(Point(1,1));
    window->insertPoint(Point(1,2));
    window->insertPoint(Point(3,1));

    QCOMPARE(3, window->getPointsCount());
}

void WindowTest::afterInsertingAPointItWillBeOnTheWindow()
{
    window->insertPoint(Point(1,1));
    QVERIFY(window->hasPoint(Point(1,1)));
}

void WindowTest::afterInsertingACurveItWillBeOnTheWindow()
{
    window->insertCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100));
    QVERIFY(window->hasCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100)));
}

void WindowTest::ifACurveWasNotInsertedItWillNotBeOnTheWindow()
{
    QVERIFY(!window->hasCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100)));
}

void WindowTest::ifAPointWasNotInsertedItWillNotBeOnTheWindow()
{
    QVERIFY(!window->hasPoint(Point(1,1)));
}

void WindowTest::afterRemovingAPointItWillNotBeOnTheWindow()
{
    window->insertPoint(Point(1,1));
    QVERIFY(window->hasPoint(Point(1,1)));
    window->removePoint(Point(1,1));
    QVERIFY(!window->hasPoint(Point(1,1)));
}

void WindowTest::ifAPointThatIsNotOnTheWindowIsRemovedNothingHappens()
{
    window->removePoint(Point(1,1));
}

void WindowTest::ifTwoEqualPointsAreInsertedBothWillBeOnTheWindow()
{
    window->insertPoint(Point(1,1));
    window->insertPoint(Point(1,1));

    QCOMPARE(2, window->getPointsCount());
}

void WindowTest::ifThereIsTwoEqualPointsAndOneIsRemovedTheOtherStays()
{
    window->insertPoint(Point(1,1));
    window->insertPoint(Point(1,1));

    QCOMPARE(2, window->getPointsCount());
    window->removePoint(Point(1,1));
    QCOMPARE(1, window->getPointsCount());
}

void WindowTest::knowItsCenterPoint()
{
    QCOMPARE(Point(0,0), window->getCenter());
}

void WindowTest::afterIsRotatedTheCenterPointWontChange()
{
    Point center(0, 0);

    QCOMPARE(center, window->getCenter());
    window->rotateAroundZ(1.5);
    QCOMPARE(center, window->getCenter());
}

void WindowTest::afterItIsRotatedToRemoveAPointTheOriginalPointMustBeInformed()
{
    window->insertPoint(Point(1,1));
    QVERIFY(window->hasPoint(Point(1,1)));
    window->rotateAroundZ(0.9);
    window->removePoint(Point(1,1));
    QVERIFY(!window->hasPoint(Point(1,1)));
}

void WindowTest::afterItIsRotatedToRemoveACurveTheOriginalCurveMustBeInformed()
{
    window->insertCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100));
    QVERIFY(window->hasCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100)));
    window->rotateAroundZ(-1.5);
    window->removeCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100));
    QVERIFY(!window->hasCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100)));
}

void WindowTest::afterItIsRotatedToRemoveAWireTheOriginalWireMustBeInformed()
{
    Wire wire(Point(2,2), Point(4,4));
    window->insertWire(wire);
    QVERIFY(window->hasWire(wire));
    window->rotateAroundZ(1.2);
    window->removeWire(wire);
    QVERIFY(!window->hasWire(wire));
}

void WindowTest::afterItIsRotatedToRemoveAWireFrameTheOriginalWireFrameMustBeInformed()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));
    window->insertWireFrame(WireFrame(wires, false));

    QVERIFY(window->hasWireFrame(WireFrame(wires, false)));
    window->rotateAroundZ(1.2);
    window->removeWireFrame(WireFrame(wires, false));
    QVERIFY(!window->hasWireFrame(WireFrame(wires, false)));
}

void WindowTest::afterItIsRotatedCanInformOnlyIfTheOriginalCurveIsInsideTheWindow()
{
    window->insertCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100));
    QVERIFY(window->hasCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100)));
    window->rotateAroundZ(-0.5);
    QVERIFY(window->hasCurve(CurveHermite(Point(2,2), Point(4,4), Point(-2,-2), Point(8,8), 100)));
}

void WindowTest::afterItIsRotatedCanInformOnlyIfTheOriginalPointIsInsideTheWindow()
{
    window->insertPoint(Point(1,1));
    QVERIFY(window->hasPoint(Point(1,1)));
    window->rotateAroundZ(0.9);
    QVERIFY(window->hasPoint(Point(1,1)));
}

void WindowTest::afterItIsRotatedCanInformOnlyIfTheOriginalWireIsInsideTheWindow()
{
    Wire wire(Point(2,2), Point(4,4));
    window->insertWire(wire);
    QVERIFY(window->hasWire(wire));
    window->rotateAroundZ(1.2);
    QVERIFY(window->hasWire(wire));
}

void WindowTest::afterItIsRotatedCanInformOnlyIfTheOriginalWireFrameIsInsideTheWindow()
{
    QList<Wire> wires;
    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));
    window->insertWireFrame(WireFrame(wires, false));

    QVERIFY(window->hasWireFrame(WireFrame(wires, false)));
    window->rotateAroundZ(1.2);
    QVERIFY(window->hasWireFrame(WireFrame(wires, false)));
}

