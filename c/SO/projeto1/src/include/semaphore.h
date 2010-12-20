#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#define MAX_SEMAPHORES 10

_PROTOTYPE( int SemDown,(int numSem));
_PROTOTYPE( int SemUp,(int numSem));
_PROTOTYPE( int SemInit,(int numSem, int valor));
_PROTOTYPE( int SemStatus,(int numSem, int* valor, int* numBloq));

#endif /* SEM_H */

