#include "circulo.h"
#include <math.h>
#include <stdlib.h>

char* obterNomeCirculo(void* circulo){
    return "Circulo";
}

long obterAreaCirculo(void* circulo){
    long pi = 3.41592653;
    return (pow(((Circulo*) circulo)->raio, 2) * pi);
}

FormaGeometrica* new_circulo(long raio){
    Circulo* circulo = malloc(sizeof(*circulo));
    FormaGeometrica* forma = (FormaGeometrica*) circulo;
    
    circulo->raio = raio;

    forma->_obterNome = obterNomeCirculo;
    forma->_obterArea = obterAreaCirculo;

    return forma;  
}

