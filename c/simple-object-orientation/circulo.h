#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include "forma_geometrica.h"

typedef struct _Circulo  Circulo;

struct _Circulo{
    FormaGeometrica forma;
    long raio;
};

FormaGeometrica* new_circulo(long raio);

#endif
