#ifndef WIREFRAME_H
#define WIREFRAME_H

#include "object3d.h"

/**
 *  Class that defines a WireFrame (Actually a polygon, but there is no time for the entire system renaming :-().
 */
class CGSHARED_EXPORT WireFrame : public Object3D
{
private:
    bool checkIfWiresAreConnected(const Wire& wire1, const Wire& wire2) const;

public:
    /**
     *  \brief Class constructor.
     *  Constructs a wireframe with the given wires, the wires must form a closed polygon.
     *  @param wires  - the wires that will form the wireframe, on the order that they touch each other.
     *  @param filled - true if it is filled, false otherwise.
     *  @param red    - Amount of red of the wireframe.
     *  @param green  - Amount of green of the wireframe.
     *  @param blue   - Amount of blue of the wireframe.
     */
    WireFrame(const QList<Wire>& wires, bool filled, int red, int green, int blue);

    /**
     *  \brief Class constructor.
     *  Constructs a wireframe with the given points, the last point will connect to the first to form an closed polygon.
     *  @param points - the wires that will form the wireframe, on the order that they connect to each other.
     *  @param filled - true if it is filled, false otherwise.
     *  @param red    - Amount of red of the wireframe.
     *  @param green  - Amount of green of the wireframe.
     *  @param blue   - Amount of blue of the wireframe.
     */
    WireFrame(const QList<Point>& points, bool filled, int red, int green, int blue);

    /**
     *  \brief Class constructor.
     *  Constructs a wireframe that is a copy of the object3D without validating if it is a closed polygon.
     *  @param obj - the object3D that will become a wireframe.
     */
    WireFrame(const Object3D& obj);

    /**
     *  \brief Class constructor.
     *  Constructs a null wireframe.
     */
    WireFrame();

    /**
     *  Checks if this object is a closed polygon.
     *  @return - True if it is a closed polygon, false otherwise.
    */
    bool isAClosedPolygon() const;

    /**
     *  Gets the string that represents part of the xml representation without the tag start and the tag name.
     *  @return A string, eg: "cor=00FFA0> ...etc </poligono>".
     */
    virtual QString toXML() const;

    /**
     *  Returns the tag name of this element
     *  @return The tag name.
     */
    virtual QString getTagName() const;
};

#endif // WIREFRAME_H
