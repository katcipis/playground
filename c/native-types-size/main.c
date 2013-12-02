#include <stdlib.h>
#include <stdio.h>

int main ()
{
    printf("long: %zu\n", sizeof(long));
    printf("int: %zu\n", sizeof(int));
    printf("void*: %zu\n", sizeof(void*));
    return EXIT_SUCCESS;
}
