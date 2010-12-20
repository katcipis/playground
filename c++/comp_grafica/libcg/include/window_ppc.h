#ifndef WINDOW_PPC_H
#define WINDOW_PPC_H

#include "window.h"

/**
 *  Class that defines a window that uses the PPC method to rotate.
 */

class CGSHARED_EXPORT WindowPPC : public Window
{
public:
    /**
     *  \brief Class constructor.
     *  Constructs a window with the given height/width defining its size.
     *  @param height - the height.
     *  @param width  - the width.
     */
    WindowPPC(double height, double width);

    /**
     *  Get the max point on PPC coordinates.
     *  @return - the max point.
     */
    Point getMaxPoint() const;

    /**
     *  Get the min point on PPC coordinates.
     *  @return - the min point.
     */
    Point getMinPoint() const;

    /**
     *  Get the wireframes that have been inserted on this window in PPC coordinates.
     *  @return - the wireframes.
     */
    virtual const QList<WireFrame>& getWireFrames() const;

    /**
     *  Get the wires that have been inserted on this window in PPC coordinates.
     *  @return - the wires.
     */
    virtual const QList<Wire>& getWires() const;

    /**
    *  Get the points that have been inserted on this window in PPC coordinates.
    *  @return - the points.
    */
    virtual const QList<Point>& getPoints() const;


    /**
     *  Get the center of window.
     *  @return - The center point of the window.
     */
    Point getCenter() const;

    /**
     *  Gets a string representation of the PPC window.
     *  @return the string representing the PPC window.
     */
    virtual const QString toString() const;


protected:

    /**
     *  It is called everytime the window is changed.
     */
    virtual void refresh();

    void setCenter(const Point& center);

    Wire adjustMovementVector(const Wire& base);


private:
    Point center;
    Point minPPC;
    Point maxPPC;
    QList<Point> ppcPoints;
    QList<Wire> ppcWires;
    QList<WireFrame> ppcWireFrames;

    void generatePPCCoordinates();
    void generateObjectsPPC(const Matrix& trans);
    void generateWindowPPC();
    Wire rotateOnFirstPoint(const Wire& base);
};

#endif // WINDOW_PPC_H
