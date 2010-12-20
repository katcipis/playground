#include "pm.h"
#include <minix/callnr.h>
#include <minix/endpoint.h>
#include <signal.h>
#include "mproc.h"
#include "param.h"
#include <stdio.h>
#include "sem.h"

/*==============*
 * get_num_bloq *
 *==============*/
PRIVATE int get_num_bloq(struct semaphore* sem)
{
    int res = 0;
    register struct mproc * current = sem->block_head;
    while (current) {
        res++;
        current = current->next_blocked;
    }
    return res;
}

/*=================*
  push_on_semaphore
 *=================*/
PRIVATE void push_on_semaphore(struct semaphore *sem, struct mproc *proc)
{
    proc->next_blocked = 0;

    if (sem->block_tail) {
        sem->block_tail->next_blocked = proc;
        sem->block_tail = proc;
        return;
    }

    sem->block_head = proc;
    sem->block_tail = proc;
}

/*==================*
  pop_from_semaphore
 *==================*/
PRIVATE struct mproc * pop_from_semaphore(struct semaphore *sem)
{
    struct mproc *ret = 0;

    if (!sem->block_head) {
        return 0;
    }

    ret = sem->block_head;

    if(!ret->next_blocked) {
        sem->block_head = 0;
        sem->block_tail = 0;
        return ret;
    }

    sem->block_head = ret->next_blocked;
    ret->next_blocked = 0;
    return ret;
}

/*=============*
 * print_sem   *
 *=============*/
PRIVATE void print_sem(struct semaphore* sem, int number)
{
    printf("PM: semaphore[%d] with value[%d] and [%d] bloqued processes\n", number, sem->val, get_num_bloq(sem));
}

/*=============*
 * do_semdown  *
 *=============*/

PUBLIC int do_semdown()
{
    struct semaphore* sem = &semaphores[m_in.m1_i1];
    register struct mproc *rmp = mp;
    printf("PM: do_semdown called with semaphore number[%d]!!!\n", m_in.m1_i1);

    print_sem(sem, m_in.m1_i1);

    if (sem->val == 0) {
        printf("PM: blocking process name[%s] pid[%d]\n", rmp->mp_name, rmp->mp_pid);
        push_on_semaphore(sem, rmp);
        return (SUSPEND); 
    }

    --sem->val;
    return (OK);
}

/*=============*
 * do_semup    *
 *=============*/

PUBLIC int do_semup()
{
    struct semaphore *sem = &semaphores[m_in.m1_i1];
    register struct mproc *rmp = mp;
    
    printf("PM: do_semup called semaphore[%d]!!!\n", m_in.m1_i1);
    print_sem(sem, m_in.m1_i1);


    if (sem->val == 0) {
        register struct mproc *unblock = pop_from_semaphore(sem);

        if (!unblock) {
            ++sem->val;
            return (OK);
        }

        printf("PM: unblocking process name[%s] pid[%d]\n", unblock->mp_name, unblock->mp_pid);
        unblock->mp_reply.reply_res = (OK);
        unblock->mp_flags |= REPLY;         /* reply blocked process with OK */
        return (OK);
    }
    
    ++sem->val;
    return (OK);
}

/*=============*
 * do_seminit  *
 *=============*/

PUBLIC int do_seminit()
{
    struct semaphore* sem = &semaphores[m_in.m1_i1];
    printf("PM: do_seminit called semaphore[%d] and value[%d]!!!\n", m_in.m1_i1, m_in.m1_i2);
    print_sem(sem, m_in.m1_i1);

    if (sem->val != 0 && sem->block_head != 0) {
        printf("PM: ERROR, TRYING TO INITIALIZE A SEMAPHORE ALREADY IN USE !!!\n");
        return (EINVAL);
    }
    
    sem->val = m_in.m1_i2;
    return (OK);
}

/*==============*
 * do_semstatus *
 *==============*/

PUBLIC int do_semstatus()
{
    register struct mproc *rmp = mp;
    struct semaphore* sem = &semaphores[m_in.m1_i1]; 
    int proc;

    printf("PM: do_semstatus called semaphore[%d]!!!\n", m_in.m1_i1);
    print_sem(sem, m_in.m1_i1);

    rmp->mp_reply.reply_res2 = sem->val;
    rmp->mp_reply.reply_res3 = get_num_bloq(sem);
    printf("PM: do_semstatus: value[%d], numbloq[%d]\n", rmp->mp_reply.reply_res2, rmp->mp_reply.reply_res3);

    if (pm_isokendpt(rmp->mp_endpoint, &proc) == OK) {
        printf("PM: do_semstatus: reply OK proc[%d]\n", proc); 
        return (OK);
    }

    printf("PM: do_semstatus: ERROR SENDING RESPONSE TO CALLER, PROC[%d] M_IN ENDPOINT[%d]!!!\n", proc, m_in.endpt);
    printf("PM: do_semstatus: rmp name[%s], pid[%d], endpoint[%d]\n", rmp->mp_name, rmp->mp_pid, rmp->mp_endpoint);
    return (OK);
}


