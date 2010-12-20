// EPOS-- Thread Abstraction Declarations

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#ifndef __thread_h
#define __thread_h

#include <system/config.h>
#include <utility/queue.h>
#include <utility/malloc.h>
#include <utility/spin.h>
#include <cpu.h>
#include <mmu.h>

__BEGIN_SYS

class Thread
{
private:
    typedef Traits<Thread> Traits;
    static const Type_Id TYPE = Type<Thread>::TYPE;

    typedef Queue<Thread> Queue;

    static const unsigned int STACK_SIZE = 
	__SYS(Traits)<Machine>::APPLICATION_STACK_SIZE;

    typedef CPU::Log_Addr Log_Addr;
    typedef CPU::Context Context;

public:
    enum Self {SELF};

    typedef short State;
    enum  {
        RUNNING,
        READY,
        SUSPENDED,
	FINISHING
    };

    typedef short Priority;
    enum {
	HIGH = 0,
	NORMAL = 15,
	LOW = 31
    };

public:
    // The int left on the stack between thread's arguments and its context
    // is due to the fact that the thread's function believes it's a normal
    // function that will be invoked with a call, which pushes the return
    // address on the stack
    Thread(int (* entry)(), 
	   const State & state = READY,
	   const Priority & priority = NORMAL,
	   unsigned int stack_size = STACK_SIZE)
	: _stack(malloc(stack_size)), 
	  _context(new (_stack + stack_size
			- sizeof(int) - sizeof(Context))
		   Context(entry)),
	  _state(state),
	  _priority(priority),
	  _link(this),
          _join_sleep_link(this),
          _busy_lock(true),
          _sleeping(0)
    {
	header(entry, stack_size);
	Log_Addr sp = _stack + stack_size;
	sp -= sizeof(int); *static_cast<unsigned int *>(sp) = 
			       reinterpret_cast<unsigned int>(&exit);
	body();
    }
    template<class T1>
    Thread(int (* entry)(T1 a1), T1 a1,
	   const State & state = READY,
	   const Priority & priority = NORMAL,
	   unsigned int stack_size = STACK_SIZE)
	: _stack(malloc(stack_size)), 
	  _context(new (_stack + stack_size - sizeof(T1)
			- sizeof(int) - sizeof(Context))
		   Context(entry)),
	  _state(state),
	  _priority(priority),
	  _link(this),
          _join_sleep_link(this),
          _busy_lock(true),
          _sleeping(0)
    {
	header(entry, stack_size);
	Log_Addr sp = _stack + stack_size;
	sp -= sizeof(T1); *static_cast<T1 *>(sp) = a1;
	sp -= sizeof(int); *static_cast<unsigned int *>(sp) = 
			       reinterpret_cast<unsigned int>(&exit);
	body();
    }
    template<class T1, class T2>
    Thread(int (* entry)(T1 a1, T2 a2), T1 a1, T2 a2,
	   const State & state = READY,
	   const Priority & priority = NORMAL,
	   unsigned int stack_size = STACK_SIZE)
	: _stack(malloc(stack_size)), 
	  _context(new (_stack + stack_size - sizeof(T2) - sizeof(T1)
			- sizeof(int) - sizeof(Context))
		   Context(entry)),
	  _state(state),
	  _priority(priority),
	  _link(this),
          _join_sleep_link(this),
          _busy_lock(true),
          _sleeping(0)
    {
	header(entry, stack_size);
	Log_Addr sp = _stack + stack_size;
	sp -= sizeof(T2); *static_cast<T2 *>(sp) = a2;
	sp -= sizeof(T1); *static_cast<T1 *>(sp) = a1;
	sp -= sizeof(int); *static_cast<unsigned int *>(sp) = 
			       reinterpret_cast<unsigned int>(&exit);
	body();
    }
    template<class T1, class T2, class T3>
    Thread(int (* entry)(T1 a1, T2 a2, T3 a3), T1 a1, T2 a2, T3 a3,
	   const State & state = READY,
	   const Priority & priority = NORMAL,
	   unsigned int stack_size = STACK_SIZE)
	: _stack(malloc(stack_size)), 
	  _context(new (_stack + stack_size - sizeof(T3) - sizeof(T2) 
			- sizeof(T1) - sizeof(int) - sizeof(Context))
		   Context(entry)),
	  _state(state),
	  _priority(priority),
	  _link(this),
          _join_sleep_link(this),
          _busy_lock(true),
          _sleeping(0)
    {
	header(entry, stack_size);
	Log_Addr sp = _stack + stack_size;
	sp -= sizeof(T3); *static_cast<T3 *>(sp) = a3;
	sp -= sizeof(T2); *static_cast<T2 *>(sp) = a2;
	sp -= sizeof(T1); *static_cast<T1 *>(sp) = a1;
	sp -= sizeof(int); *static_cast<unsigned int *>(sp) = 
			       reinterpret_cast<unsigned int>(&implicit_exit);
	body();
    }

    ~Thread(); 

    /** 
      Make the running Thread sleep, inserting it on the given sleeping Queue.
      All handling on the sleeping Queue must be done inside the Thread implementation.
      This way we can guarantee thread safety on multiple cores.
      The sleeping Thread will keep a pointer to this Queue in case it is destroyed while sleeping.
      @param sleeping - The Queue where it will be inserted.
      @param lock     - The external lock (it will be unlocked after we acquire the Thread lock).
    */
    static void sleep(Queue * sleeping, Spin & lock);

    /** 
      Wakeup a Thread removing it from the sleeping Queue.
      All handling on the sleeping Queue must be done inside the Thread implementation.
      This way we can guarantee thread safety on multiple cores.
      @param sleeping - The Queue where the Thread will be removed and waked.
      @return true if there was a Thread to be waked up on the Queue, false otherwise.
    */
    static bool wakeup(Queue & sleeping);

    volatile const State & state() const { return _state; }
    volatile const Priority & priority() const { return _priority; }
    void priority(const Priority & priority);

    int join();
    void pass();
    void suspend();
    void resume();

    static void yield();
    static void exit(int status = 0);

    static Thread * volatile  & running() { return _running; }
    static void running(Thread * r) { _running = r; }

    static int init(System_Info * si);

private:
    void header(Log_Addr entry, unsigned int stack_size) {
	db<Thread>(TRC) << "Thread(this=" << this 
			<< ",entry=" << (void *)entry 
			<< ",state=" << _state
			<< ",priority=" << _priority
			<< ",stack={b=" << _stack
			<< ",s=" << stack_size
			<< ",context={b=" << _context
			<< "," << *_context << "})\n";
    }

    /* busy waiting methods */
    void do_busy_waiting(); 

    void stop_busy_waiting();

    void resume_joined(int status) {
        while(!_joined.empty()) {
            Thread * p = _joined.remove()->object();
            p->_exit_status = status; /* lets hold the exit status of the callee on the caller of join()*/
            p->resume();
        }
    }

    static void int_disable();
    static void int_enable();
    static void free_and_exit(); /* Exit and free the stack of the caller Thread */

    void suspend_and_enable_interruption(); /* Considers interruption is disabled */
    void resume_and_enable_interruption();  /* Considers interruption is disabled */
    static void yield_and_enable_interruption();   /* Considers interruption is disabled */

    void body() {
        int_disable();

	switch(_state) {
	case RUNNING: break;
	case SUSPENDED: _suspended.insert(&_link); break;
	default: _ready.insert(&_link);
	}

        int_enable();
    }

    static void implicit_exit() { exit(CPU::fr()); }
    static void reschedule() { yield(); }
    static void idle();

private:
    Log_Addr _stack;
    Context * volatile _context;
    volatile State _state;
    volatile Priority _priority;
    Queue::Element _link;            /* Used for suspended or ready Queues */
    Queue::Element _join_sleep_link; /* Used for the _joined and sleeping Queues */

    volatile bool _busy_lock;    /* used on Synchronizer_Common when 
                                   configured as busy_waiting 
                                   see do_busy_waiting and
                                   stop_busy_waiting methods. */
    Queue _joined;
    Queue * volatile _sleeping; /* A pointer to the Queue where the Thread is being held as sleeping */
    volatile int _exit_status;  

    static Thread * volatile _running;
    static Queue _ready;
    static Queue _suspended;
    static Spin  _lock;
};

__END_SYS

#endif
