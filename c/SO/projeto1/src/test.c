#include<lib.h>
#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>


int main(void) { 
    SemInit(1,1);

    if (fork() == 0) {
        printf("PROCESSO PAI PID[%d] OBTENDO SEMAFORO !!!\n", getpid());
        SemDown(1);
        sleep(10);
        printf("PROCESSO PAI PID[%d] LIBERANDO SEMAFORO !!!\n", getpid());
        SemUp(1);
    } else {
        sleep(1);
        printf("PROCESSO FILHO PID[%d] OBTENDO SEMAFORO !!!\n", getpid());
        SemDown(1);
        printf("PROCESSO FILHO PID[%d] FOI DESBLOQUEADO DO SEMAFORO !!!\n", getpid());
        SemUp(1);
    }
    printf("ENCERRANDO PROCESSO[%d] !!!\n", getpid());
    return 0; 
} 
