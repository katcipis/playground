/*
 * Tiago Katcipis <tiagokatcipis@gmail.com>
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#define NUM_FILHOS 6

static void tratador_termino_processo_filho(int signum, siginfo_t * info, void * contexto)
{
    if (signum != SIGCHLD) {
        printf("aconteceu algo errado, este tratador eh de apenas SIGCHLD porem o sinal recebido eh [%d] !!\n", signum);
        return;
    }

    printf("pai recebeu sinal SIGCHLD do processo filho pid[%d] que encerrou !!", info->si_pid);
    printf(" errno[%d] errnomsg[%s]\n", info->si_errno, strerror(info->si_errno));
}

static void espera_filhos_terminar(pid_t filhos[])
{
    pid_t filho_terminou;
    int status = 0;

    while ( (filho_terminou = wait(&status)) != -1) { 
        printf("filho PID: %d  terminou com status: %04x.\n\n", filho_terminou, status);
    }

    printf("todos os filhos terminaram, encerrando processo !!!\n");
}

static void dormir(int sleep_time)
{
    printf("processo pid[%d] esta dormindo\n", getpid());
    sleep(sleep_time);
    printf("processo morrendo de causa natural :-), pid[%d], pid do pai[%d]\n", getpid(), getppid());
}

int main (void) {
    pid_t pid_filhos[NUM_FILHOS];
    int i;
    int sou_pai = 1;
    struct sigaction tratador;

    tratador.sa_sigaction = tratador_termino_processo_filho;
    tratador.sa_flags = SA_SIGINFO;

    if (sigaction(SIGCHLD, &tratador, NULL) == -1) {
        printf("ERRO AO INSTALAR O TRATADOR DE SINAL SIGCHLD !!!");
    }

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
        espera_filhos_terminar(pid_filhos);
    }

    exit(0);
}

