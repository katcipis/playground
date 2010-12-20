#ifndef WINDOW_PPC_CLIPPED_TEST_H
#define WINDOW_PPC_CLIPPED_TEST_H

#include "window_ppc_test.h"

class WindowPPCClippedTest : public WindowPPCTest
{
    Q_OBJECT

protected:
    Window* getNewWindow(double height, double width);

private slots:
    void ifAPointIsNotInsideTheWindowVisibleAreaItWillNotBeOnThePointList();
    void ifAPointIsInsideTheWindowVisibleAreaItWillBeOnThePointList();

    void ifAWireIsNotInsideTheWindowVisibleAreaItWillNotBeOnTheWireList();
    void ifAWireIsPartiallyInsideTheWindowVisibleAreaItWillBeClipped();
    void ifAWireIsInsideTheWindowVisibleAreaItWillBeOnTheWireList();

    void ifAWireFrameIsNotInsideTheWindowVisibleAreaItWillNotBeOnTheWireFrameList();
    void ifAWireFrameIsPartiallyInsideTheWindowVisibleAreaItWillBeClipped();
    void ifAWireFrameIsInsideTheWindowVisibleAreaItWillBeOnTheWireFrameList();
};

#endif // WINDOW_PPC_CLIPPED_TEST_H
