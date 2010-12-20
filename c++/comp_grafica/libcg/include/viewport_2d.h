#ifndef VIEWPORT2D_H
#define VIEWPORT2D_H

#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "curve_hermite.h"

/**
 * \namespace viewport_2d
 * \brief Defines functions that can be used to transform a window objects to a viewport object.
 */
namespace viewport_2d {

    /**
     *  Transform a point from window coordinates to viewport coordinates.
     *  @param point        - The window point.
     *  @param window_min   - The window minimum point.
     *  @param window_max   - The window maximum point.
     *  @param viewport_min - The viewport minimum point.
     *  @param viewport_max - The viewport maximum point.
     *  @param offset       - The offset between the viewport size and the window size (if the viewport has a margin).
     *  @return - the viewport point.
     */
    Point transform(const Point& point, const Point& window_min, const Point& window_max,
                    const Point& viewport_min, const Point& viewport_max, double offset = 0);

    /**
     *  Transform a wire from window coordinates to viewport coordinates.
     *  @param wire         - The window wire.
     *  @param window_min   - The window minimum point.
     *  @param window_max   - The window maximum point.
     *  @param viewport_min - The viewport minimum point.
     *  @param viewport_max - The viewport maximum point.
     *  @param offset       - The offset between the viewport size and the window size (if the viewport has a margin).
     *  @return - the viewport wire.
     */
    Wire transform(const Wire& wire, const Point& window_min, const Point& window_max,
                   const Point& viewport_min, const Point& viewport_max, double offset = 0);

    /**
     *  Transform a wireframe from window coordinates to viewport coordinates.
     *  @param wireframe    - The window wireframe.
     *  @param window_min   - The window minimum point.
     *  @param window_max   - The window maximum point.
     *  @param viewport_min - The viewport minimum point.
     *  @param viewport_max - The viewport maximum point.
     *  @param offset       - The offset between the viewport size and the window size (if the viewport has a margin).
     *  @return - the viewport wireframe.
     */
    WireFrame transform(const WireFrame& wireframe, const Point& window_min, const Point& window_max,
                        const Point& viewport_min, const Point& viewport_max, double offset = 0);

    /**
     *  Transform a curve from window coordinates to viewport coordinates.
     *  @param curve        - The window curve.
     *  @param window_min   - The window minimum point.
     *  @param window_max   - The window maximum point.
     *  @param viewport_min - The viewport minimum point.
     *  @param viewport_max - The viewport maximum point.
     *  @param offset       - The offset between the viewport size and the window size (if the viewport has a margin).
     *  @return - the viewport wireframe.
     */
    CurveHermite transform(const CurveHermite& curve, const Point& window_min, const Point& window_max,
                           const Point& viewport_min, const Point& viewport_max, double offset = 0);
}

#endif // VIEWPORT2D_H
