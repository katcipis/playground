#include<lib.h>
#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>

#define TAMBUFFER 500

static void produtor(FILE* fBuffer) {
    while (1) {
        printf("Processo [%d] vai tentar produzir caracter\n", getpid());
        SemDown(2); /* decrementa sem�foro de posi��es livres */ 
        SemDown(1); /* decrementa mutex */
        printf("Processo [%d] produzindo caracter\n", getpid());
        if (fBuffer) {
            putc('c',fBuffer);
        } else {
            printf("ERROR, FILE IS NOT VALID!!!\n");
        }
        printf("Processo [%d] produziu caracter\n", getpid());
        SemUp(1); /* libera mutex */
        SemUp(3); /* incrementa sem�foro de posi��es ocupadas */
        sleep(rand()%10);
    }
}

static void consumidor(FILE* fBuffer) {
    while(1){
        printf("Processo [%d] vai tentar consumir caracter\n", getpid());
        SemDown(3); /* decrementa sem�foro de posi��es ocupadas */ 
        SemDown(1); /* decrementa mutex */
        printf("Processo [%d] consumindo caracter\n", getpid());
        if(fBuffer) {
            getc(fBuffer);
        } else {
            printf("ERROR, FILE IS NOT VALID!!!\n");
        }
        printf("Processo [%d] consumiu caracter\n", getpid());
        SemUp(1); /* libera mutex */
        SemUp(2); /* incrementa sem�foro de posi��es livres */
        sleep(rand()%10);
    }
}

int main(int argc, char *argv[])
{
    FILE* writeBuffer = fopen ("buffer", "w");
    FILE* readBuffer  = fopen ("buffer","r");
    int i; 

    if(argc < 3) {
        printf("Usage: %s [num_prod] [num_consum]\n", argv[0]);
        return 0;
    }   

    if (!writeBuffer || !readBuffer) {
        printf("Error opening file !!!!\n");
        printf("WRITE[%p], READ[%p]\n", writeBuffer, readBuffer);
        return 0;
    }

    SemInit(1,1);         /* sem�foro mutex - controla quem tem acesso ao buffer */
    SemInit(2,TAMBUFFER); /* sem�foro que controla as posi��es livres */
    SemInit(3,0);         /* sem�foro que controla as posi��es ocupadas */

    for(i=0; i<atoi(argv[1]); i++) {
        printf("Creating producer [%d]\n", i);
        if(fork() > 0)
            produtor(writeBuffer);
    }

    for(i=0; i<atoi(argv[2]); i++) {
        printf("Creating consumer [%d]\n", i);
        if(fork() > 0)
            consumidor(readBuffer);
    }
    
    return 0;
}
