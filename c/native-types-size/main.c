#include <stdlib.h>
#include <stdio.h>

int main ()
{
    printf("int: %zu\n", sizeof(int));
    printf("size_t: %zu\n", sizeof(size_t));
    printf("long: %zu\n", sizeof(long));
    printf("void*: %zu\n", sizeof(void*));
    return EXIT_SUCCESS;
}
