#include "viewport_2d.h"
#include <QList>

Point viewport_2d::transform(const Point& point, const Point& window_min, const Point& window_max,
                               const Point& viewport_min, const Point& viewport_max, double offset)
{
    double vp_x = ((point.getX() - window_min.getX()) / (window_max.getX() - window_min.getX())) *
                  (viewport_max.getX() - viewport_min.getX());

    double vp_y = (1.0 - ((point.getY() - window_min.getY()) / (window_max.getY() - window_min.getY()))) *
                  (viewport_max.getY() - viewport_min.getY());

    return Point(point.getRed(), point.getGreen(), point.getBlue(), vp_x + offset, vp_y + offset);
}

Wire viewport_2d::transform(const Wire& wire, const Point& window_min, const Point& window_max,
                              const Point& viewport_min, const Point& viewport_max, double offset)
{
    return Wire(viewport_2d::transform(wire.getFirstPoint(), window_min, window_max, viewport_min, viewport_max, offset),
                viewport_2d::transform(wire.getSecondPoint(), window_min, window_max, viewport_min, viewport_max, offset),
                wire.getRed(), wire.getGreen(), wire.getBlue());
}

WireFrame viewport_2d::transform(const WireFrame& wireframe, const Point& window_min, const Point& window_max,
                                 const Point& viewport_min, const Point& viewport_max, double offset)
{
    QList<Wire> new_wires;
    QList<Wire> old_wires = wireframe.getWires();

    for(int i = 0; i < old_wires.size(); i++){
        new_wires.append(viewport_2d::transform(old_wires[i], window_min, window_max, viewport_min, viewport_max, offset));
    }

    return WireFrame(new_wires, wireframe.isFilled(), wireframe.getRed(), wireframe.getGreen(), wireframe.getBlue());
}

CurveHermite viewport_2d::transform(const CurveHermite& curve, const Point& window_min, const Point& window_max,
                       const Point& viewport_min, const Point& viewport_max, double offset)
{
    Point p1 = viewport_2d::transform(curve.getP1(), window_min, window_max,
                                                     viewport_min, viewport_max, offset);
    Point p4 = viewport_2d::transform(curve.getP4(), window_min, window_max,
                                                     viewport_min, viewport_max, offset);
    Point r1 = viewport_2d::transform(curve.getR1(), window_min, window_max,
                                                     viewport_min, viewport_max, offset);
    Point r4 = viewport_2d::transform(curve.getR4(), window_min, window_max,
                                                     viewport_min, viewport_max, offset);

    return CurveHermite(p1, p4, r1, r4, curve.getPrecision(), curve.getRed(), curve.getGreen(), curve.getBlue());
}
