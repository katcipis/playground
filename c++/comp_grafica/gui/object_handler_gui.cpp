#include "object_handler_gui.h"
#include <QTextStream>
#include <QFileDialog>
#include "cg_exception.h"
#include "transform.h"
#include "window_ortogonal.h"
#include "window_perspective.h"
#include "window_ppc.h"
#include "xml_parser.h"
#include "xml_writer.h"

/****************************
  Wrap functions declaration
 ****************************/
static void transformWireFrameWrap(ObjectHandlerGUI* context, const Matrix& trans)
{
    context->transformWireFrame(trans);
}
static void transformWireWrap(ObjectHandlerGUI* context, const Matrix& trans)
{
    context->transformWire(trans);
}
static void transformPointWrap(ObjectHandlerGUI* context, const Matrix& trans)
{
    context->transformPoint(trans);
}
static void transformCurveWrap(ObjectHandlerGUI* context, const Matrix& trans)
{
    context->transformCurve(trans);
}
static void transformContinuousCurveWrap(ObjectHandlerGUI* context, const Matrix& trans)
{
    context->transformContinuousCurve(trans);
}


static void addWireFrameWrap(ObjectHandlerGUI* context, const QString& objectName)
{
    context->addWireFrame(objectName, context->addObjetoWindow->getWireFrame());
}
static void addWireWrap(ObjectHandlerGUI* context, const QString& objectName)
{
    context->addWire(objectName, context->addObjetoWindow->getWire());
}
static void addPointWrap(ObjectHandlerGUI* context, const QString& objectName)
{
    context->addPoint(objectName, context->addObjetoWindow->getPoint());
}
static void addCurveWrap(ObjectHandlerGUI* context, const QString& objectName)
{
    context->addCurve(objectName, context->addObjetoWindow->getCurve());
}
static void addContinuosCurveWrap(ObjectHandlerGUI* context, const QString& objectName)
{
    context->addContinuosCurve(objectName, context->addObjetoWindow->getContinuosCurve());
}
static void addBSplineCurveWrap(ObjectHandlerGUI* context, const QString& objectName)
{
    context->addBSplineCurve(objectName, context->addObjetoWindow->getBSplineCurve());
}


ObjectHandlerGUI::ObjectHandlerGUI(Ui::MainWindow *main_ui) : QObject(), ui(main_ui), viewport(main_ui, new WindowOrtogonal(1,1)),
                                                              suffixBegin('<'), suffixEnd('>'),
                                                              pointSuffix("point"), wireSuffix("wire"),
                                                              wireframeSuffix("wireframe"), curveSuffix("curve"),
                                                              continuosCurveSuffix("continuousCurve"), bSplineCurveSuffix("bspline"),
                                                              windowOrtogonalName("Ortogonal 3D"), windowPerspectiveName("Perspective 3D"),
                                                              windowPPCName("PPC 2D")
{
    this->addObjetoWindow = new AddObjeto();
    this->addObjetoWindow->setModal(true);
    this->message = new Message();
    this->message->setModal(true);
    this->transformationGUI = new TransformationHandlerGUI();
    this->transformationGUI->setModal(true);

    this->transformHandlers[pointSuffix]          = transformPointWrap;
    this->transformHandlers[wireSuffix]           = transformWireWrap;
    this->transformHandlers[wireframeSuffix]      = transformWireFrameWrap;
    this->transformHandlers[curveSuffix]          = transformCurveWrap;
    this->transformHandlers[continuosCurveSuffix] = transformContinuousCurveWrap;
    this->transformHandlers[bSplineCurveSuffix]   = transformCurveWrap;

    this->addObjectHandlers[ADD_POINT]            = addPointWrap;
    this->addObjectHandlers[ADD_WIRE]             = addWireWrap;
    this->addObjectHandlers[ADD_WIREFRAME]        = addWireFrameWrap;
    this->addObjectHandlers[ADD_CURVE]            = addCurveWrap;
    this->addObjectHandlers[ADD_CONTINUOUS_CURVE] = addContinuosCurveWrap;
    this->addObjectHandlers[ADD_BSPLINE_CURVE]    = addBSplineCurveWrap;

    QObject::connect(this->ui->novoObjeto,  SIGNAL(triggered(bool)),this,SLOT(handleNewObject()));
    QObject::connect(this->ui->abrirXml,    SIGNAL(triggered(bool)),this,SLOT(handleOpenXml()));
    QObject::connect(this->ui->salvarXml,   SIGNAL(triggered(bool)),this,SLOT(handleWriteAllSceneToXml()));
    QObject::connect(this->addObjetoWindow, SIGNAL(accepted()),this,SLOT(handleCreatedObject()));

    QObject::connect(this->ui->objects,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(handleTransformObject(QListWidgetItem*)));
    QObject::connect(this->transformationGUI,SIGNAL(accepted()),this,SLOT(handleObjectTransformed()));
    QObject::connect(this->ui->salvarObjeto,SIGNAL(clicked()),this,SLOT(handleSaveObject()));

    this->ui->windowsBox->addItem(windowOrtogonalName);
    this->ui->windowsBox->addItem(windowPerspectiveName);
    this->ui->windowsBox->addItem(windowPPCName);
    QObject::connect(this->ui->windowsBox, SIGNAL(currentIndexChanged(const QString&)),this,SLOT(handleCurrentWindowChanged(const QString&)));
}

ObjectHandlerGUI::~ObjectHandlerGUI()
{
    delete addObjetoWindow;
    delete message;
    delete transformationGUI;
 }

void ObjectHandlerGUI::handleCreatedObject()
{
    try{
        this->createNewObject();
    } catch(CGException& except) {
        this->message->setMessage(except.getErrorMessage());
        this->message->show();
    }

    this->refreshObjectsList();
}

void ObjectHandlerGUI::createNewObject()
{
    QString objectName = this->addObjetoWindow->getObjectName();

    if (objectName == QString("")) {
        this->message->setMessage("Trying to create and object without a name !!");
        this->message->show();
        return;
    }

    this->addObjectHandlers[this->addObjetoWindow->getCreatedObjectID()](this, objectName);
}

void ObjectHandlerGUI::refreshObjectsList()
{
    QMap<QString, Point>::const_iterator points_iter = this->points.constBegin();
    QMap<QString, Wire>::const_iterator wires_iter = this->wires.constBegin();
    QMap<QString, WireFrame>::const_iterator wireframes_iter = this->wireframes.constBegin();
    QMap<QString, Curve>::const_iterator curves_iter = this->curves.constBegin();
    QMap<QString, QList<Curve> >::const_iterator continuous_curves_iter = this->continuosCurves.constBegin();

    this->ui->objects->clear();

    while(points_iter != this->points.constEnd()) {
        this->ui->objects->addItem(points_iter.key());
        points_iter++;
    }

    while(wires_iter != this->wires.constEnd()) {
        this->ui->objects->addItem(wires_iter.key());
        wires_iter++;
    }

    while(wireframes_iter != this->wireframes.constEnd()) {
        this->ui->objects->addItem(wireframes_iter.key());
        wireframes_iter++;
    }

    while(curves_iter != this->curves.constEnd()) {
        this->ui->objects->addItem(curves_iter.key());
        curves_iter++;
    }

    while(continuous_curves_iter != this->continuosCurves.constEnd()) {
        this->ui->objects->addItem(continuous_curves_iter.key());
        continuous_curves_iter++;
    }
}

void ObjectHandlerGUI::showObjectNameError(const QString& objectType, const QString& objectName)
{
    QString messageStr;
    QTextStream(&messageStr) << "Already exists a " << objectType << " with the name: " << objectName;
    this->message->setMessage(messageStr);
    this->message->show();
}

void ObjectHandlerGUI::showObjectNameNotFoundError(const QString& objectName)
{
    QString messageStr;
    QTextStream(&messageStr) << "There is no object with the name: " << objectName;
    this->message->setMessage(messageStr);
    this->message->show();
}

void ObjectHandlerGUI::addPoint(const QString& objectName, const Point& point)
{
    QString name = objectName + this->suffixBegin + this->pointSuffix + this->suffixEnd;

    if (this->points.contains(name)) {
        this->showObjectNameError("point", objectName);
    } else {
        this->points.insert(name, point);
        this->viewport.addPoint(point);
    }
}

void ObjectHandlerGUI::addCurve(const QString& objectName, const Curve& curve)
{
    QString name = objectName + this->suffixBegin + this->curveSuffix + this->suffixEnd;

    if (this->curves.contains(name)) {
        this->showObjectNameError(this->curveSuffix, objectName);
    } else {
        this->curves.insert(name, curve);
        this->viewport.addCurve(curve);
    }
}

void ObjectHandlerGUI::addBSplineCurve(const QString& objectName, const CurveBSpline& curve)
{
    QString name = objectName + this->suffixBegin + this->bSplineCurveSuffix + this->suffixEnd;

    if (this->curves.contains(name)) {
        this->showObjectNameError(this->bSplineCurveSuffix, objectName);
    } else {
        this->curves.insert(name, curve);
        this->viewport.addCurve(curve);
    }
}

void ObjectHandlerGUI::addContinuosCurve(const QString& objectName, const QList<Curve>& curve)
{
    QString name = objectName + this->suffixBegin + this->continuosCurveSuffix + this->suffixEnd;

    if (this->continuosCurves.contains(name)) {
        this->showObjectNameError(this->continuosCurveSuffix, objectName);
    } else {
        this->continuosCurves.insert(name, curve);
        for (int i = 0; i<curve.size(); i++) {
            this->viewport.addCurve(curve[i]);
        }
    }
}

void ObjectHandlerGUI::addWire(const QString& objectName, const Wire& wire)
{
    QString name = objectName + this->suffixBegin + this->wireSuffix + this->suffixEnd;

    if (this->wires.contains(name)) {
        this->showObjectNameError("wire", objectName);
    } else {
        this->wires.insert(name, wire);
        this->viewport.addWire(wire);
    }
}

void ObjectHandlerGUI::addWireFrame(const QString& objectName, const WireFrame& wireframe)
{
    QString name = objectName + this->suffixBegin + this->wireframeSuffix + this->suffixEnd;

    if (this->wireframes.contains(name)) {
        this->showObjectNameError("wireframe", objectName);
    } else {
        this->wireframes.insert(name, wireframe);
        this->viewport.addWireFrame(wireframe);
    }
}


void ObjectHandlerGUI::handleWriteAllSceneToXml()
{
    QString filename = QFileDialog::getSaveFileName();
    if (filename.isNull()) {
        return;
    }

    XmlWriter writer(filename);
    QMap<QString, Point>::const_iterator points_iter                    = this->points.constBegin();
    QMap<QString, Wire>::const_iterator wires_iter                      = this->wires.constBegin();
    QMap<QString, WireFrame>::const_iterator wireframes_iter            = this->wireframes.constBegin();
    QMap<QString, Curve>::const_iterator curves_iter                    = this->curves.constBegin();
    QMap<QString, QList<Curve> >::const_iterator continuous_curves_iter = this->continuosCurves.constBegin();

    while(points_iter != this->points.constEnd()) {
        writer.addObject(this->removeSuffixFromObjectName(points_iter.key()), &points_iter.value());
        points_iter++;
    }


    while(wires_iter != this->wires.constEnd()) {
        writer.addObject(this->removeSuffixFromObjectName(wires_iter.key()), &wires_iter.value());
        wires_iter++;
    }

    while(wireframes_iter != this->wireframes.constEnd()) {
        writer.addObject(this->removeSuffixFromObjectName(wireframes_iter.key()), &wireframes_iter.value());
        wireframes_iter++;
    }

    while(curves_iter != this->curves.constEnd()) {
        writer.addObject(this->removeSuffixFromObjectName(curves_iter.key()), &curves_iter.value());
        curves_iter++;
    }


    while(continuous_curves_iter != this->continuosCurves.constEnd()) {
        Curve curve = Curve::getContinuosCurveXML(continuous_curves_iter.value());
        if (curve.isNull()) {
            continuous_curves_iter++;
            continue;
        }
        writer.addObject(this->removeSuffixFromObjectName(continuous_curves_iter.key()), &curve);
        continuous_curves_iter++;
    }

    writer.addObject(this->viewport.getWindow());
    writer.save();
}

void ObjectHandlerGUI::handleOpenXml()
{
    QString filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) {
        return;
    }

    try {

        XmlParser parser(filename);
        QMap<QString, Point>::const_iterator points_iter            = parser.points.constBegin();
        QMap<QString, Wire>::const_iterator wires_iter              = parser.wires.constBegin();
        QMap<QString, WireFrame>::const_iterator wireframes_iter    = parser.wireframes.constBegin();
        QMap<QString, Curve>::const_iterator curves_iter            = parser.curves.constBegin();
        QMap<QString, QList<Curve> >::const_iterator continuous_curves_iter = parser.continuousCurves.constBegin();

        while(points_iter != parser.points.constEnd()) {
            this->addPoint(points_iter.key(), points_iter.value());
            points_iter++;
        }

        while(wires_iter != parser.wires.constEnd()) {
            this->addWire(wires_iter.key(), wires_iter.value());
            wires_iter++;
        }

        while(wireframes_iter != parser.wireframes.constEnd()) {
            this->addWireFrame(wireframes_iter.key(), wireframes_iter.value());
            wireframes_iter++;
        }

        while(curves_iter != parser.curves.constEnd()) {
            this->addCurve(curves_iter.key(), curves_iter.value());
            curves_iter++;
        }

        while(continuous_curves_iter != parser.continuousCurves.constEnd()) {
            this->addContinuosCurve(continuous_curves_iter.key(), continuous_curves_iter.value());
            continuous_curves_iter++;
        }

        if (parser.window) {
            this->viewport.setNewWindow(parser.window);
        }
        this->resetViewport();

        if (parser.errors.empty()) {
            return;
        }

        QString log;
        QTextStream stream(&log);

        for (int i = 0; i < parser.errors.size(); i++) {
            stream << parser.errors[i] << "\n";
        }

        this->message->setMessage(log);
        this->message->show();

    } catch(CGException e) {
        this->message->setMessage(e.getErrorMessage());
        this->message->show();
    }

}

void ObjectHandlerGUI::handleNewObject()
{
    this->addObjetoWindow->resetInternalState();
    this->addObjetoWindow->show();
}

Point ObjectHandlerGUI::getSelectedObjectCenter(const QString& objectName)
{
    if (this->wireframes.contains(objectName)) {
        return this->wireframes[objectName].getCenter();
    }

    if (this->wires.contains(objectName)) {
        return this->wires[objectName].getCenter();
    }

    if (this->points.contains(objectName)) {
        return this->points[objectName];
    }

    if (this->curves.contains(objectName)) {
        return this->curves[objectName].getCenter();
    }

    if (this->continuosCurves.contains(objectName)) {
        QList<Curve> curves = this->continuosCurves[objectName];
        double x = 0;
        double y = 0;

        for (int i = 0; i < curves.size(); i++) {
            x += curves[i].getCenter().getX();
            y += curves[i].getCenter().getY();
        }

        return Point(x / curves.size(), y / curves.size());
    }

    this->showObjectNameNotFoundError(objectName);
    return Point();
}

void ObjectHandlerGUI::handleCurrentWindowChanged(const QString& option)
{
    Window* newWindow = 0;
    if (option == this->windowOrtogonalName) {
        newWindow = new WindowOrtogonal(1,1);
    }
    else if (option == this->windowPerspectiveName) {
        newWindow = new WindowPerspective(1,1);
    }
    else if (option == this->windowPPCName) {
        newWindow = new WindowPPC(1,1);
    } else {
        this->message->setMessage(QString("Unexpected error, got a invalid window: ") + option + QString(" as choice !!!"));
        this->message->show();
        return;
    }

    this->viewport.setNewWindow(newWindow);
    this->resetViewport();
}

void ObjectHandlerGUI::resetViewport()
{
    QMap<QString, Point>::const_iterator points_iter                   = this->points.constBegin();
    QMap<QString, Wire>::const_iterator wires_iter                     = this->wires.constBegin();
    QMap<QString, WireFrame>::const_iterator wireframes_iter           = this->wireframes.constBegin();
    QMap<QString, Curve>::const_iterator curves_iter                   = this->curves.constBegin();
    QMap<QString, QList<Curve> >::const_iterator continuous_curves_iter = this->continuosCurves.constBegin();

    this->viewport.reset();
    
    while(points_iter != this->points.constEnd()) {
        this->viewport.addPoint(points_iter.value());
        points_iter++;
    }

    while(wires_iter != this->wires.constEnd()) {
        this->viewport.addWire(wires_iter.value());
        wires_iter++;
    }

    while(wireframes_iter != this->wireframes.constEnd()) {
        this->viewport.addWireFrame(wireframes_iter.value());
        wireframes_iter++;
    }

    while(curves_iter != this->curves.constEnd()) {
        this->viewport.addCurve(curves_iter.value());
        curves_iter++;
    }

    while(continuous_curves_iter != this->continuosCurves.constEnd()) {
        QList<Curve> curves = continuous_curves_iter.value();
        for (int i = 0; i < curves.size(); i++) {
            this->viewport.addCurve(curves[i]);
        }
        continuous_curves_iter++;
    }

    this->refreshObjectsList();
}

QString ObjectHandlerGUI::removeSuffixFromObjectName(const QString& name)
{
    QString result;
    for (int i = 0; i < name.size(); i++) {
        if(name[i] == this->suffixBegin) {
            return result;
        }
        result.append(name[i]);
    }
    return result;
}

XmlObject* ObjectHandlerGUI::getXmlObject(const QString& name)
{
    if (this->points.contains(name)) {
        return new Point(this->points[name]);
    }

    if (this->wires.contains(name)) {
        return new Wire(this->wires[name]);
    }

    if (this->wireframes.contains(name)) {
        return new WireFrame(this->wireframes[name]);
    }

    if (this->curves.contains(name)) {
        return new Curve(this->curves[name]);
    }

    if (this->continuosCurves.contains(name)) {
        Curve curve = Curve::getContinuosCurveXML(this->continuosCurves[name]);
        if (curve.isNull()) {
            return 0;
        }
        return new Curve(curve);
    }

    return 0;
}

QString ObjectHandlerGUI::getSelectedObjectSuffix()
{
    int begin = 0;
    int end   = 0;
    QString result;

    for (int i = this->chosenObjectName.size() - 1; i >=0; i--) {
        if(this->chosenObjectName[i] == this->suffixBegin) {
            begin = i;
            break;
        }
    }

    for (int i = this->chosenObjectName.size() - 1; i >=0; i--) {
        if(this->chosenObjectName[i] == this->suffixEnd) {
            end = i;
            break;
        }
    }

    for (int i = begin + 1; i < end; i++) {
        result.append(this->chosenObjectName[i]);
    }
    return result;
}

void ObjectHandlerGUI::handleTransformObject(QListWidgetItem* item)
{
    this->chosenObjectName = item->text();
    this->transformationGUI->resetInternalState();
    this->transformationGUI->setSelectedObjectCenter(this->getSelectedObjectCenter(item->text()));
    this->transformationGUI->show();
}

void ObjectHandlerGUI::handleSaveObject()
{
    QString filename = QFileDialog::getSaveFileName();
    QString errors;
    if (filename.isNull()) {
        return;
    }

    XmlWriter writer(filename);
    QList<QListWidgetItem *> selectedObjs = this->ui->objects->selectedItems();

    for (int i=0; i < selectedObjs.size(); i++) {
        XmlObject* obj = this->getXmlObject(selectedObjs[i]->text());
        QString name   = this->removeSuffixFromObjectName(selectedObjs[i]->text());

        if (!obj) {
            errors += "Unable to get object with name[" + selectedObjs[i]->text() + "]\n";
            continue;
        }

        writer.addObject(name,obj);
        /* delete obj; i thought i had to delete here, i wont use it anymore, but if i delete i get seg fault every time.*/
    }

    writer.save();
    if (errors != QString("")) {
        this->message->setMessage(errors);
        this->message->show();
    }
}

void ObjectHandlerGUI::handleObjectTransformed()
{
    try {
        this->transformHandlers[this->getSelectedObjectSuffix()](this, this->transformationGUI->getTransformationMatrix());
    } catch(CGException e) {
        this->message->setMessage(e.getErrorMessage());
        this->message->show();
    }
}

void ObjectHandlerGUI::transformWireFrame(const Matrix& trans)
{
    if (!this->wireframes.contains(this->chosenObjectName)) {
        return;
    }
    WireFrame wireframe = this->wireframes[this->chosenObjectName];
    WireFrame newWireFrame = transform::getTransformedWireFrame(wireframe, trans);
    this->wireframes[this->chosenObjectName] = newWireFrame;
    this->viewport.removeWireFrame(wireframe);
    this->viewport.addWireFrame(newWireFrame);
}

void ObjectHandlerGUI::transformCurve(const Matrix& trans)
{
    if (!this->curves.contains(this->chosenObjectName)) {
        return;
    }
    Curve curve = this->curves[this->chosenObjectName];
    Curve newCurve = transform::getTransformedCurve(curve, trans);

    this->curves[this->chosenObjectName] = newCurve;
    this->viewport.removeCurve(curve);
    this->viewport.addCurve(newCurve);
}

void ObjectHandlerGUI::transformContinuousCurve(const Matrix& trans)
{
    if (!this->continuosCurves.contains(this->chosenObjectName)) {
        return;
    }
    const QList<Curve> curve = this->continuosCurves[this->chosenObjectName];
    QList<Curve> newCurve;

    for (int i = 0; i < curve.size(); i++) {
        newCurve.append(Curve(transform::getTransformedCurve(curve[i], trans)));
        this->viewport.removeCurve(curve[i]);
        this->viewport.addCurve(newCurve[i]);
    }

    this->continuosCurves[this->chosenObjectName] = newCurve;
}

void ObjectHandlerGUI::transformWire(const Matrix& trans)
{
    if (!this->wires.contains(this->chosenObjectName)) {
        return;
    }
    Wire wire = this->wires[this->chosenObjectName];
    Wire newWire = transform::getTransformedWire(wire, trans);

    this->wires[this->chosenObjectName] = newWire;
    this->viewport.removeWire(wire);
    this->viewport.addWire(newWire);
}

void ObjectHandlerGUI::transformPoint(const Matrix& trans)
{
    if (!this->points.contains(this->chosenObjectName)) {
        return;
    }
    Point point= this->points[this->chosenObjectName];
    Point newPoint = transform::getTransformedPoint(point, trans);

    this->points[this->chosenObjectName] = newPoint;
    this->viewport.removePoint(point);
    this->viewport.addPoint(newPoint);
}
