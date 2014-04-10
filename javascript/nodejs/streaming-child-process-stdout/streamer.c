#include <stdlib.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
    int i ;
    for (i = 0; i < 10000; i ++) {
        void * data = malloc(2048);
        fwrite(data, 2048, 1, stdout);
    }
    return EXIT_SUCCESS;
}
