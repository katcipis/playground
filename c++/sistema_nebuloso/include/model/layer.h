#ifndef LAYER_H
#define LAYER_H
#include <QList>
#include <cstdlib>
#include <cmath>


class Layer
{
public:
    int neuronios;
    int entradas;
    int funcao;

    double lr;
    QList<double> o,input,e,net,y;
    QList< QList<double> > w;
    Layer *proxima, *anterior;

    Layer();


    void update_weights();
    QList<double> calc_erro();
    void setTarget(QList<double> t);
    double dsigmoid(double x);
    double sigmoid(double x);
    void sub_weights(int n,QList<double> delta);
    void sum_weights(int n, QList<double> delta);
    void calculate_output(QList<double> in);
    void inicializa(int entrs,int neurons,int func, Layer *prox,Layer *ant,double lrr);



};

#endif // LAYER_H
