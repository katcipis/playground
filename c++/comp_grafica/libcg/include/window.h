#ifndef WINDOW_H
#define WINDOW_H

#include <QSet>
#include "cg_global.h"
#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "xml_object.h"
#include "curve_hermite.h"

/**
 *  Class that defines a window.
 */
class CGSHARED_EXPORT Window : public XmlObject
{
private:
    QList<Point> points;
    QList<Wire> wires;
    QList<WireFrame> wireframes;
    QList<Curve> curves;

    double height;
    double width;

protected:
    double vUpAngleWithY;
    double vpnAngleWithX;
    double vpnAngleWithY;
    double zoomFactor;

    /**
     *  It is called everytime the window is changed.
     */
    virtual void refresh() = 0;

    virtual Wire adjustMovementVector(const Wire& base) = 0;

    virtual void setCenter(const Point& center) = 0;

public:
    /**
     *  \brief Class constructor.
     *  Constructs a window with the given height/width defining its size.
     *  @param height - the height.
     *  @param width  - the width.
     */
    Window(double height, double width);

    /**
     *  Get the max point.
     *  @return - the max point.
     */
    virtual Point getMaxPoint() const;

    /**
     *  Removes all objects from the window.
     */
    void clear();

    /**
     *  Get the min point.
     *  @return - the min point.
     */
    virtual Point getMinPoint() const;

    /**
     *  Set the window height.
     *  @param height - the height.
     */
    void setHeight(double height);

    /**
     *  Set the window width.
     *  @param width - the width.
     */
    void setWidth(double width);

    /**
     *  Get how much points have been inserted on this window.
     *  @return - the poitns count.
     */
    int getPointsCount() const;

    /**
     *  Get how much wires have been inserted on this window.
     *  @return - the wires count.
     */
    int getWiresCount() const;

    /**
     *  Get the wireframes that have been inserted on this window.
     *  @return - the wireframes.
     */
    virtual const QList<WireFrame>& getWireFrames() const;

    /**
     *  Get the wires that have been inserted on this window.
     *  @return - the wires.
     */
    virtual const QList<Wire>& getWires() const;

    /**
    *  Get the points that have been inserted on this window.
    *  @return - the points.
    */
    virtual const QList<Point>& getPoints() const;

    /**
    *  Get the curves that have been inserted on this window.
    *  @return - the points.
    */
    virtual const QList<Curve>& getCurves() const;

    /**
     *  Get how much wireframes have been inserted on this window.
     *  @return - the wireframes count.
     */
    int getWireFramesCount() const;

    /**
     *  Get how much curves have been inserted on this window.
     *  @return - the curves count.
     */
    int getCurvesCount() const;

    /**
     *  Inserts a point on this window.
     *  @param point - the point to insert.
     */
    void insertPoint(const Point& point);

    /**
     *  Inserts a wire on this window.
     *  @param wire - the wire to insert.
     */
    void insertWire(const Wire& wire);

    /**
     *  Inserts a wireframe on this window.
     *  @param wireframe - the wireframe to insert.
     */
    void insertWireFrame(const WireFrame& wireframe);

    /**
     *  Inserts a curve on this window.
     *  @param curve - the curve to insert.
     */
    void insertCurve(const Curve& curve);

    /**
     *  removes a curve on this window.
     *  @param curve - the curve to remove.
     */
    void removeCurve(const Curve& curve);

    /**
     *  Removes a point (in world coordinates) from this window.
     *  @param point - the point to remove.
     */
    void removePoint(const Point& point);

    /**
     *  Removes a wire (in world coordinates) from this window.
     *  @param wire - the wire to remove.
     */
    void removeWire(const Wire& wire);

    /**
     *  Removes a wireframe (in world coordinates) from this window.
     *  @param wireframe - the wireframe to remove.
     */
    void removeWireFrame(const WireFrame& wireframe);

    /**
     *  Checks if a point (in world coordinates) is inside this window.
     *  @param point - the point to check.
     *  @return - true if the point is inside the window, false otherwise.
     */
    bool hasPoint(const Point& point) const;

    /**
     *  Checks if a wire (in world coordinates) is inside this window.
     *  @param wire - the wire to check.
     *  @return - true if the wire is inside the window, false otherwise.
     */
    bool hasWire(const Wire& wire) const;

    /**
     *  Checks if a curve (in world coordinates) is inside this window.
     *  @param curve - the curve to check.
     *  @return - true if the curve is inside the window, false otherwise.
     */
    bool hasCurve(const Curve& curve) const;

    /**
     *  Checks if a wireframe (in world coordinates) is inside this window.
     *  @param wireframe - the wireframe to check.
     *  @return - true if the wireframe is inside the window, false otherwise.
     */
    bool hasWireFrame(const WireFrame& wireframe) const;

    /**
     *  Get the center of window.
     *  @return - The center point of the window.
     */
    virtual Point getCenter() const = 0;

    /**
     *  Rotate this window around z.
     *  @param angle - the angle in radians.
     */
    virtual void rotateAroundZ(double angle);

    /**
     *  Translate this window up, according to how much points are informed.
     *  @param points - how much points to translate.
     */
    virtual void translateIn(double points);

    /**
     *  Translate this window up, according to how much points are informed.
     *  @param points - how much points to translate.
     */
    virtual void translateOut(double points);

    /**
     *  Rotate this window around the x axis.
     *  @param angle - the angle in radians.
     */
    virtual void rotateAroundX(double angle);

    /**
     *  Rotate this window around the y axis.
     *  @param angle - the angle in radians.
     */
    virtual void rotateAroundY(double angle);

    /**
     *  Makes objects bigger.
     */
    virtual void zoomPlus();

    /**
     *  Makes objects smaller.
     */
    virtual void zoomMinus();

    /**
     *  Translate this window up, according to how much points are informed.
     *  @param points - how much points to translate.
     */
    virtual void translateUp(double points);

    /**
     *  Translate this window down, according to how much points are informed.
     *  @param points - how much points to translate.
     */
    virtual void translateDown(double points);

    /**
     *  Translate this window to the left, according to how much points are informed.
     *  @param points - how much points to translate.
     */
    virtual void translateLeft(double points);

    /**
     *  Translate this window to the right, according to how much points are informed.
     *  @param points - how much points to translate.
     */
    virtual void translateRight(double points);


    /**
     *  Gets a string representation of the window.
     *  @return the string representing the window.
     */
    virtual const QString toString() const;

    /**
     *  Gets the string that represents the entire xml representation.
     *  @return A string, eg: <window name=hi> ...etc ...</window>.
     */
    QString toXML() const;

    /**
     *  Returns the tag name of this element.
     *  @return The tag name.
     */
    QString getTagName() const;
};

#endif // WINDOW_H
