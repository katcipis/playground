#ifndef EXEMPLO_HPP
#define EXEMPLO_HPP
#include "os.h"

#define DEFINE_UM   "Define de um string"
#define DEFINE_DOIS 50

#ifdef LINUX
    #define OS "LINUX"
#else
    #define OS "OUTRO"
#endif

struct Ponto{
  int x,y;
};

//estrutura opaca
typedef struct vetor tipovetor;

enum {
    ENUM_TESTE1,
    ENUM_TESTE2,
    ENUM_TESTE3
}EnumTeste;

int funcao_um();
char* funcao_dois();
void funcao_tres();

tipovetor* aloca_vetor(int x, int y, int z);
void imprimir_vetor(tipovetor* vetor);

#endif /*EXEMPLO_HPP*/
