#include "window_ppc_clipped_test.h"
#include "window_ppc.h"

Window* WindowPPCClippedTest::getNewWindow(double height, double width)
{
    return new WindowPPC(height, width);
}


void WindowPPCClippedTest::ifAPointIsNotInsideTheWindowVisibleAreaItWillNotBeOnThePointList()
{
    Point outside1(Point(15,11));
    Point outside2(Point(16,10));

    Point outside3(Point(-15,-11));
    Point outside4(Point(-16,-10));

    Point outside5(Point(15,-11));
    Point outside6(Point(16,-10));

    Point outside7(Point(-15,11));
    Point outside8(Point(-16,10));

    this->window->setHeight(20);
    this->window->setWidth(30);

    this->window->insertPoint(outside1);
    this->window->insertPoint(outside2);
    this->window->insertPoint(outside3);
    this->window->insertPoint(outside4);
    this->window->insertPoint(outside5);
    this->window->insertPoint(outside6);
    this->window->insertPoint(outside7);
    this->window->insertPoint(outside8);

    const QList<Point> points = this->window->getPoints();

    QCOMPARE(points.size(), 0);
    QVERIFY(!points.contains(outside1));
    QVERIFY(!points.contains(outside2));
    QVERIFY(!points.contains(outside3));
    QVERIFY(!points.contains(outside4));
    QVERIFY(!points.contains(outside5));
    QVERIFY(!points.contains(outside6));
    QVERIFY(!points.contains(outside7));
    QVERIFY(!points.contains(outside8));
}

void WindowPPCClippedTest::ifAPointIsInsideTheWindowVisibleAreaItWillBeOnThePointList()
{
    Point inside1(Point(15,9));
    Point inside2(Point(14,10));
    Point inside3(Point(15,10));

    Point inside4(Point(-15,-9));
    Point inside5(Point(-14,-10));
    Point inside6(Point(-15,-10));

    Point inside7(Point(15,-9));
    Point inside8(Point(14,-10));
    Point inside9(Point(15,-10));

    Point inside10(Point(-15,9));
    Point inside11(Point(-14,10));
    Point inside12(Point(-15,10));

    this->window->setHeight(20);
    this->window->setWidth(30);

    this->window->insertPoint(inside1);
    this->window->insertPoint(inside2);
    this->window->insertPoint(inside3);
    this->window->insertPoint(inside4);
    this->window->insertPoint(inside5);
    this->window->insertPoint(inside6);
    this->window->insertPoint(inside7);
    this->window->insertPoint(inside8);
    this->window->insertPoint(inside9);
    this->window->insertPoint(inside10);
    this->window->insertPoint(inside11);
    this->window->insertPoint(inside12);

    const QList<Point> points = this->window->getPoints();

    QCOMPARE(points.size(), 12);
    QVERIFY(points.contains(inside1));
    QVERIFY(points.contains(inside2));
    QVERIFY(points.contains(inside3));
    QVERIFY(points.contains(inside4));
    QVERIFY(points.contains(inside5));
    QVERIFY(points.contains(inside6));
    QVERIFY(points.contains(inside7));
    QVERIFY(points.contains(inside8));
}

void WindowPPCClippedTest::ifAWireIsNotInsideTheWindowVisibleAreaItWillNotBeOnTheWireList()
{
}

void WindowPPCClippedTest::ifAWireIsPartiallyInsideTheWindowVisibleAreaItWillBeClipped()
{
}

void WindowPPCClippedTest::ifAWireIsInsideTheWindowVisibleAreaItWillBeOnTheWireList()
{
}

void WindowPPCClippedTest::ifAWireFrameIsNotInsideTheWindowVisibleAreaItWillNotBeOnTheWireFrameList()
{
}

void WindowPPCClippedTest::ifAWireFrameIsPartiallyInsideTheWindowVisibleAreaItWillBeClipped()
{
}

void WindowPPCClippedTest::ifAWireFrameIsInsideTheWindowVisibleAreaItWillBeOnTheWireFrameList()
{
}

