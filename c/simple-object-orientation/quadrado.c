#include "quadrado.h"
#include <stdlib.h>

char* obterNomeQuadrado(void* quadrado){
    return "Quadrado";
}

long obterAreaQuadrado(void* quadrado){
    return ((Quadrado*) quadrado)->lado * ((Quadrado*) quadrado)->lado ;
}

FormaGeometrica* new_quadrado(long lado){
    Quadrado* quadrado = malloc(sizeof(*quadrado));
    FormaGeometrica* forma = (FormaGeometrica*) quadrado;

    quadrado->lado = lado;

    forma->_obterNome = obterNomeQuadrado;
    forma->_obterArea = obterAreaQuadrado;

    return forma;
}

