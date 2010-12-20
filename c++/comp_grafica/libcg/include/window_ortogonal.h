#ifndef WINDOW_ORTOGONAL_H
#define WINDOW_ORTOGONAL_H

#include "window.h"

/**
 *  Class that defines a window using ortogonal perspective to implement 3D objects.
 */
class CGSHARED_EXPORT WindowOrtogonal : public Window
{
public:

    /**
     *  \brief Class constructor.
     *  Constructs a window with the given height/width defining its size.
     *  @param height - the height.
     *  @param width  - the width.
     */
    WindowOrtogonal(double height, double width);

    /**
     *  \brief Class constructor.
     *  Constructs a window with the given parameters.
     *  @param min    - the min point of the window.
     *  @param max    - the max point of the window.
     *  @param center - the center of the window.
     */
    WindowOrtogonal(const Point& min, const Point& max, const Point& center);

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
    Point vrp;
};

#endif // WINDOW_ORTOGONAL_H
