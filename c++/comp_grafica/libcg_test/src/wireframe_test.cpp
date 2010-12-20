#include "wireframe_test.h"
#include "cg_exception.h"
#include <QList>


void WireFrameTest::knowsAllTheWiresThatFormsIt()
{
    WireFrame wireframe(ok_wires, false);
    QCOMPARE(ok_wires, wireframe.getWires());
}

void WireFrameTest::everyWireMustTouchThePointOfTwoOtherWires()
{
    WireFrame wireframe(ok_wires, false);
}

void WireFrameTest::ifAWireDoesNotTouchThePointOfTwoOtherWiresAnExceptionIsThrow()
{
    QList<Wire> wires;
    bool has_been_throw = false;

    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(31,30), Point(50,50)));
    wires.append(Wire(Point(50,50), Point(2,2)));

    try{
        WireFrame wireframe(wires, false);
    } catch(CGException& except) {
        has_been_throw = true;
    }

    QVERIFY(has_been_throw);
}

void WireFrameTest::theWiresMustBeOnTheOrderTheyTouchEachOtherToBuildTheWireFrame()
{
    WireFrame wireframe(ok_wires, false);
}

void WireFrameTest::ifTheWiresAreNotOnTheOrderTheyTouchEachOtherAnExceptionIsThrow()
{
    QList<Wire> wrong_order_square;
    QList<Wire> ok_square;

    Wire wire1(Point(1,1), Point(1,30));
    Wire wire2(Point(1,30), Point(30,30));
    Wire wire3(Point(30,30), Point(30,1));
    Wire wire4(Point(30,1), Point(1,1));

    bool has_been_throw = false;

    wrong_order_square.append(wire1);
    wrong_order_square.append(wire3);
    wrong_order_square.append(wire2);
    wrong_order_square.append(wire4);

    ok_square.append(wire1);
    ok_square.append(wire2);
    ok_square.append(wire3);
    ok_square.append(wire4);

    WireFrame ok_wireframe(ok_square, false);

    try{
        WireFrame wireframe(wrong_order_square, false);
    } catch(CGException& except) {
        has_been_throw = true;
    }

    QVERIFY(has_been_throw);
}

void WireFrameTest::ifThereIsTwoIdenticalWiresAnExceptionIsThrow()
{
    QList<Wire> wires;
    bool has_been_throw = false;

    wires.append(Wire(Point(2,2), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(2,2)));
    wires.append(Wire(Point(2,2), Point(30,30)));

    try{
        WireFrame wireframe(wires, false);
    } catch(CGException& except) {
        has_been_throw = true;
    }

    QVERIFY(has_been_throw);
}

void WireFrameTest::ifAllTheWiresOfTwoWireFramesAreEqualThenTheyAreEqual()
{
    QList<Wire> square2;
    QList<Wire> square;

    Wire wire1(Point(1,1), Point(1,30));
    Wire wire2(Point(1,30), Point(30,30));
    Wire wire3(Point(30,30), Point(30,1));
    Wire wire4(Point(30,1), Point(1,1));


    square.append(wire1);
    square.append(wire2);
    square.append(wire3);
    square.append(wire4);

    square2.append(wire4);
    square2.append(wire3);
    square2.append(wire2);
    square2.append(wire1);

    QCOMPARE(WireFrame(square, false), WireFrame(square2, false));
}

void WireFrameTest::ifOneOfTheWiresOfTwoWireFramesAreNotEqualThenTheyAreNotEqual()
{
    QList<Wire> other;
    QList<Wire> square;

    square.append(Wire(Point(1,1), Point(1,30)));
    square.append(Wire(Point(1,30), Point(30,30)));
    square.append(Wire(Point(30,30), Point(30,1)));
    square.append(Wire(Point(30,1), Point(1,1)));

    other.append(Wire(Point(1,1), Point(1,60)));
    other.append(Wire(Point(1,60), Point(30,30)));
    other.append(Wire(Point(30,30), Point(30,1)));
    other.append(Wire(Point(30,1), Point(1,1)));

    QVERIFY(WireFrame(square, false) != WireFrame(other, false));
}

ColoredGeometricShape WireFrameTest::getColoredGeometricShape(int red, int green, int blue)
{
    return WireFrame(ok_wires, false, red, green, blue);
}

WireFrameTest::WireFrameTest()
{
    ok_wires.append(Wire(Point(2,2), Point(30,30)));
    ok_wires.append(Wire(Point(30,30), Point(50,50)));
    ok_wires.append(Wire(Point(50,50), Point(2,2)));
}

void WireFrameTest::knowsItsCenter()
{
    QList<Wire> wires;
    wires.append(Wire(Point(1,1), Point(1,30)));
    wires.append(Wire(Point(1,30), Point(30,30)));
    wires.append(Wire(Point(30,30), Point(30,1)));
    wires.append(Wire(Point(30,1), Point(1,1)));

    WireFrame wireframe(wires, false);
    Point center(15.5, 15.5);

    QCOMPARE(center, wireframe.getCenter());
}
