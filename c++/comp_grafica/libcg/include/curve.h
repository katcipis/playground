#ifndef CURVE_H
#define CURVE_H

#include "colored_geometric_shape.h"
#include "wire.h"
#include <QList>
#include <QString>

/**
 *  Class that defines an curve abstraction.
 */
class Curve : public ColoredGeometricShape, public XmlObject
{
protected:
    QList<Wire> wires;
    QString curve_repr;
    QString tagName;
    QString xmlStart;
    QString xmlBody;
    QString xmlEnd;
    Curve(int red , int green, int blue);

public:

    /**
     *  \brief Class constructor.
     *  Constructs a curve.
     *  @param wires     - The wires that forms this curve.
     *  @param precision - The precision used to build this curve.
     *  @param red   - Amount of red of the point.
     *  @param green - Amount of green of the point.
     *  @param blue  - Amount of blue of the point.
     */
    Curve(const QList<Wire>& wires, int red = 0, int green = 0, int blue = 0, const QString& repr = QString(""));

    /**
     *  \brief Class constructor.
     *  Constructs a null curve.
     */
    Curve();

    /**
     *  Get the wires that build this curve.
     *  @return - the wires.
     */
    const QList<Wire>& getWires() const;

    /**
     *  Get the center point of this curve.
     *  @return - the center point.
     */
    Point getCenter() const;

    /**
     *  Compares if two curves are equal.
     *  @param other - the other curve.
     *  @return true if the two curves are equal.
     */
    bool operator==(const Curve &other) const;

    /**
     *  Compares if curves are not equal.
     *  @param other - the other curve.
     *  @return true if the two curves are not equal.
     */
    bool operator!=(const Curve &other) const;

    /**
     *  Gets a string representation of the curve.
     *  @return the string representing the curve.
     */
    virtual const QString toString () const;

    /**
     *  Gets the string that represents part of the xml representation without the tag start and the tag name.
     *  @return A string, eg: "curveType> ...etc </curveType>", where curveType depends on implementation.
     */
    QString toXML() const;

    /**
     *  Returns the tag name of this element
     *  @return The tag name.
     */
    QString getTagName() const;

    /**
     *  Gets a List of curves that forms a continuous curve and returns only one
     *  curve with the xml data of a continue curve. Used only when saving continuous curves to xml.
     *  @return The curve with full xml tag.
     */
    static Curve getContinuosCurveXML(const QList<Curve>& curves);

};

#endif // CURVE_H
