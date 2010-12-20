#ifndef WINDOW_PERSPECTIVE_H
#define WINDOW_PERSPECTIVE_H

#include "window.h"

/**
 *  Class that defines a window using perspective to implement 3D objects.
 */
class CGSHARED_EXPORT WindowPerspective : public Window
{
public:

    /**
     *  \brief Class constructor.
     *  Constructs a window with the given height/width defining its size.
     *  @param height - the height.
     *  @param width  - the width.
     */
    WindowPerspective(double height, double width);

    /**
     *  Get the center of window.
     *  @return - The center point of the window.
     */
    Point getCenter() const;

    /**
     *  Get the wireframes that have been inserted on this window in 3D coordinates.
     *  @return - the wireframes.
     */
    virtual const QList<WireFrame>& getWireFrames() const;

    /**
     *  Get the wires that have been inserted on this window in 3D coordinates.
     *  @return - the wires.
     */
    virtual const QList<Wire>& getWires() const;

    /**
    *  Get the points that have been inserted on this window in 3D coordinates.
    *  @return - the points.
    */
    virtual const QList<Point>& getPoints() const;

    /**
     *  Gets a string representation of the 3D window.
     *  @return the string representing the 3D window.
     */
    virtual const QString toString() const;


protected:
    /**
     *  It is called everytime the window is changed.
     */
    void refresh();

    void setCenter(const Point& center);

    Wire adjustMovementVector(const Wire& base);


private:
    QList<Point> points3D;
    QList<Wire> wires3D;
    QList<WireFrame> wireframes3D;
    Point cop;
    double d;

    Point getPointProjection(const Point& point);
    QList<Wire> getWiresProjection(const QList<Wire>& wires);
    WireFrame getWireFrameProjection(const WireFrame& wireframe);
};

#endif // WINDOW_PERSPECTIVE_H
