#include<lib.h>
#include<unistd.h>
#include<stdio.h>

#define getpids _getpids

PUBLIC int GetPIDs(pid_t *eu, pid_t *pai)
{
    message m;
    *eu  = 0;
    *pai = 0;

    printf("GetPIDs: realizando chamada de sistema !!! \n");
    _syscall(MM, GETPIDS, &m);
    printf("GetPIDs: retornou da chamada de sistema !!! \n");

    *eu = m.m2_i2;
    *pai= m.m2_i1;

    printf("GetPIDs: Pid Filho = %d \n",*eu);
    printf("GetPIDs: Pid Pai = %d \n", *pai);

    return 0;
}

