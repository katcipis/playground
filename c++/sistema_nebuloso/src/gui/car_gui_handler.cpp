#include "gui/car_gui_handler.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QKeyEvent>
#include "gui/window_size.h"


CarGuiHandler::CarGuiHandler(Ui::MainWindow* u) : ui(u), car(0)
{
    QObject::connect(this->ui->insertCar, SIGNAL(clicked()),this,SLOT(handleAddCar()));
    QObject::connect(this->ui->exec,      SIGNAL(clicked()),this,SLOT(handleStartFuzzyDriver()));

    this->ui->drawArea->scene()->setSceneRect(QRectF(0,0, WINDOW_WIDTH, WINDOW_HEIGHT));
    this->drawGarage();
}

CarGuiHandler::~CarGuiHandler()
{
    delete this->car;
    if (this->garage) {
        this->ui->drawArea->scene()->removeItem(this->garage);
    }
}

void CarGuiHandler::drawGarage()
{
    QVector<QPointF> garPoints;

    garPoints.append(QPointF(WINDOW_GARAGE_X - 70, WINDOW_GARAGE_Y));
    garPoints.append(QPointF(WINDOW_GARAGE_X + 70, WINDOW_GARAGE_Y));

    this->garage = this->ui->drawArea->scene()->addPolygon(QPolygonF(garPoints));
}

CarGui* CarGuiHandler::getCar()
{
    return this->car;
}

void CarGuiHandler::handleAddCar()
{
    double x = this->ui->carX->text().toDouble();
    double y = this->ui->carY->text().toDouble();
    double angle = this->ui->carAngle->text().toDouble();

    if (this->car) {
        delete this->car;
        this->car = 0;
    }

    this->car = new CarGui(this->ui->drawArea, QPointF(x, y), angle);
}

void CarGuiHandler::handleStartFuzzyDriver()
{
    FuzzyDriver(this->car);
}
