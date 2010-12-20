#include "layer.h"

Layer::Layer()
{
}

void Layer::inicializa(int entrs,int neurons,int func, Layer *prox,Layer *ant,double lrr){
        this->neuronios=neurons;
        this->entradas=entrs;
        this->y = QList<double>();
        this->w = QList< QList<double> >();


        QList<double> temp;
        for (int i=0;i<neuronios;i++)
            for (int c=0;c<=entradas;c++){
                temp = this->w[i];
                temp.insert(c, rand() );
                this->w.insert(i, temp);
            }

        this->proxima = prox;
        this->anterior = ant;
        this->funcao=func;
        this->lr=lrr;
        this->input =QList<double>();
        this->o= QList<double>();
        this->net= QList<double>();
        this->e = QList<double>();
}

void Layer::calculate_output(QList<double> in) {
        double soma;
        for (int n=0;n<this->entradas;n++)
                input.insert(n, in[n]);

        for (int i=0; i<this->neuronios ; i++){
                soma=0;
                for (int n=0;n<this->entradas;n++)
                        soma+= in[n] * w[i][n];

                net.insert(i, soma + w[i][entradas]);
                if (funcao==1)
                        o.insert(i, sigmoid(net[i]));
                else o.insert(i, net[i]);
        }
}

void Layer::sum_weights(int n, QList<double> delta){
    QList<double> aux1;
    double aux2;

    for (int en=0;en<this->entradas;en++){
            aux1 = w[n];
            aux2 = aux1[en];
            aux2 += delta[en];
            aux1.insert(en, aux2);
            w.insert(n, aux1);
    }
}

void Layer::sub_weights(int n,QList<double> delta){

    QList<double> aux1;
    double aux2;
    for (int en=0;en<this->entradas;en++){
        aux1 = w[n];
        aux2 = aux1[en];
        aux2 -= delta[en];
        aux1.insert(en, aux2);
        w.insert(n, aux1);
    }
}

double Layer::sigmoid(double x){
    double e =  2.71828183;
    return 1/(1 + pow(e, -1*x) );
    //return 1/(1+Math.exp(-1*(x)));

}

double Layer::dsigmoid(double x){
        return sigmoid(x)*(1-sigmoid(x));
}

void Layer::setTarget(QList<double> t){
        for (int j=0;j<this->neuronios;j++)
                y.insert(j, t[j]);
}

QList<double> Layer::calc_erro(){
        double soma;
        if (this->funcao==1){
                for (int n=0;n<this->neuronios;n++){
                        soma=0;
                        for (int c=0;c< proxima->neuronios ;c++){
                                soma+= this->proxima->e[c] * this->proxima->w[c][n];
                                soma+= this->proxima->e[c] * this->proxima->w[c][n+1];
                        }
                        this->e.insert(n, this->dsigmoid(net[n])* soma);
                }
        }else
                for (int i=0;i<this->neuronios;i++)
                        this->e.insert(i, (this->y[i] - this->o[i]));
        return e;
}


// Atualiza os pesos do BP comum
void Layer::update_weights(){
        double inpI;
        QList<double> aux1;
        double aux2;

        for (int n=0;n<this->neuronios;n++){
                for (int i=0;i<this->entradas;i++){
                        if (this->funcao==1) inpI =  input[i];
                        else{
                                inpI = this->anterior->o[i];
                            }

                        aux1 = w[n];
                        aux2 = aux1[i];
                        aux2 += ( this->lr * this->e[n] * inpI);
                        aux1.insert(i, aux2);
                        w.insert(n, aux1);

                }
                w[n][entradas] += ( this->lr * this->e[n] );
        }

}
