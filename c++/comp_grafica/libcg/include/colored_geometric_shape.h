#ifndef COLORED_GEOMETRIC_SHAPE_H
#define COLORED_GEOMETRIC_SHAPE_H

#include "cg_global.h"

/**
 *  Class that defines a ColoredGeometricShape.
 */
class CGSHARED_EXPORT ColoredGeometricShape
{
private:
    int red;
    int green;
    int blue;
    bool filled;
    bool null;
    int cropValue(int val) const;

public:
    /**
     *  \brief Class constructor.
     *  Constructs a ColoredGeometricShape.
     *  @param filled  - True if the form is filled.
     *  @param red     - Amount of red of the geometric shape.
     *  @param green   - Amount of green of the geometric shape.
     *  @param blue    - Amount of blue of the geometric shape.
     */
    ColoredGeometricShape(bool filled, int red, int green, int blue);

    /**
     *  \brief Class constructor.
     *  Constructs a null shape.
     */
    ColoredGeometricShape();

    /**
     *  Check if this wireframe must be filled or not.
     *  @return - true if it is filled or false otherwise.
     */
    bool isFilled() const;

    /**
     *  Get the amount of red of the geometric shape.
     *  @return - the amount of red.
     */
    int getRed() const;

    /**
     *  Checks if it is a valid shape.
     *  @return - true if it is null, false otherwise.
     */
    bool isNull() const;

    /**
     *  Get the amount of green of the geometric shape.
     *  @return - the amount of green.
     */
    int getGreen() const;

    /**
     *  Get the amount of blue of the geometric shape.
     *  @return - the amount of blue.
     */
    int getBlue() const;

    /**
     *  Get the color representation as hexadecimal.
     *  @return - The string representing the color as hexadecimal.
     */
    QString getColorAsHex() const;

    /**
    *  Compares if two colored objects are equal.
    *  @param other - the other colored object.
    *  @return true if the two colored objects are equal.
    */
    virtual bool operator==(const ColoredGeometricShape &other) const;

    /**
    *  Compares if two colored objects are not equal.
    *  @param other - the other colored object.
    *  @return true if the two colored objects are not equal.
    */
    virtual bool operator!=(const ColoredGeometricShape &other) const;

    /**
     *  Gets a string representation of the colored object.
     *  @return the string representing the colored object.
     */
    virtual const QString toString() const;
};

#endif // COLORED_GEOMETRIC_SHAPE_H
