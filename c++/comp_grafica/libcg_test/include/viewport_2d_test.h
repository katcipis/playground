#ifndef VIEWPORT_2D_TEST_H
#define VIEWPORT_2D_TEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "viewport_2d.h"

class ViewPort2DTest : public QObject
{
    Q_OBJECT
private slots:
    void canTransformAWindowPointToAViewPortPoint();
    void canTransformAWindowWireToAViewPortWire();
    void canTransformAWindowWireFramePointToAViewPortWireFrame();

public:
    ViewPort2DTest();
};

#endif // VIEWPORT_2D_TEST_H
