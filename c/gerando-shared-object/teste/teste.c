#include "exemplo.h"
#include <stdio.h>

int main()
{
    int a = funcao_um();
    char* b = funcao_dois();
    printf("funcao_um %d\n", a);
    printf("funcao_dois %s\n",b);
    funcao_tres();
    return 1;    
}
