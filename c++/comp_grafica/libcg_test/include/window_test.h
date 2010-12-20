#ifndef WINDOW_TEST_H
#define WINDOW_TEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "window.h"

class WindowTest : public QObject
{
    Q_OBJECT

protected:
    Window *window;

    virtual Window* getNewWindow(double height, double width) = 0;

    virtual void knowItsOwnMaxPoint() = 0;
    virtual void knowItsOwnMinPoint() = 0;

    virtual void ifItIsRotatedKnowsTheNewPositionOfAllPoints() = 0;
    virtual void ifItIsRotatedKnowsTheNewPositionOfAllWires() = 0;
    virtual void ifItIsRotatedKnowsTheNewPositionOfAllWireFrames() = 0;

private slots:
    void init();
    void cleanup();

    void knowItsCenterPoint();
    void afterIsRotatedTheCenterPointWontChange();

    void knowsHowMuchWiresAreInside();
    void knowsHowMuchPointsAreInside();
    void knowsHowMuchWireFramesAreInside();

    void afterInsertingAWireItWillBeOnTheWindow();
    void afterInsertingACurveItWillBeOnTheWindow();
    void afterInsertingAPointItWillBeOnTheWindow();
    void afterInsertingAWireframeItWillBeOnTheWindow();

    void ifAWireWasNotInsertedItWillNotBeOnTheWindow();
    void ifACurveWasNotInsertedItWillNotBeOnTheWindow();
    void ifAPointWasNotInsertedItWillNotBeOnTheWindow();
    void ifAWireFrameWasNotInsertedItWillNotBeOnTheWindow();

    void afterRemovingAWireItWillNotBeOnTheWindow();
    void afterRemovingACurveItWillNotBeOnTheWindow();
    void afterRemovingAPointItWillNotBeOnTheWindow();
    void afterRemovingAWireframeItWillNotBeOnTheWindow();

    void ifAWireThatIsNotOnTheWindowIsRemovedNothingHappens();
    void ifACurveThatIsNotOnTheWindowIsRemovedNothingHappens();
    void ifAPointThatIsNotOnTheWindowIsRemovedNothingHappens();
    void ifAWireFrameThatIsNotOnTheWindowIsRemovedNothingHappens();

    void ifTwoEqualWiresAreInsertedBothWillBeOnTheWindow();
    void ifTwoEqualCurvesAreInsertedBothWillBeOnTheWindow();
    void ifTwoEqualPointsAreInsertedBothWillBeOnTheWindow();
    void ifTwoEqualWireFramesAreInsertedBothWillBeOnTheWindow();

    void ifThereIsTwoEqualWiresAndOneIsRemovedTheOtherStays();
    void ifThereIsTwoEqualCurvesAndOneIsRemovedTheOtherStays();
    void ifThereIsTwoEqualPointsAndOneIsRemovedTheOtherStays();
    void ifThereIsTwoEqualWireFramessAndOneIsRemovedTheOtherStays();

    void afterItIsRotatedToRemoveAPointTheOriginalPointMustBeInformed();
    void afterItIsRotatedToRemoveACurveTheOriginalCurveMustBeInformed();
    void afterItIsRotatedToRemoveAWireTheOriginalWireMustBeInformed();
    void afterItIsRotatedToRemoveAWireFrameTheOriginalWireFrameMustBeInformed();

    void afterItIsRotatedCanInformOnlyIfTheOriginalPointIsInsideTheWindow();
    void afterItIsRotatedCanInformOnlyIfTheOriginalCurveIsInsideTheWindow();
    void afterItIsRotatedCanInformOnlyIfTheOriginalWireIsInsideTheWindow();
    void afterItIsRotatedCanInformOnlyIfTheOriginalWireFrameIsInsideTheWindow();

private:
    Point min_point;
    Point max_point;

public:
    WindowTest();
};

#endif // WINDOW_TEST_H
