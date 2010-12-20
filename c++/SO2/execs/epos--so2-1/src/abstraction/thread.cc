// EPOS-- Thread Abstraction Implementation

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <thread.h>
#include <mmu.h>
#include <machine.h>

__BEGIN_SYS

// Class attributes
Thread * volatile Thread::_running;
Thread::Queue Thread::_ready;
Thread::Queue Thread::_suspended;
Spin  Thread::_lock;

// Destructor
Thread::~Thread() {

    int_disable();

    if (_running == this) {
        /* im not sleeping and exit will resume joined threads */
        free_and_exit();  /* wont return from here, already frees stack and enable interruption */
    } 

    _ready.remove(this);
    _suspended.remove(this);

    resume_joined(-1); /* Prevent joined Threads to deadlock, -1 is the error code */

    /* If we have a sleeping Queue it means that we are sleeping */
    if (_sleeping) {
        _sleeping->remove(this);
        _sleeping = 0;
    }
    
    /* we cant return the stack top on the join method anymore */
    free(_stack);

    int_enable();
}


// Methods
int Thread::join() {
    db<Thread>(TRC) << "Thread::join(this=" << this
		    << ",state=" << _state << ")\n";

    /* Lets prevent race conditions while joining a Thread. */
    int_disable();

    if (_state == FINISHING) {
        /* Join on an already finished thread, just return the exit status code */
        int_enable();
        return _exit_status;
    }

    Thread* caller = _running;
    _joined.insert(&caller->_join_sleep_link); 
    caller->suspend_and_enable_interruption();

    /* since the callee may have been deleted we must
       keep the exit status of the callee on the caller */
    return caller->_exit_status;
}

void Thread::pass() {
    db<Thread>(TRC) << "Thread::pass(this=" << this << ")\n";

    int_disable();

    Thread * old = _running;
    old->_state = READY;
    _ready.insert(&old->_link);

    _ready.remove(this);
    _state = RUNNING;
    _running = this;

//     old->_context->save(); // can be used to force an update
    db<Thread>(INF) << "old={" << old << "," 
		    << *old->_context << "}\n";
    db<Thread>(INF) << "new={" << _running << "," 
		    << *_running->_context << "}\n";
	
    CPU::switch_context(&old->_context, _context);

    int_enable();
}

void Thread::suspend_and_enable_interruption()
{
    if(_running != this) {
        _ready.remove(this);
    }

    _state = SUSPENDED;
    _suspended.insert(&_link);

    _running = _ready.remove()->object();
    _running->_state = RUNNING;

    db<Thread>(INF) << "old={" << this << ","
                    << *_context << "}\n";
    db<Thread>(INF) << "new={" << _running << ","
                    << *_running->_context << "}\n";

    CPU::switch_context(&_context, _running->_context);

    int_enable();
}

void  Thread::suspend()
{
    db<Thread>(TRC) << "Thread::suspend(this=" << this << ")\n";
    int_disable();
    suspend_and_enable_interruption();
}	    

void Thread::resume()
{
    db<Thread>(TRC) << "Thread::resume(this=" << this << ")\n";
    int_disable();
    resume_and_enable_interruption();
}

void  Thread::resume_and_enable_interruption() {
    _suspended.remove(this);
    _state = READY;
    _ready.insert(&_link);

    int_enable();
}

void Thread::yield() {
    db<Thread>(TRC) << "Thread::yield()\n";
    int_disable();

    yield_and_enable_interruption();
}

void Thread::yield_and_enable_interruption() {

    Thread * old = _running;
    old->_state = READY;
    _ready.insert(&old->_link);

    _running = _ready.remove()->object();
    _running->_state = RUNNING;

    db<Thread>(INF) << "old={" << old << ","
                    << *old->_context << "}\n";
    db<Thread>(INF) << "new={" << _running << ","
                    << *_running->_context << "}\n";

    CPU::switch_context(&old->_context, _running->_context);

    int_enable();
}

void Thread::exit(int status)
{
    db<Thread>(TRC) << "Thread::exit(status=" << status << ")\n";

    int_disable();
    _running->resume_joined(status); // Put joined threads back to READY.

    if (_ready.size() == 1 && _suspended.empty()) {
        /* There is only the idle Thread on the ready Queue.
           And suspended is empty...so there is no thread in the system able to run.  */
        db<Thread>(WRN) << "The last thread in the system has exited!\n";
        db<Thread>(WRN) << "Halting the CPU ...\n";
        Machine::shutdown(); /* nothing to do, lets shutdown */
    }
    
    /* We can schedule another Thread to run */
    Thread * old      = _running;

    old->_state       = FINISHING;
    old->_exit_status = status;

    _running = _ready.remove()->object();
    _running->_state = RUNNING;

    db<Thread>(INF) << "old={" << old << "," 
                    << *old->_context << "}\n";
    db<Thread>(INF) << "new={" << _running << "," 
                    << *_running->_context << "}\n";

    CPU::switch_context(&old->_context, _running->_context);
    int_enable();
}

void Thread::free_and_exit()
{
    /* int_enable already called */

    _running->resume_joined(-1); // Put joined threads back to READY.

    if (_ready.size() == 1 && _suspended.empty()) {
        /* There is only the idle Thread on the ready Queue.
           And suspended is empty...so there is no thread in the system able to run.  */
        db<Thread>(WRN) << "The last thread in the system has exited!\n";
        db<Thread>(WRN) << "Halting the CPU ...\n";
        Machine::shutdown(); /* nothing to do, lets shutdown */
    }

    /* We can schedule another Thread to run */
    Thread * old      = _running;

    _running = _ready.remove()->object();
    _running->_state = RUNNING;

    db<Thread>(INF) << "old={" << old << ","
                    << *old->_context << "}\n";
    db<Thread>(INF) << "new={" << _running << ","
                    << *_running->_context << "}\n";

    CPU::switch_context(&old->_context, _running->_context);

    /* now it is safe to free the old deleted running Thread stack */
    free(old->_stack);

    int_enable();
}

void Thread::idle()
{
    /* Stays forever waiting to someone become ready to execute */
    while (true) {
        db<Thread>(TRC) << "Thread::idle\n";

        int_disable();

        if (!_ready.empty()) {
            /* we can schedule someone :-).
               yield call will schedule someone else. */
            yield_and_enable_interruption();
            /* after we return the yield we must go back to the start of the loop
               or we could make the CPU halt while there is a ready thread waiting.
               Or even thinking that all threads of the system where killed */
            continue; 
        }

        
        if (_suspended.empty()) {
            /* _ready is empty and _suspended is empty, someone killed all threads
               while the idle thread was running. This seems to be an error, lets reboot */
            db<Thread>(WRN) << "ERROR! There are no runnable threads at ALL!!!!\n";
            Machine::reboot();
        }

        int_enable();

        db<Thread>(TRC) << "There are no runnable threads at the moment!\n";
        db<Thread>(TRC) << "Halting the CPU ...\n";

        /* since there is no one to run lets halt the CPU */
        CPU::halt();
    }
}

void Thread::sleep(Queue * sleeping, Spin & lock)
{
    db<Thread>(TRC) << "Thread::sleep()\n";

    int_disable();

    db<Thread>(TRC) << "Thread::sleep(running=" << Thread::_running << ")\n";

    /* lets make the running Thread sleep (The caller) */
    Thread::_running->_sleeping = sleeping;
    Thread::_running->_sleeping->insert(&Thread::_running->_join_sleep_link);


    /* now we can guarantee the atomicity of the call to sleep 
       but releasing after the Thread lock has some case where a deadlock can happen ? 
       it seems that the two locks never crosses each other, so it works =P */
    lock.release();

    if(!Traits::busy_waiting) {
        Thread::_running->suspend_and_enable_interruption();
    } else {
        int_enable();
        Thread::_running->do_busy_waiting(); /* locks the thread on a busy waiting */
    }
}

bool Thread::wakeup(Queue & sleeping)
{
    db<Thread>(TRC) << "Thread::wakeup()\n";

    /* The caller of the wakeup method must guarantee the atomicity of the call
       but not remove the waking up Thread from the sleeping Queue */

    int_disable(); /* Avoid race conditions like deleting a Thread that is being waked up */

    Queue::Element * e = sleeping.remove();
   
    if (!e) {
        return false;
    }

    Thread * t = e->object();
    t->_sleeping = 0; /* this Thread is not sleeping anymore */

    db<Thread>(TRC) << "Thread::wakeup(waking up=" << t << ")\n";

    if(!Traits::busy_waiting) {
        t->resume_and_enable_interruption();
    } else {
        t->stop_busy_waiting();
        int_enable();
    }

    return true;
}

void Thread::do_busy_waiting()
{
    /* now we keep this thread locked on the tsl */
    while (CPU::tsl(_busy_lock)) ;
}

void Thread::stop_busy_waiting() 
{
    /* free the locked thread from busy waiting */
    _busy_lock = false;
}

void Thread::int_enable() 
{
   db<Thread>(TRC) << "entering int_enable(_running =" << _running << ") \n";

   if(Traits::smp)
       _lock.release();

   if(Traits::active_scheduler)
       CPU::int_enable();

    db<Thread>(TRC) << "exiting int_enable(_running =" << _running << ") \n";
}

void Thread::int_disable() 
{
    db<Thread>(TRC) << "entering int_disable(_running =" << _running << ") \n";

    if(Traits::active_scheduler)
        CPU::int_disable();

    if(Traits::smp)
        _lock.acquire();

    db<Thread>(TRC) << "exiting int_disable(_running =" << _running << ") \n";
}

__END_SYS
