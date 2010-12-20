#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

#define TAMANHO_NOME 1024
static char current_name[TAMANHO_NOME];

int main (int argc, char** argv)
{
    DIR *current = 0;
    struct dirent * entry = 0;

    char* ret = getcwd(current_name, TAMANHO_NOME);

    if (!ret) {
        printf("Erro obtendo nome do diretorio corrente !!\n");
        return -1;
    }

    if (argc < 2) {
        printf("Uso: %s [nome_arquivo]\n", argv[0]);
        return -1;
    }

    current = opendir(current_name);
    if (!current) {
        printf("Erro abrindo diretorio corrente[%s]!!\n", current_name);
        return -1;
    }

    while ((entry = readdir(current))) {
        if (strcmp(entry->d_name, argv[1]) == 0) {
            printf("Arquivo [%s] foi encontrado !!\n", entry->d_name);
            printf("Inode do arquivo eh: %lu\n", entry->d_ino);

            if (closedir(current) == -1) {
                printf("Erro fechando diretorio corrent !!!\n");
            }
            return 0;
        }
    }
    
    printf("Nao foi encontrado o arquivo [%s] no diretorio corrente !!\n", argv[1]);
    if (closedir(current) == -1) {
                printf("Erro fechando diretorio corrent !!!\n");
    }
    return 0;
}

