#ifndef FORMA_GEOMETRICA_HPP
#define FORMA_GEOMETRICA_HPP

typedef struct _FormaGeometrica  FormaGeometrica;

typedef char* (*fcnFormaGeometricaNome) (void*); 

typedef long  (*fcnFormaGeometricaArea) (void*); 


struct _FormaGeometrica{

    fcnFormaGeometricaNome _obterNome;
    fcnFormaGeometricaArea _obterArea;

};

char* obterNomeDaForma(FormaGeometrica* forma);
long obterAreaDaForma(FormaGeometrica* forma);


#endif
