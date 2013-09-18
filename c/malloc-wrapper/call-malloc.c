#include <stdlib.h>
#include <stdio.h>
#include "call-malloc.h"

void call_malloc(void)
{
    printf("=== starting call_malloc on dynamic library ===\n");
    void * a = malloc(1024);
    void * b = malloc(2048);
    void * c = malloc(3000);

    free(a);
    free(b);
    free(c);
    printf("=== call_malloc on dynamic library done ===\n\n");
}
