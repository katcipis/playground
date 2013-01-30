#include "forma_geometrica.h"

char* obterNomeDaForma(FormaGeometrica* forma){
    if(forma->_obterNome == 0)
      return 0;

    return forma->_obterNome(forma);
}

long obterAreaDaForma(FormaGeometrica* forma){
    if(forma->_obterArea == 0)
      return 0;

    return forma->_obterArea(forma);
}


