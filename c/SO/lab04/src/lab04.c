#include<unistd.h>
#include<stdio.h>
#include<getpids.h>
 
#define NIVEIS_FORK 8

int main(void) { 
    pid_t eu, pai; 
    int i; 

    GetPIDs(&eu, &pai);
    printf("=============== RAIZ =============\n"); 
    printf("Pid Filho = GetPIDs[%d] e getpid[%d]  \n",eu, getpid());
    printf("Pid Pai   = GetPIDs[%d] e getppid[%d] \n",pai, getppid());  
    printf("==================================\n");

    for (i = 0; i < NIVEIS_FORK; i++) {
        int ehPai = fork();
        if (ehPai) {
            break;
        }
        GetPIDs(&eu, &pai);
        printf("=============== NIVEL[%d] =============\n", i+1);
        printf("Pid Filho = GetPIDs[%d] e getpid[%d]  \n",eu, getpid());
        printf("Pid Pai   = GetPIDs[%d] e getppid[%d] \n",pai, getppid());
        printf("=======================================\n");
    }
    return 0; 
} 
