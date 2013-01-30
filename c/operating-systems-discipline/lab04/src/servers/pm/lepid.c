#include "pm.h"
#include <minix/callnr.h>
#include <minix/endpoint.h>
#include <signal.h>
#include "mproc.h"
#include "param.h"

/*=============*
 * do_getpids  *
 *=============*/

PUBLIC int do_getpids()
{
    register struct mproc *rmp = mp;
    int proc;
/*    
THERE IS NO endpt on m_in in Minix 3.1.6
if (pm_isokendpt(m_in.endpt, &proc) == OK && proc >= 0) { */
        rmp->mp_reply.reply_res3 = mproc[who_p].mp_pid;
        rmp->mp_reply.reply_res2 = mproc[rmp->mp_parent].mp_pid;
        return 0;
/*    }
 
    return 1; */
}

