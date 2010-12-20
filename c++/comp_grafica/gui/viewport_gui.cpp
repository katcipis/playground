#include "viewport_gui.h"
#include "viewport_2d.h"
#include "window_ortogonal.h"
#include "transform.h"

ViewPortGUI::ViewPortGUI(Ui::MainWindow *main_ui, Window *w) : QObject(),
                                                    ui(main_ui),
                                                    window(w),
                                                    margin(10),
                                                    vp_minpoint(Point(margin,margin)),
                                                    vp_maxpoint(Point(margin+1,margin+1)),
                                                    guidePen(QColor(255,0,0)),
                                                    rotateStep(10.0)

{
    this->ui->viewPort_graphicsView->setScene(new QGraphicsScene());
    QObject::connect(this->ui->plusZoomWindow,  SIGNAL(clicked()),this,SLOT(handlePlusZoom()));
    QObject::connect(this->ui->minusZoomWindow,  SIGNAL(clicked()),this,SLOT(handleMinusZoom()));

    QObject::connect(this->ui->up_window,   SIGNAL(clicked()),this,SLOT(handleUp()));
    QObject::connect(this->ui->down_window, SIGNAL(clicked()),this,SLOT(handleDown()));
    QObject::connect(this->ui->left_window, SIGNAL(clicked()),this,SLOT(handleLeft()));
    QObject::connect(this->ui->right_window,SIGNAL(clicked()),this,SLOT(handleRight()));
    QObject::connect(this->ui->in_window,   SIGNAL(clicked()),this,SLOT(handleIn()));
    QObject::connect(this->ui->out_window,  SIGNAL(clicked()),this,SLOT(handleOut()));

    QObject::connect(this->ui->rotateVUpPlus,  SIGNAL(clicked()),this,SLOT(handleRotateVUpPlus()));
    QObject::connect(this->ui->rotateVUpMinus, SIGNAL(clicked()),this,SLOT(handleRotateVUpMinus()));

    QObject::connect(this->ui->rotateXPlus,  SIGNAL(clicked()),this,SLOT(handleRotateXAxisPlus()));
    QObject::connect(this->ui->rotateXMinus, SIGNAL(clicked()),this,SLOT(handleRotateXAxisMinus()));

    QObject::connect(this->ui->rotateYPlus,  SIGNAL(clicked()),this,SLOT(handleRotateYAxisPlus()));
    QObject::connect(this->ui->rotateYMinus, SIGNAL(clicked()),this,SLOT(handleRotateYAxisMinus()));

    // TODO COMO DESCOBRIR QUANDO O TAMANHO DA JANELA FOI ALTERADO? ASSIM PODEMOS CHAMAR O refreshSize.
    // QObject::connect(this->ui->viewPort_graphicsView,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(handleResizeEvent(QResizeEvent*)));
}

ViewPortGUI::~ViewPortGUI()
{
    delete this->window;
}

void ViewPortGUI::setNewWindow(Window *newWindow)
{
    if (!newWindow) {
        return;
    }

    delete this->window;
    this->window = newWindow;
    this->redraw();
}

void ViewPortGUI::reset()
{
    this->window->clear();
}

Window* ViewPortGUI::getWindow()
{
    return this->window;
}

void ViewPortGUI::refreshSize()
{
    double maxX = this->ui->viewPort_graphicsView->viewport()->width();
    double maxY = this->ui->viewPort_graphicsView->viewport()->height();

    this->vp_maxpoint = Point(maxX - margin, maxY - margin);

    this->window->setWidth(maxX);
    this->window->setHeight(maxY);

    this->ui->viewPort_graphicsView->scene()->setSceneRect(QRectF(this->pointToQPoint(Point(0,0)),
                                                                  this->pointToQPoint(Point(maxX,maxY))));
}

void ViewPortGUI::addPoint(Point point)
{
    this->window->insertPoint(point);
    this->redraw();
}

void ViewPortGUI::addCurve(Curve curve)
{
    this->window->insertCurve(curve);
    this->redraw();
}

void ViewPortGUI::addWire(Wire wire)
{
    this->window->insertWire(wire);
    this->redraw();
}

void ViewPortGUI::addWireFrame(WireFrame wireframe)
{
    this->window->insertWireFrame(wireframe);
    this->redraw();
}

void ViewPortGUI::removePoint(const Point& point)
{
    this->window->removePoint(point);
    this->redraw();
}

void ViewPortGUI::removeWire(const Wire& wire)
{
    this->window->removeWire(wire);
    this->redraw();
}

void ViewPortGUI::removeCurve(const Curve& curve)
{
    this->window->removeCurve(curve);
    this->redraw();
}

void ViewPortGUI::removeWireFrame(const WireFrame& wireframe)
{
    this->window->removeWireFrame(wireframe);
    this->redraw();
}

QPointF ViewPortGUI::pointToQPoint(Point point)
{
    return QPointF(point.getX(), point.getY());
}

double ViewPortGUI::getPasso()
{
    return this->ui->passo_field->text().toDouble() * 0.1;
}

void ViewPortGUI::drawnWires(const QList<Wire>& wires)
{
    for (int i = 0; i < wires.size(); i++) {
        Wire wire = viewport_2d::transform(wires[i], this->window->getMinPoint(), this->window->getMaxPoint(),
                                           this->vp_minpoint, this->vp_maxpoint, this->margin);

        const QPen objectColor(QColor(wires[i].getRed(), wires[i].getGreen(), wires[i].getBlue()));
        this->ui->viewPort_graphicsView->scene()->addLine(wire.getFirstPoint().getX(),
                                                          wire.getFirstPoint().getY(),
                                                          wire.getSecondPoint().getX(),
                                                          wire.getSecondPoint().getY(), objectColor);
    }
}

void ViewPortGUI::drawnWireFrame(const WireFrame& wireframe)
{
    QPolygon polygon;
    const QPen   objectColor(QColor(wireframe.getRed(), wireframe.getGreen(), wireframe.getBlue()));
    const QBrush objectBrush(QColor(wireframe.getRed(), wireframe.getGreen(), wireframe.getBlue()), Qt::SolidPattern);
    const QList<Wire>& wires = wireframe.getWires();

    if (!wireframe.isAClosedPolygon()) {
        /* more workaround because we do not use object3D on the system */
        for (int i = 0; i < wires.size(); i++ ) {
            this->ui->viewPort_graphicsView->scene()->addLine(wires[i].getFirstPoint().getX(),
                                                              wires[i].getFirstPoint().getY(),
                                                              wires[i].getSecondPoint().getX(),
                                                              wires[i].getSecondPoint().getY(),
                                                              objectColor);
        }
        return;
    }

    /* build a normal closed polygon */
    for (int i = 0; i < wires.size(); i++ ) {
        polygon << QPoint(wires[i].getFirstPoint().getX(), wires[i].getFirstPoint().getY());
        polygon << QPoint(wires[i].getSecondPoint().getX(), wires[i].getSecondPoint().getY());
    }

    if (wireframe.isFilled()) {
        this->ui->viewPort_graphicsView->scene()->addPolygon(polygon, objectColor, objectBrush);
    } else {
        this->ui->viewPort_graphicsView->scene()->addPolygon(polygon, objectColor);
    }
}

void ViewPortGUI::handlePlusZoom()
{
    this->window->zoomMinus();
    this->redraw();
}

void ViewPortGUI::handleMinusZoom()
{
    this->window->zoomPlus();
    this->redraw();
}

void ViewPortGUI::handleIn()
{
    this->window->translateIn(this->getPasso());
    this->redraw();
}

void ViewPortGUI::handleOut()
{
    this->window->translateOut(this->getPasso());
    this->redraw();
}

void ViewPortGUI::handleUp()
{
    this->window->translateUp(this->getPasso());
    this->redraw();
}

void ViewPortGUI::handleDown()
{
    this->window->translateDown(this->getPasso());
    this->redraw();
}

void ViewPortGUI::handleLeft()
{
    this->window->translateLeft(this->getPasso());
    this->redraw();
}

void ViewPortGUI::handleRight()
{
    this->window->translateRight(this->getPasso());
    this->redraw();
}

void ViewPortGUI::handleRotateVUpPlus ()
{
    this->window->rotateAroundZ(transform::fromDegreeToRadian(rotateStep));
    this->redraw();
}

void ViewPortGUI::handleRotateVUpMinus ()
{
    this->window->rotateAroundZ(transform::fromDegreeToRadian(-rotateStep));
    this->redraw();
}

void ViewPortGUI::handleRotateXAxisPlus ()
{
    this->window->rotateAroundX(transform::fromDegreeToRadian(rotateStep));
    this->redraw();
}

void ViewPortGUI::handleRotateXAxisMinus ()
{
    this->window->rotateAroundX(transform::fromDegreeToRadian(-rotateStep));
    this->redraw();
}

void ViewPortGUI::handleRotateYAxisPlus ()
{
    this->window->rotateAroundY(transform::fromDegreeToRadian(rotateStep));
    this->redraw();
}

void ViewPortGUI::handleRotateYAxisMinus ()
{
    this->window->rotateAroundY(transform::fromDegreeToRadian(-rotateStep));
    this->redraw();
}

void ViewPortGUI::drawViewportRect()
{
    int x = this->ui->viewPort_graphicsView->viewport()->width();
    int y = this->ui->viewPort_graphicsView->viewport()->height();

    this->ui->viewPort_graphicsView->scene()->addLine(this->margin,
                                                      this->margin,
                                                      this->margin,
                                                      y - this->margin,
                                                      this->guidePen);

    this->ui->viewPort_graphicsView->scene()->addLine(this->margin,
                                                      y - this->margin,
                                                      x - this->margin,
                                                      y - this->margin,
                                                      this->guidePen);

    this->ui->viewPort_graphicsView->scene()->addLine(x - this->margin,
                                                      y - this->margin,
                                                      x - this->margin,
                                                      this->margin,
                                                      this->guidePen);

    this->ui->viewPort_graphicsView->scene()->addLine(x - this->margin,
                                                      this->margin,
                                                      this->margin,
                                                      this->margin,
                                                      this->guidePen);
}

void ViewPortGUI::drawXYAxis()
{
    int x = this->ui->viewPort_graphicsView->viewport()->width();
    int y = this->ui->viewPort_graphicsView->viewport()->height();


    this->ui->viewPort_graphicsView->scene()->addLine(0,
                                                      y / 2,
                                                      x,
                                                      y / 2,
                                                      this->guidePen);

    this->ui->viewPort_graphicsView->scene()->addLine(x / 2,
                                                      0,
                                                      x / 2,
                                                      y,
                                                      this->guidePen);
}

void ViewPortGUI::redraw()
{
    this->refreshSize();
    this->ui->viewPort_graphicsView->scene()->clear();

    this->drawXYAxis();
    this->drawViewportRect();

    const QList<Wire>& wires           = this->window->getWires();
    const QList<WireFrame>& wireframes = this->window->getWireFrames();
    const QList<Point>& points         = this->window->getPoints();

    for (int i = 0; i < points.size(); i++) {
        Point point = viewport_2d::transform(points[i], this->window->getMinPoint(), this->window->getMaxPoint(),
                                             this->vp_minpoint, this->vp_maxpoint, this->margin);

        const QPen objectColor(QColor(points[i].getRed(), points[i].getGreen(), points[i].getBlue()));
        this->ui->viewPort_graphicsView->scene()->addLine(point.getX(),
                                                          point.getY(),
                                                          point.getX() + 0.1,
                                                          point.getY() + 0.1,
                                                          objectColor);
    }

    this->drawnWires(wires);

    for (int i = 0; i < wireframes.size(); i++) {
        this->drawnWireFrame(viewport_2d::transform(wireframes[i], this->window->getMinPoint(), this->window->getMaxPoint(),
                                                                   this->vp_minpoint, this->vp_maxpoint, this->margin));
    }
}
