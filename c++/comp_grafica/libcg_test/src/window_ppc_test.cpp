#include "window_ppc_test.h"
#include "window_ppc.h"
#include "cg_exception.h"
#include "transform.h"
#include <cmath>
#include <iostream>

WindowPPCTest::WindowPPCTest()
{
}

Window* WindowPPCTest::getNewWindow(double height, double width)
{
    return new WindowPPC(height, width);
}

void WindowPPCTest::ifItIsRotatedKnowsTheNewPositionOfAllPoints()
{
    Point orig(30.0, 30.0);
    Point cpp(ceil(30.0), ceil(30.0));
    Point cppPlus(ceil(24.3348), ceil(34.7537));
    Point cppMinus(ceil(34.7537), ceil(24.3348));

    this->window->setWidth(810.0);
    this->window->setHeight(651.0);
    this->window->insertPoint(orig);

    /* we have some problem with double values that are almost the same due to the operations, lets ceil the values */

    QCOMPARE(cpp, Point(ceil(this->window->getPoints()[0].getX()), ceil(this->window->getPoints()[0].getY())));
    this->window->rotateAroundZ(transform::fromDegreeToRadian(10));
    QCOMPARE(cppPlus, Point(ceil(this->window->getPoints()[0].getX()), ceil(this->window->getPoints()[0].getY())));
    this->window->rotateAroundZ(transform::fromDegreeToRadian(-10));
    QCOMPARE(cpp, Point(ceil(this->window->getPoints()[0].getX()), ceil(this->window->getPoints()[0].getY())));
    this->window->rotateAroundZ(transform::fromDegreeToRadian(-10));
    QCOMPARE(cppMinus, Point(ceil(this->window->getPoints()[0].getX()), ceil(this->window->getPoints()[0].getY())));
}

void WindowPPCTest::ifItIsRotatedKnowsTheNewPositionOfAllWires()
{
    //TODO
}

void WindowPPCTest::ifItIsRotatedKnowsTheNewPositionOfAllWireFrames()
{
    //TODO
}

void WindowPPCTest::knowItsOwnMaxPoint()
{
    Point ppcMaxPoint(405.0, 325.5);
    this->window->setWidth(810.0);
    this->window->setHeight(651.0);

    QCOMPARE(ppcMaxPoint, this->window->getMaxPoint());
}

void WindowPPCTest::knowItsOwnMinPoint()
{
    Point ppcMinPoint(-405.0, -325.5);
    this->window->setWidth(810.0);
    this->window->setHeight(651.0);

    QCOMPARE(ppcMinPoint, this->window->getMinPoint());
}
