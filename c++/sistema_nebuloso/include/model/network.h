#ifndef NETWORK_H
#define NETWORK_H
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "model/layer.h"
#include <stdio.h>

class Network
{
public:

    int nInputs, nOutputs, trainSize, nHidden;
    QList< QList<double> > inputs, outputs;
    QList<double> simul, o, w;
    double lr;
    Layer hidden, output;

    Network();
    void inicializa(int ne, int q, int ns, int neuHid, double lrr);
    void set_inputs(QList<double> in);
    void feedfoward(int index);
    double train(int e, double ep);
    void openInputFile(QString file);
    void openOutputFile(QString file);
    void loadWeights(QString file);
    void saveWeights(QString file);
    void acumulaPesos() ;
    void setPesos(QList<double> p) ;
    void simular(QList<double> input);
};

#endif // NETWORK_H
