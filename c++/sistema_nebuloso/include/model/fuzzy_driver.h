#ifndef FUZZY_DRIVER_H
#define FUZZY_DRIVER_H

#include "model/fuzzy_set.h"
#include "gui/car_gui.h"
#include <QThread>

class FuzzyDriver
{
public:
    static const int nAngulos = 7;
    static const int nX = 5;
    static const int nSaidas = 7;

    FuzzyDriver(CarGui* car);
    void run();

private:
    CarGui* car;
    QList<FuzzySet> fuzzySets;
    QList<FuzzySet> angleSets;
    QList<FuzzySet> outputSets;

    //patricia
    void configureFuzzySets();
    QList<FuzzySet> defineAnglesFuzzySets();
    QList<FuzzySet> defineCarFuzzySets();
    QList<FuzzySet> defineOutput();

};

#endif // FUZZY_DRIVER_H
