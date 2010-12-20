#include <stdio.h>

#define ASMV    __asm__ __volatile__

static int esp() 
{
    int value; 
    ASMV("movl %%esp,%0" : "=r"(value) :); 
    return value;
}

void test_func(int a, int b, int c)
{
    printf("Inside test_func: ESP[%u]\n", esp());
    printf("Stack addresses: a [%u] b[%u] c[%u] \n", (unsigned int) &a, 
                                                     (unsigned int) &b, 
                                                     (unsigned int) &c);
    return;
}

int main(int argc, char * argv[])
{
    printf("Before calling test_func: ESP[%u]\n", esp());
    test_func(1, 2, 3);
    printf("After calling test_func: ESP[%u]\n", esp());
    return 1;
}
