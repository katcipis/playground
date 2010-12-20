#ifndef CAR_GUI_HANDLER_H
#define CAR_GUI_HANDLER_H

#include <QObject>
#include <QGraphicsView>
#include <QMap>
#include <QPointF>
#include <math.h>

#include "gui/car_gui.h"
#include "model/fuzzy_driver.h"

namespace Ui {
    class MainWindow;
}

class CarGuiHandler : QObject{
    Q_OBJECT

private:
    Ui::MainWindow* ui;
    CarGui* car;
    QGraphicsPolygonItem* garage;

    void drawGarage();

private slots:
    void handleAddCar();
    void handleStartFuzzyDriver();

public:
    CarGuiHandler(Ui::MainWindow* ui);
    ~CarGuiHandler();
    void keyPressEvent(QKeyEvent * event);
    CarGui* getCar();
};

#endif // CAR_GUI_HANDLER_H
