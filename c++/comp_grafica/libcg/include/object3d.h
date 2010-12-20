#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "cg_global.h"
#include "wire.h"
#include <QList>
#include <QString>

class CGSHARED_EXPORT Object3D : public ColoredGeometricShape, public XmlObject {

protected:
    QList<Wire> wires;

    /**
     *  \brief Class constructor.
     *  Constructs a object3d with the given wires.
     *  @param wires - the wires that will form the object3d, on the order that they touch each other.
     *  @param fill  - True if the form is filled.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    Object3D(const QList<Wire>& wires, bool fill, int red, int green, int blue);

    /**
     *  \brief Class constructor.
     *  Constructs a object3d with the given points.
     *  @param points - the points that will form the object3d, on the order that they form the wires.
     *  @param fill  - True if the form is filled.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    Object3D(const QList<Point>& points, bool fill, int red, int green, int blue);


public:

    /**
     *  \brief Class constructor.
     *  Constructs a object3d with the given points.
     *  @param points - the points that will form the object3d, on the order that they connect each other.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    Object3D(const QList<Wire>& wires, int red, int green, int blue);
    

    /**
     *  \brief Class constructor.
     *  Constructs a null object3D.
     */
    Object3D();

    /**
     *  Get the wires that forms this object3d.
     *  This must NOT be altered, only consulted.
     *  @return - the wires.
     */
    const QList<Wire>& getWires() const;

    /**
     *  Get the center point of this object3d.
     *  @return - the center point.
     */
    Point getCenter() const;

     /**
     *  Compares if two object3ds are equal.
     *  @param other - the other object3d.
     *  @return true if the two object3ds are equal.
     */
    bool operator==(const Object3D &other) const;

    /**
     *  Compares if two object3ds are not equal.
     *  @param other - the other object3d.
     *  @return true if the two object3ds are not equal.
     */
    bool operator!=(const Object3D &other) const;

    /**
     *  Gets a string representation of the object3d.
     *  @return the string representing the object3d.
     */
    virtual const QString toString() const;

    /**
     *  Gets the string that represents part of the xml representation without the tag start and the tag name.
     *  @return A string, eg: "cor=00FFA0> ...etc </objeto3d>".
     */
    virtual QString toXML() const;

    /**
     *  Returns the tag name of this element
     *  @return The tag name.
     */
    virtual QString getTagName() const;

};

#endif // OBJECT3D_H
