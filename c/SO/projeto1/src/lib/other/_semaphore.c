#include<lib.h>
#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>

#define semaphore _semaphore

PUBLIC int SemDown(int numSem)
{
    message m;

    if (numSem >= MAX_SEMAPHORES || numSem < 0) {
        printf("SemDown: ERROR, INVALID SEMAPHORE NUMBER[%d]!!!!\n", numSem);
        return -1;
    }    

    printf("SemDown: semaphore[%d]\n", numSem);
    m.m1_i1 = numSem;
    _syscall(MM, SEMDOWN, &m);
    return 0;
}

PUBLIC int SemUp(int numSem)
{
    message m;

    if (numSem >= MAX_SEMAPHORES || numSem < 0) {
        printf("SemUp: ERROR, INVALID SEMAPHORE NUMBER[%d]!!!!\n", numSem);
        return -1;
    }

    printf("SemUp: semaphore[%d]\n", numSem);
    m.m1_i1 = numSem;
    _syscall(MM, SEMUP, &m);
    return 0;
}

PUBLIC int SemInit(int numSem, int valor)
{
    message m;

    if (numSem >= MAX_SEMAPHORES || numSem < 0 || valor < 0) {
        printf("SemInit: ERROR, INVALID SEMAPHORE [%d] OR VALUE [%d] !!!!\n", numSem, valor);
        return -1;
    }

    printf("SemInit: semaphore number[%d] starting with value[%d] \n", numSem, valor);
    m.m1_i1 = numSem;
    m.m1_i2 = valor;
    _syscall(MM, SEMINIT, &m);

    return 0;
}

PUBLIC int SemStatus(int numSem, int* valor, int* numBloq)
{
    message m;

    if (numSem >= MAX_SEMAPHORES || numSem < 0) {
        printf("SemStatus: ERROR, INVALID SEMAPHORE NUMBER[%d]!!!!\n", numSem);
        return -1;
    }

    if (!valor || !numBloq) {
        printf("SemStatus: NULL PARAMETER GIVEN, valor[%p] numBloq[%p]!!!\n", valor, numBloq);
        return -1;
    }

    printf("SemStatus: semaphore[%d]\n", numSem);
    m.m1_i1 = numSem;

    _syscall(MM, SEMSTATUS, &m);
   
    *valor   = m.m2_i1; 
    *numBloq = m.m2_i2;
    printf("SemStatus: syscall returned valor[%d], numBloq[%d]\n", *valor, *numBloq);
    return 0;
}

