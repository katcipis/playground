#include "circulo.h"
#include "quadrado.h"
#include<stdio.h>

int main(){
    FormaGeometrica* circulo;
    FormaGeometrica* quadrado;
    circulo = new_circulo(5.5);
    quadrado = new_quadrado(5.5);

    printf("Area da forma: %ld\n", obterAreaDaForma(circulo));
    printf("Nome da forma: %s\n",  obterNomeDaForma(circulo));

    printf("\nArea da forma: %ld\n", obterAreaDaForma(quadrado));
    printf("Nome da forma: %s\n",  obterNomeDaForma(quadrado));
    return 1;
}


