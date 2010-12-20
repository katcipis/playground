#include "wire_test.h"
#include "wireframe_test.h"
#include "point_test.h"
#include "window_ppc_test.h"
#include "window_ppc_clipped_test.h"
#include "viewport_2d_test.h"
#include "matrix_test.h"
#include "transform_test.h"
#include "curve_hermite_test.h"

int main()
{
    WireTest wire;
    PointTest point;
    WireFrameTest wireframe;
    WindowPPCTest windowPPC;
    WindowPPCClippedTest windowPPCClipped;
    ViewPort2DTest viewport2D;
    MatrixTest matrix;
    TransformTest transform;
    CurveHermiteTest hermite;

    QTest::qExec(&wire);
    QTest::qExec(&point);
    QTest::qExec(&wireframe);
    QTest::qExec(&hermite);
    QTest::qExec(&windowPPC);
    QTest::qExec(&windowPPCClipped);
    QTest::qExec(&viewport2D);
    QTest::qExec(&matrix);
    QTest::qExec(&transform);
}
