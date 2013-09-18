#include <stdlib.h>
#include "call-malloc.h"

void call_malloc(void)
{
    void * a = malloc(1024);
    void * b = malloc(2048);
    void * c = malloc(3000);

    free(a);
    free(b);
    free(c);
}
