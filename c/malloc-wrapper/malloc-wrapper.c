#include "call-malloc.h"
#include <stdlib.h>
#include <stdio.h>

extern void * __real_malloc(size_t size);

void * __wrapper_malloc(size_t size)
{
    printf("wrapped malloc call for size[%zu]\n", size);
    void * ret = __real_malloc(size);
    printf("returning [%p]\n", ret);
    return ret;
}

int main(void)
{
    call_malloc();
    return 0;
}
