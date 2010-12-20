#ifndef WIREFRAME_TEST_H
#define WIREFRAME_TEST_H

#include <QObject>
#include "colored_geometric_shape_test.h"
#include "wireframe.h"

class WireFrameTest : public ColoredGeometricShapeTest
{
    Q_OBJECT
private slots:
    void knowsAllTheWiresThatFormsIt();
    void knowsItsCenter();
    void everyWireMustTouchThePointOfTwoOtherWires();
    void ifAWireDoesNotTouchThePointOfTwoOtherWiresAnExceptionIsThrow();
    void theWiresMustBeOnTheOrderTheyTouchEachOtherToBuildTheWireFrame();
    void ifTheWiresAreNotOnTheOrderTheyTouchEachOtherAnExceptionIsThrow();
    void ifThereIsTwoIdenticalWiresAnExceptionIsThrow();
    void ifAllTheWiresOfTwoWireFramesAreEqualThenTheyAreEqual();
    void ifOneOfTheWiresOfTwoWireFramesAreNotEqualThenTheyAreNotEqual();

private:
    QList<Wire> ok_wires;

protected:
    ColoredGeometricShape getColoredGeometricShape(int red, int green, int blue);

public:
    WireFrameTest();
};

#endif // WIREFRAME_TEST_H

