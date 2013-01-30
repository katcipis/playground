/*
 * Tiago Katcipis <tiagokatcipis@gmail.com>
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NUM_FILHOS 6

void espera_filho_terminar(pid_t filhos[])
{
    pid_t filho_terminou;
    int status = 0;
    int i;

    printf("processo pai vai esperar o termino de um dos filhos\n");   
    while ( (filho_terminou = wait(&status)) == -1) { 
        printf("ocorreu um erro ao fazer wait nos processos filhos, status[%d]\n", status);
    }
    printf("processo pai retornou do wait!!!\nfilho PID: %d  terminou naturalmente com status: %04x.\nParando todos os outros filhos !!!!\n", filho_terminou, status);

    for (i=0; i < NUM_FILHOS; i++) {
        int kill_ret = 0;        

        if (filhos[i] == filho_terminou) {
            continue;
        }
       
        kill_ret = kill(filhos[i], SIGKILL);
        if (kill_ret == -1) {
            printf("erro ao tentar matar processo filho pid[%d], errno[%d] errno_msg[%s]\n", filhos[i], errno, strerror(errno));
            continue;
        }
        printf("foi enviado o comando kill para o processo pid[%d], status retorno da chamada[%d]!\n", filhos[i], kill_ret);
        printf("\tchamando waitpid no processo filho pid[%d]\n", filhos[i]);
        waitpid(filhos[i], &status, 0);
        printf("\tprocesso pai retornou do waitpid!!\n\tprocesso pid[%d] realmente foi morto, status[%d]\n", filhos[i], status); 
    }
}

void dormir(int sleep_time)
{
    printf("processo pid[%d] esta dormindo\n", getpid());
    sleep(sleep_time);
    printf("processo morrendo de causa natural :-), pid[%d], pid do pai[%d]\n", getpid(), getppid());
}

int main (void) {
    pid_t pid_filhos[NUM_FILHOS];
    int i;
    int sou_pai = 1;

    /* criar 6 filhos */
    for (i=0; i < NUM_FILHOS; i++) {
        pid_t ret;
        if ( (ret=fork()) != 0) {
   	    pid_filhos[i] = ret;
            printf("processo pai pid[%d] criou processo filho pid[%d]\n", getpid(), ret);
        } else {
            sou_pai = 0;
            dormir(i + 1);
            break;
        }
    }

    if (sou_pai) {
        espera_filho_terminar(pid_filhos);
    }

    exit(0);
}

