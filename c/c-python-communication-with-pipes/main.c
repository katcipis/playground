#include <stdio.h>
#include <stdlib.h>
#include <sys/poll.h>

#define MAX_BYTES 102400000

int main (int argc, char* args[])
{
  char* buffer = NULL;
  FILE* arquivo = fopen("copiado", "wb");
  struct pollfd stpoll;
  int tamanho_arquivo;
  int lidos = 0;
  int i;

  tamanho_arquivo = atoi(args[1]);
  stpoll.fd = 0;                    //0 = File descriptor do STDIN.
  stpoll.events = POLLIN | POLLPRI; //Setar para capturar eventos de entrada e de entrada urgente de dados.
  buffer = malloc(tamanho_arquivo);
 
  while(lidos < tamanho_arquivo)
  {
      int rsp = poll(&stpoll, 1, 1000);//Fazer polling com timeout de 1 segundo
      if(rsp == 1)
          lidos = lidos + read(0, buffer + lidos, tamanho_arquivo - lidos); // Lendo do file descriptor 0 (STDIN).
    
  }
  
  for(i = 0; i < tamanho_arquivo; i++){
      fprintf(arquivo, "%c", buffer[i]);
  }
  fclose(arquivo);
  return 0;
}
