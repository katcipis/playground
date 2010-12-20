#ifndef CLIPPER_H
#define CLIPPER_H

#include "wire.h"
#include "wireframe.h"
#include <QList>

/**
 * \namespace transform
 * \brief Define functions that can be used to clip points, wires and polygons. Uses Cohen Sutherland line clipping and the Weiler Atherton polygon clipping method.
 */
namespace clipper
{
    /**
     *  Start internal facilities of the clipper module, MUST be called once.
     */
    void init();

    /**
     *  Clip a list of points.
     *  @param points - The points to clip.
     *  @param min    - The min point of the window.
     *  @param max    - The max point of the window.
     *  @return - A list of clipped points.
     */
    QList<Point> clipPoints(const QList<Point> points, const Point& min, const Point& max);

    /**
     *  Clip a list of wires.
     *  @param points - The wires to clip.
     *  @param min    - The min point of the window.
     *  @param max    - The max point of the window.
     *  @return - A list of clipped wires.
     */
    QList<Wire> clipWires(const QList<Wire>& wires, const Point& min, const Point& max);

    /**
     *  Clip a list of wireframes.
     *  @param points - The wireframes to clip.
     *  @param min    - The min point of the window.
     *  @param max    - The max point of the window.
     *  @return - A list of clipped wireframes.
     */
    QList<WireFrame> clipWireFrames(const QList<WireFrame>& wireframes,  const Point& min,  const Point& max);
};

#endif // CLIPPER_H
