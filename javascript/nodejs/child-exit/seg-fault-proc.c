#include <stdlib.h>

int main ()
{
    char * random_crap = (char*) 0xaaffdd00;
    random_crap[0] = 255;
    return EXIT_SUCCESS;
}
