#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * For someone that has good C knowledge this is pretty obvious.
 * To someone used to high level languages, this is pretty odd and wrong :-).
 * Thats why C is so cool ;-).
 */

static void
check_that_sizeof_being_naughty(char * array)
{
    printf("size[%i]\n", sizeof(array));
}

int main()
{
    char array[80];
    
    check_that_sizeof_being_naughty(array);

    unsigned int i;

    for (i = 0; i < sizeof(array); i++) {
        array[i] = (char)i;
    }

    printf("size[%i]\n", sizeof(array));
    return 0;
}

