#ifndef WIRE_H
#define WIRE_H

#include "cg_global.h"
#include "point.h"

/**
 *  Class that defines a Wire.
 */
class CGSHARED_EXPORT Wire : public ColoredGeometricShape, public XmlObject
{
private:
    Point first_point;
    Point second_point;
    bool isNull;

public:
    /**
     *  \brief Class constructor.
     *  Constructs a wire with the given two points defining its length.
     *  @param point1 - the first  point.
     *  @param point2 - the second point.
     *  @param red    - Amount of red of the wireframe.
     *  @param green  - Amount of green of the wireframe.
     *  @param blue   - Amount of blue of the wireframe.
     */
    Wire(const Point& point1, const Point& point2, int red = 0, int green = 0, int blue = 0);

    /**
     *  \brief Class constructor.
     *  Constructs a null wire.
     */
    Wire();

    /**
     *  Get the first point.
     *  @return - the first point.
     */
    const Point& getFirstPoint() const;

    /**
     *  Get the second point.
     *  @return - the second point.
     */
    const Point& getSecondPoint() const;

    /**
     *  Get the center point of this wire.
     *  @return - the center point.
     */
    Point getCenter() const;

    /**
     *  Compares if two wires are equal.
     *  @param other - the other wire.
     *  @return true if the two wires are equal.
     */
    bool operator==(const Wire &other) const;

    /**
     *  Compares if two wires are not equal.
     *  @param other - the other wire.
     *  @return true if the two wires are not equal.
     */
    bool operator!=(const Wire &other) const;

    /**
     *  Gets a string representation of the wire.
     *  @return the string representing the wire.
     */
    const QString toString () const;

    /**
     *  Gets the string that represents part of the xml representation without the tag start and the tag name.
     *  @return A string, eg: "> ...etc </reta>".
     */
    QString toXML() const;

    /**
     *  Returns the tag name of this element
     *  @return The tag name.
     */
    QString getTagName() const;
};

#endif // WIRE_H
