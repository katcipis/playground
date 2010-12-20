#include<unistd.h>
#include<stdio.h>
#include<getpids.h>
 

 int main(void) { 
  pid_t euComprovado= getpid(); 
  pid_t paiComprovado = getppid(); 
  pid_t eu, pai; 
 
  int result = GetPIDs(&eu, &pai); 
  printf("\Pid Filho = %d e %d\n",eu, euComprovado);
  printf("\Pid Pai = %d e %d\n",pai, paiComprovado);  
  return 0; 
} 
