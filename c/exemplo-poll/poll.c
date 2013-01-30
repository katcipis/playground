#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/poll.h>

int main(int argc, char *argv[])
{
  int rsp;
  struct pollfd stpoll;

  stpoll.fd = 0;
  stpoll.events = POLLIN | POLLPRI;

  while( ( rsp = poll(&stpoll, 1, 8000) ) >= 0)
  {
     switch(rsp)
     {
        case -1:
           printf("erro no poll\n");
        break;
        case 0:
        {
           printf("timeout do poll\n");
        }  break;
        default: // tem dados disponiveis
        {
           int rx;
           char buffer[0x100];
           rx = read(0, buffer, 0xff);
           printf("li %d bytes da entrada padrao\n", rx);
        }
     }
  }

  return 0;
} 
