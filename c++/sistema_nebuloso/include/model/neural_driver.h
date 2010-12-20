#ifndef NEURAL_DRIVER_H
#define NEURAL_DRIVER_H

#include "model/network.h"
#include "gui/car_gui.h"
#include <iostream>

class neural_driver
{
public:

    static int nAngulos; //7
    static int nX; //5
    static int nSaidas; //7

    Network rede;

    CarGui* car;

    neural_driver(CarGui* car);
    void setTruckPosition(int x, int y , double angulo);
    void run();
};

#endif // NEURAL_DRIVER_H
