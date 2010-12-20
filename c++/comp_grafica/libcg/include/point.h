#ifndef POINT_H
#define POINT_H

#include "cg_global.h"
#include "matrix.h"
#include "colored_geometric_shape.h"
#include "xml_object.h"

/**
 *  Class that defines a point.
 */
class CGSHARED_EXPORT Point : public ColoredGeometricShape, public XmlObject
{
private:
    double x;
    double y;
    double z;
    Matrix matrix;

    void defineMatriz();

public:
    /**
     *  \brief Default Class constructor.
     *  Constructs a Null point.
     */
    Point();

    /**
     *  \brief Class constructor.
     *  Constructs a point with the given coordinates (x, y, z).
     *  @param x - the x coordinate
     *  @param y - the y coordinate
     *  @param z - the z coordinate
     */
    Point(double x, double y, double z = 1.0);

    /**
     *  \brief Class constructor.
     *  Constructs a point with the given coordinates (x, y, z) and the given color on RGB.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     *  @param x - the x coordinate
     *  @param y - the y coordinate
     *  @param z - the z coordinate
     */
    Point(int red, int green, int blue, double x, double y, double z = 1.0);

    /**
     *  \brief Class constructor.
     *  Constructs a point with the given coordinates on the 1X3 matrix [x,y,z].
     *  @param matrix - The 1X3 matrix with the coordinates.
     */
    Point(const Matrix& matrix, int red = 0, int green = 0, int blue = 0);

    /**
     *  Get the x coordinate
     *  @return - the x coordinate.
     */
    double getX() const;

    /**
     *  Get the y coordinate
     *  @return - the y coordinate.
     */
    double getY() const;

    /**
     *  Get the z coordinate
     *  @return - the z coordinate.
     */
    double getZ() const;

    /**
     *  Get a matrix representing this point.
     *  @return - the matrix with 1 row and 3 columns.
     */
    const Matrix& toMatrix() const;

    /**
     *  Compares if two points are equal.
     *  @param other - the other point.
     *  @return true if the two points are equal.
     */
    virtual bool operator==(const Point &other) const;

    /**
     *  Compares if two points are not equal.
     *  @param other - the other point.
     *  @return true if the two points are not equal.
     */
    virtual bool operator!=(const Point &other) const;

    /**
     *  Gets a string representation of the point.
     *  @return the string representing the point.
     */
    virtual const QString toString () const;

    /**
     *  Gets the string that represents part of the xml representation without the tag start and the tag name.
     *  @return A XML string, eg: "cor=FFAABB x=1.0, y=2.0, z=0.5/>".
     */
    QString toXML() const;

    /**
     *  Gets the string that represents part of the xml representation without the tag start, tag name and color.
     *  @return A XML string, eg: "x=1.0, y=2.0, z=0.5/>".
     */
    QString toXMLColorless() const;

    /**
     *  Returns the tag name of this element
     *  @return The tag name.
     */
    QString getTagName() const;
};

#endif // POINT_H
