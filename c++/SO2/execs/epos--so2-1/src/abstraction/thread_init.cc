// EPOS-- Thread Abstraction Initialization

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <thread.h>
#include <alarm.h>
#include <system/kmalloc.h>

__BEGIN_SYS

int Thread::init(System_Info * si)
{
    db<Init>(TRC) << "Thread::init(entry="
		  << (void *)si->lmm.app_entry << ")\n";

    int_disable();

    if(Traits::active_scheduler)
	Alarm::master(Traits::quantum, &reschedule);

    _running = 	new(malloc(sizeof(Thread))) 
    Thread(reinterpret_cast<int (*)()>(si->lmm.app_entry), RUNNING);

    /* Before loading the main app context lets create our idle Thread on ready state. */
    new(malloc(sizeof(Thread)))
    Thread(reinterpret_cast<int (*)()>(&idle), READY, LOW);

    int_enable();

    /* now lets load the context of the main app */
    _running->_context->load();

    return 0;
}

__END_SYS
