#include "exemplo.h"
#include <stdio.h>
#include <stdlib.h>

struct vetor {
    int x,y,z;
};

int funcao_um()
{
    return 69;
}

char* funcao_dois()
{
    return "parabens voce linkou e usou a lib exemplo com sucesso";
}

void funcao_tres()
{
    printf("parabens voce linkou e usou a lib exemplo com sucesso\n");   
}

tipovetor* aloca_vetor(int x, int y, int z)
{
    tipovetor* vetor = malloc(sizeof(tipovetor));
    vetor->x = x;
    vetor->y = y;
    vetor->z = z;
    return vetor;
}

void imprimir_vetor(tipovetor* vetor)
{
    printf("Vetor x[%d] y[%d] z[%d]\n", vetor->x, vetor->y, vetor->z);
}
