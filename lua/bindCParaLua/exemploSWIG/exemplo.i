%module exemplo
%{
#include "exemplo.h"
%}

/* 
   Se desejar fazer o parse do exemplo.h automaticamente em vez de 
   escrever tudo isso basta substituir todo o codigo abaixo por:
   %include "exemplo.h"
*/
%include "os.h" /*Vamos fazer parse do arquivo para obter a configuracao desejada*/

#define DEFINE_UM   "Define de um string"
#define DEFINE_DOIS 50

#ifdef LINUX
    #define OS "LINUX"
#else
    #define OS "OUTRO"
#endif

typedef struct vetor tipovetor;
tipovetor* aloca_vetor(int x, int y, int z);
void imprimir_vetor(tipovetor* vetor);

int funcao_um();
char* funcao_dois();
void funcao_tres();

enum EnumTeste{ENUM_TESTE1, ENUM_TESTE2,ENUM_TESTE3};

struct Ponto{
  int x,y;
};




