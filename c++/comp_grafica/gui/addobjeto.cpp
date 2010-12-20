#include "addobjeto.h"
#include "ui_addobjeto.h"

AddObjeto::AddObjeto(QWidget *parent) :QDialog(parent), ui(new Ui::AddObjeto)
{
    this->ui->setupUi(this);

    QObject::connect(this->ui->addAresta, SIGNAL(clicked()),this,SLOT(handleAddWire()));
    QObject::connect(this->ui->adcionarCurva, SIGNAL(clicked()),this,SLOT(handleAddCurve()));
    QObject::connect(this->ui->colorSelect_pushButton, SIGNAL(clicked()),this,SLOT(handleSelectColor()));
    QObject::connect(this->ui->addPointBSpline,SIGNAL(clicked()),this,SLOT(handleAddCoordinate()));

    this->indexToId[this->ui->objetosTab->indexOf(this->ui->curvaTab)] = ADD_CURVE;
    this->indexToId[this->ui->objetosTab->indexOf(this->ui->pontoTab)] = ADD_POINT;
    this->indexToId[this->ui->objetosTab->indexOf(this->ui->wireframeTab)] = ADD_WIREFRAME;
    this->indexToId[this->ui->objetosTab->indexOf(this->ui->wireTab)] = ADD_WIRE;
    this->indexToId[this->ui->objetosTab->indexOf(this->ui->curvasContinuasTab)] = ADD_CONTINUOUS_CURVE;
    this->indexToId[this->ui->objetosTab->indexOf(this->ui->bsplineTab)] = ADD_BSPLINE_CURVE;
}

AddObjeto::~AddObjeto()
{
    delete this->ui;
}

CreatedObjectID AddObjeto::getCreatedObjectID()
{
    return this->indexToId[this->ui->objetosTab->currentIndex()];
}

QString AddObjeto::getObjectName()
{
    return this->ui->nameField->text();
}

Point AddObjeto::getPoint()
{
    return Point(this->chosenObjectColor.red(), this->chosenObjectColor.green(), this->chosenObjectColor.blue(),
                 this->ui->pointX_field->text().toDouble(), this->ui->pointY_field->text().toDouble(), this->ui->pointZ_field->text().toDouble());
}

Wire AddObjeto::getWire()
{
    Point start(this->ui->wireXIni_field->text().toDouble(), this->ui->wireYIni_field->text().toDouble(),   this->ui->wireZIni_field->text().toDouble());
    Point end(this->ui->wireXFinal_field->text().toDouble(), this->ui->wireYFinal_field->text().toDouble(), this->ui->wireZFinal_field->text().toDouble());
    return Wire(start, end, this->chosenObjectColor.red(), this->chosenObjectColor.green(), this->chosenObjectColor.blue());
}

WireFrame AddObjeto::getWireFrame()
{
    return WireFrame(this->wireframe_wires, this->ui->wireFramePreenchido->isChecked(),
                     this->chosenObjectColor.red(), this->chosenObjectColor.green(), this->chosenObjectColor.blue());
}

CurveBSpline AddObjeto::getBSplineCurve()
{
    return CurveBSpline(this->bSplineCoordinates, this->chosenObjectColor.red(), this->chosenObjectColor.green(), this->chosenObjectColor.blue());
}

CurveHermite AddObjeto::getCurve()
{
    return CurveHermite(Point(this->ui->curveP1X->text().toDouble(), this->ui->curveP1Y->text().toDouble()),
                        Point(this->ui->curveP4X->text().toDouble(), this->ui->curveP4Y->text().toDouble()),
                        Point(this->ui->curveR1X->text().toDouble(), this->ui->curveR1Y->text().toDouble()),
                        Point(this->ui->curveR4X->text().toDouble(), this->ui->curveR4Y->text().toDouble()),
                        this->ui->precisaoCurva->text().toDouble(), this->chosenObjectColor.red(),
                        this->chosenObjectColor.green(), this->chosenObjectColor.blue());
}

void AddObjeto::resetInternalState()
{
    this->wireframe_wires.clear();
    this->continuosCurve.clear();

    this->ui->bsplineCoordinates->clear();
    this->bSplineCoordinates.clear();

    this->ui->curveContinuousP1X->setReadOnly(false);
    this->ui->curveContinuousP1Y->setReadOnly(false);

    this->ui->numeroCurvas->setText(0);
    this->ui->arestasAdcionadas->clear();
}

QList<Curve> AddObjeto::getContinuosCurve()
{
    return this->continuosCurve;
}

void AddObjeto::handleAddWire()
{
    Point start(this->ui->wireframeXIni->text().toDouble(), this->ui->wireframeYIni->text().toDouble(), this->ui->wireframeZIni->text().toDouble());
    Point end(this->ui->wireframeXFinal->text().toDouble(), this->ui->wireframeYFinal->text().toDouble(), this->ui->wireframeZFinal->text().toDouble());

    this->wireframe_wires.append(Wire(start, end));

    this->ui->wireframeXIni->setText(this->ui->wireframeXFinal->text());
    this->ui->wireframeYIni->setText(this->ui->wireframeYFinal->text());
    this->ui->wireframeZIni->setText(this->ui->wireframeZFinal->text());

    this->ui->wireframeXFinal->clear();
    this->ui->wireframeYFinal->clear();
    this->ui->wireframeZFinal->clear();

    this->ui->arestasAdcionadas->insertItem(this->ui->arestasAdcionadas->count(),
                                            QString("[") + start.toString() + QString("] to [") + end.toString() + QString("]"));
}

void AddObjeto::handleAddCurve()
{

    this->continuosCurve.append(CurveHermite(Point(this->ui->curveContinuousP1X->text().toDouble(),
                                                   this->ui->curveContinuousP1Y->text().toDouble()),
                                             Point(this->ui->curveContinuousP4X->text().toDouble(),
                                                   this->ui->curveContinuousP4Y->text().toDouble()),
                                             Point(this->ui->curveContinuousR1X->text().toDouble(),
                                                   this->ui->curveContinuousR1Y->text().toDouble()),
                                             Point(this->ui->curveContinuousR4X->text().toDouble(),
                                                   this->ui->curveContinuousR4Y->text().toDouble()),
                                             this->ui->precisaoCurvaContinua->text().toDouble(), this->chosenObjectColor.red(),
                                             this->chosenObjectColor.green(), this->chosenObjectColor.blue()));

    this->ui->curveContinuousP1X->setReadOnly(true);
    this->ui->curveContinuousP1Y->setReadOnly(true);

    this->ui->curveContinuousP1X->setText(this->ui->curveContinuousP4X->text());
    this->ui->curveContinuousP1Y->setText(this->ui->curveContinuousP4Y->text());

    this->ui->numeroCurvas->clear();
    this->ui->numeroCurvas->insert(QString().setNum(this->continuosCurve.size()));
}

void AddObjeto::handleAddCoordinate()
{
    this->bSplineCoordinates.append(Point(this->ui->bsplineX->text().toDouble(),this->ui->bsplineY->text().toDouble()));
    QString Coordinate(this->ui->bsplineX->text() + "," + this->ui->bsplineY->text());
    this->ui->bsplineX->clear();
    this->ui->bsplineY->clear();
    this->ui->bsplineCoordinates->addItem(Coordinate);
}

void AddObjeto::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AddObjeto::handleSelectColor(){
    this->chosenObjectColor = QColorDialog::getColor();
}



