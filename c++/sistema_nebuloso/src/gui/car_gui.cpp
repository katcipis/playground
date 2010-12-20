#include "gui/car_gui.h"
#include <QGraphicsRectItem>
#include <cmath>
#include <math.h>
#include <iostream>

static double PI = std::atan2(0.0,-1.0);

CarGui::CarGui(QGraphicsView* draw, QPointF position, double rot) : drawArea(draw), currentCar(0)
{
    this->speed = 20;
    this->rotation = rot;
    this->setPos(position.x(), position.y());
    std::cout << "CarGui::CarGui Criado com rotacao : " << rot << "]" << std::endl;
}

CarGui::~CarGui()
{
    if (!this->drawArea->scene()) {
        return;
    }

    for (int i = 0; i < this->drawnCars.size(); i++) {
        this->drawArea->scene()->removeItem(this->drawnCars[i]);
    }
    this->drawnCars.clear();

    if (this->currentCar) {
        this->drawArea->scene()->removeItem(this->currentCar);
        this->currentCar = 0;
    }
}


void CarGui::draw()
{
    QPolygonF newCar(this->points);

    if (this->currentCar) {
        this->currentCar->setPen(QPen(QColor(255,0,0)));
        this->drawnCars.append(this->currentCar);
        this->currentCar = 0;
    }
    std::cout << "CarGui::draw new car drawn, total drawn cars[" << this->drawnCars.size() << "]" << std::endl;
    this->currentCar = this->drawArea->scene()->addPolygon(newCar);
}

void CarGui::setPos(double x, double y) {
    this->position = QPointF(x,y);

    std::cout << "CarGui::setPos nova posicao x[" << x << "] y[" << y << "]" << std::endl;

    double sinV = sin((rotation / 180.0) * PI);
    double cosV = cos((rotation / 180.0) * PI);

    this->points.clear();

    this->points.append(QPointF((x + l * sinV), (y + l * cosV)));
    this->points.append(QPointF((x - l * sinV), (y - l * cosV)));
    this->points.append(QPointF((x - c * cosV - l * sinV),
                              (y + c * sinV - l * cosV)));//
    this->points.append(QPointF((x - c * cosV + l * sinV),
                              (y + c * sinV + l * cosV)));
    this->points.append(QPointF(points[0].x(), points[0].y()));

    sinV = sin(((rotation + 60.0) / 180.0) * PI);
    cosV = cos(((rotation + 60.0) / 180.0) * PI);
    this->points.append(QPointF((x + l * sinV), (y + l * cosV)));

    sinV = sin(((rotation - 60.0) / 180.0) * PI);
    cosV = cos(((rotation - 60.0) / 180.0) * PI);
    this->points.append(QPointF((x - l * sinV), (y - l * cosV)));

    this->points.append(QPointF(points[1].x(), points[1].y()));
    this->draw();
}

QPointF CarGui::getPos() {
    return this->position;
}


void CarGui::stepManeuver(double axisRot) {
    double sinV = sin(((-axisRot * maxAxisAngle + rotation) / 180.0) * PI);
    double cosV = cos(((-axisRot * maxAxisAngle + rotation) / 180.0) * PI);

    double dx = (this->position.x() - cosV * speed);
    double dy = (this->position.y() + sinV * speed);
    rotation = axisRot * maxAxisAngle + rotation;
    if (rotation < 0) {
        rotation += 360;
    }
    this->setPos(dx, dy);
}

void CarGui::stepManeuver(double axisRot, int sp) {
    if (sp < 10) {
        sp = 10;
    }
    this->speed = sp;
    stepManeuver(axisRot);
}

QPointF CarGui::getPoint(int index) {
    return points[index];
}

double CarGui::getRotation() {
    return rotation;
}

void CarGui::setRotation(double rotation) {
    this->rotation = rotation;
}


