#include <stdlib.h>
#include <stdio.h>
#include "call-malloc.h"

void call_malloc(void)
{
    printf("=== starting to call malloc inside the library ===\n");
    void * a = malloc(1024);
    void * b = malloc(2048);
    void * c = malloc(3000);

    free(a);
    free(b);
    free(c);
    printf("=== all calls to malloc inside the library are done ===\n\n");
}
