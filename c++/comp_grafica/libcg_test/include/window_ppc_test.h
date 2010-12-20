#ifndef WINDOW_PPC_TEST_H
#define WINDOW_PPC_TEST_H

#include "window_test.h"

class WindowPPCTest : public WindowTest
{
    Q_OBJECT

public:
    WindowPPCTest();

protected:
    virtual Window* getNewWindow(double height, double width);
    
private slots:
    void knowItsOwnMaxPoint();
    void knowItsOwnMinPoint();

    void ifItIsRotatedKnowsTheNewPositionOfAllPoints();
    void ifItIsRotatedKnowsTheNewPositionOfAllWires();
    void ifItIsRotatedKnowsTheNewPositionOfAllWireFrames();
};

#endif // WINDOW_PPC_TEST_H
