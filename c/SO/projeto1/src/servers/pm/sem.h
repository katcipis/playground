#ifndef SEM_H
#define SEM_H

#include <semaphore.h>

struct semaphore {
    int val;
    struct mproc *block_head;
    struct mproc *block_tail;
} semaphores[MAX_SEMAPHORES];

#endif /* SEM_H */
