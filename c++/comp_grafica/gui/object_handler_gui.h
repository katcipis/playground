#ifndef OBJECT_HANDLER_GUI_H
#define OBJECT_HANDLER_GUI_H

#include <QObject>
#include <QMap>
#include "ui_mainwindow.h"
#include "addobjeto.h"
#include "message.h"
#include "viewport_gui.h"
#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "transformation_handler_gui.h"
#include "ui_addobjeto.h"


class ObjectHandlerGUI : public QObject {
    Q_OBJECT
public:
    ObjectHandlerGUI(Ui::MainWindow *main_ui);
    ~ObjectHandlerGUI();

    void transformWireFrame(const Matrix& trans);
    void transformWire(const Matrix& trans);
    void transformPoint(const Matrix& trans);
    void transformCurve(const Matrix& trans);
    void transformContinuousCurve(const Matrix& trans);
    void transformBSplineCurve(const Matrix& trans);

    void addPoint(const QString& objectName, const Point& point);
    void addWire(const QString& objectName, const Wire& wire);
    void addWireFrame(const QString& objectName, const WireFrame& wireframe);
    void addCurve(const QString& objectName, const Curve& curve);
    void addContinuosCurve(const QString& objectName, const QList<Curve>& curves);
    void addBSplineCurve(const QString& objectName, const CurveBSpline& bspline);

private:
    Ui::MainWindow *ui;
    TransformationHandlerGUI* transformationGUI;
    Message* message;
    ViewPortGUI viewport;

    QChar suffixBegin;
    QChar suffixEnd;
    QString pointSuffix;
    QString wireSuffix;
    QString wireframeSuffix;
    QString curveSuffix;
    QString continuosCurveSuffix;
    QString bSplineCurveSuffix;
    QString windowOrtogonalName;
    QString windowPerspectiveName;
    QString windowPPCName;

    QMap<QString, Point> points;
    QMap<QString, Wire> wires;
    QMap<QString, WireFrame> wireframes;
    QMap<QString, Curve> curves;
    QMap<QString, QList<Curve> > continuosCurves;
    QString chosenObjectName;

    typedef void (*transformHandler) (ObjectHandlerGUI*, const Matrix&);
    QMap<QString, transformHandler> transformHandlers;

    typedef void (*addObjectHandler) (ObjectHandlerGUI*, const QString&);
    QMap<CreatedObjectID, addObjectHandler> addObjectHandlers;

    void refreshObjectsList();
    void showObjectNameError(const QString& objectType, const QString& objectName);
    void showObjectNameNotFoundError(const QString& objectName);
    void createNewObject();
    Point getSelectedObjectCenter(const QString& objectName);
    QString getSelectedObjectSuffix();
    QString removeSuffixFromObjectName(const QString& name);
    XmlObject* getXmlObject(const QString& name);
    void resetViewport();

private slots:
    void handleNewObject();
    void handleCreatedObject();
    void handleTransformObject(QListWidgetItem* item);
    void handleObjectTransformed();
    void handleCurrentWindowChanged(const QString& option);
    void handleOpenXml();
    void handleWriteAllSceneToXml();
    void handleSaveObject();

public:
    AddObjeto *addObjetoWindow; // to use just on the internal handlers functions
};

#endif // OBJECT_HANDLER_GUI_H
