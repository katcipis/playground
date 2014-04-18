#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    static const unsigned int STREAM_SIZE = 15728640;
    static const unsigned int CHUNK_SIZE = 2048;
    unsigned int sent_size = 0;

    while (sent_size < STREAM_SIZE) {
        void * buffer = malloc(CHUNK_SIZE);
        fwrite(buffer, CHUNK_SIZE, 1 , stdout);
        free(buffer);
        sent_size += CHUNK_SIZE;
    }

    return EXIT_SUCCESS;
}
