#ifndef QUADRADO_HPP
#define QUADRADO_HPP

#include "forma_geometrica.h"

typedef struct _Quadrado Quadrado;

struct _Quadrado{
    FormaGeometrica forma;
    long lado;
};

FormaGeometrica* new_quadrado(long lado);

#endif

