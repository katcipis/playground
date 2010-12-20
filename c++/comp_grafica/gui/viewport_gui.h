#ifndef VIEWPORT_GUI_H
#define VIEWPORT_GUI_H

#include <QObject>
#include "ui_mainwindow.h"
#include "window.h"

class ViewPortGUI : public QObject
{
Q_OBJECT
public:
    ViewPortGUI(Ui::MainWindow *main_ui, Window *window);
    ~ViewPortGUI();

    void addPoint(Point point);
    void addWire(Wire wire);
    void addWireFrame(WireFrame wireframe);
    void addCurve(Curve curve);

    void removePoint(const Point& point);
    void removeWire(const Wire& wire);
    void removeWireFrame(const WireFrame& wireframe);
    void removeCurve(const Curve& curve);

    void setNewWindow(Window *newWindow);
    Window* getWindow();
    void reset();

private:
    Ui::MainWindow *ui;
    Window* window;
    int margin;
    Point vp_minpoint;
    Point vp_maxpoint;
    QPen guidePen;
    double rotateStep;

    void redraw();
    void refreshSize();
    double getPasso();
    void drawXYAxis();
    void drawViewportRect();
    void drawnWires(const QList<Wire>& wires);
    void drawnWireFrame(const WireFrame& wireframe);

    QPointF pointToQPoint(Point point);

private slots:
    void handlePlusZoom();
    void handleMinusZoom();
    void handleUp();
    void handleDown();
    void handleLeft();
    void handleRight();
    void handleIn();
    void handleOut();
    void handleRotateVUpPlus();
    void handleRotateVUpMinus();
    void handleRotateXAxisPlus();
    void handleRotateXAxisMinus();
    void handleRotateYAxisPlus();
    void handleRotateYAxisMinus();
};

#endif // VIEWPORT_GUI_H
