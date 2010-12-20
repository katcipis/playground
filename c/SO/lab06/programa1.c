#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TAMANHO_BLOCO 4096
static char buffer[TAMANHO_BLOCO];

int main (int argc, char** argv)
{
    int fd_origem  = 0;
    int fd_destino = 0;
    int lido = 0;
    int gravado = 0;
    int total = 0;

    if (argc < 3) {
        printf("Erro: uso: %s [arquivo origem] [arquivo destino]\n", argv[0]);
        return -1;
    }

    if (access(argv[1], F_OK) != 0) {
        printf("Erro: arquivo origem [%s] nao existe !!\n", argv[1]);
        return -1;
    }

    if (access(argv[1], R_OK) != 0) {
        printf("Erro: Nao eh possivel ler de [%s] !!\n", argv[1]);
        return -1;
    }

    if (access(argv[2], F_OK) == 0) {
        printf("Erro: arquivo destino [%s] ja existe !!\n", argv[2]);
        return -1;
    }

    fd_origem = open(argv[1], O_RDONLY, 0);
    if (fd_origem == -1) {
        printf("Erro abrindo arquivo[%s] para leitura !!\n", argv[1]);
        return -1;
    }

    fd_destino = creat(argv[2], S_IRWXU);
    if (fd_destino == -1) {
        printf("Erro criando arquivo de destino [%s]\n", argv[2]);
        return -1;
    }

  
    while ((lido = read(fd_origem, buffer, TAMANHO_BLOCO))) {
        printf("Foram lidos [%i]\n", lido);
        total += lido;
        gravado = write(fd_destino, buffer, lido);
        if (gravado < lido) {
            printf("ERRO !!! tentou gravar[%i] mas soh gravou[%i]\n", lido, gravado);
            break;
        }
    }
 
    printf("Copia terminada, total de bytes transferidos [%i]\n", total);
    if ((close(fd_origem) == -1) || (close(fd_destino) == -1)) {
        printf("Erro fechando os arquivos !!\n");
        return -1;
    } 

    return 0;
}
