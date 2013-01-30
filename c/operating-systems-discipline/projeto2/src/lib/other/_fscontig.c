#include<lib.h>
#include<unistd.h>
#include<stdio.h>
#include<fscontig.h>

PUBLIC int fscontig(int fd)
{
  message m;
  int r;
  m.m1_i1 = fd;
  printf("file descriptor in fscontig %d\n", fd);
  return (_syscall(FS_PROC_NR, FSCONTIG, &m)) / 100;
}

