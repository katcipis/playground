#ifndef ADDOBJETO_H
#define ADDOBJETO_H

#include <QDialog>
#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "curve_hermite.h"
#include "curve_bspline.h"
#include <QColorDialog>
#include <QColor>
#include <QRgb>
#include <QMap>

namespace Ui {
    class AddObjeto;
}

enum CreatedObjectID {
    ADD_POINT,
    ADD_WIRE,
    ADD_WIREFRAME,
    ADD_CURVE,
    ADD_CONTINUOUS_CURVE,
    ADD_BSPLINE_CURVE
};

class AddObjeto : public QDialog {
    Q_OBJECT
public:
    AddObjeto(QWidget *parent = 0);
    ~AddObjeto();

    CreatedObjectID getCreatedObjectID();

    QString getObjectName();
    void resetInternalState();

    Point getPoint();
    CurveHermite getCurve();
    CurveBSpline getBSplineCurve();
    QList<Curve> getContinuosCurve();
    Wire getWire();
    WireFrame getWireFrame();

protected:
    void changeEvent(QEvent *e);

private slots:
    void handleAddWire();
    void handleAddCurve();
    void handleSelectColor();
    void handleAddCoordinate();

private:
    QList<Wire> wireframe_wires;
    QList<Curve> continuosCurve;
    Ui::AddObjeto *ui;
    QColor chosenObjectColor;
    QMap<int, CreatedObjectID> indexToId;
    QList<Point> bSplineCoordinates;
};

#endif // ADDOBJETO_H
