#include <unistd.h>
#include <stdio.h>
#include <fscontig.h>
#include <sys/types.h>
#include <fcntl.h>

int main (int argc, char** argv)
{
    int fd  = 0;

    if (argc < 2) {
        printf("Erro: uso: %s [path_arquivo]\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY, 0);
    if (fd == -1) {
        printf("Erro abrindo arquivo[%s] para leitura !!\n", argv[1]);
        return -1;
    }

    printf("fscontig retornou: %d\n", fscontig(fd));

    if ((close(fd) == -1)) {
        printf("Erro fechando arquivo !!\n");
        return -1;
    }
}
