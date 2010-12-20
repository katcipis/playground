// EPOS-- Alarm Abstraction Implementation

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <alarm.h>
#include <display.h>

__BEGIN_SYS

// Class attributes
Timer Alarm::_timer;
volatile Alarm::Tick Alarm::_elapsed;
Alarm::Handler Alarm::_master;
Alarm::Tick Alarm::_master_ticks;
Alarm::Queue Alarm::_requests;
Spin Alarm::_lock;

// Methods
Alarm::Alarm(const Microseconds & time, const Handler & handler, int times)
    : _ticks((time + period() / 2) / period()), _handler(new Thread(&run_handler, handler, Thread::SUSPENDED)),
      _handler_func(handler), _times(times), _link(this, _ticks)
{
    lock();

    db<Alarm>(TRC) << "Alarm(t=" << time << ",h=" << (void *)handler
		   << ",x=" << times << ")\n";
    if(_ticks) {
	_requests.insert(&_link);
    } else {
        db<Alarm>(TRC) << "Executing handler on the Alarm constructor !!!\n";
	_handler->resume();
    }

    unlock();
}

Alarm::Alarm(const Microseconds & time, Thread * handler) 
    : _ticks((time + period() / 2) / period()), _handler(handler),
       _handler_func(0), _times(1), _link(this, _ticks)
{
    db<Alarm>(TRC) << "Private Alarm(t=" << time << ",h=" << handler << "\n";
    if(_ticks) {
        lock();
        _requests.insert(&_link);
        unlock();
        handler->suspend();
    } 
}

Alarm::~Alarm() {
    lock();

    db<Alarm>(TRC) << "~Alarm()\n";
    _requests.remove(this);

    unlock();
}

int Alarm::run_handler(Handler handler)
{
    handler();
    /* now that the handler has run it is safe to destroy this Thread.
       we fixed the Thread destructor so we can do this without leaking memory. */
    delete Thread::running();

    return 1; /* never gonna reach it */
}

void Alarm::master(const Microseconds & time, const Handler & handler)
{
    db<Alarm>(TRC) << "master(t=" << time << ",h="
		   << (void *)handler << ")\n";

    _master = handler;
    _master_ticks = (time + period() / 2) / period();
}

void Alarm::delay(const Microseconds & time)
{
    db<Alarm>(TRC) << "delay(t=" << time << ")\n";
    Alarm * alarm  = new Alarm(time, Thread::running()); 
    db<Alarm>(TRC) << "Releasing thread " << Thread::running() << "\n";
    delete alarm;
}

void Alarm::unlock()
{
   if(smp)
       _lock.release();

   if(active_scheduler)
       CPU::int_enable();
}

void Alarm::lock()
{
    if(active_scheduler)
        CPU::int_disable();

    if(smp)
        _lock.acquire();
}

void Alarm::timer_handler(void)
{
    static Tick next;
    static Thread * handler;

    db<Alarm>(TRC) << "Alarm::timer_handler init\n";
 
    lock();

    _elapsed++;
    
    if(Traits::visible) {
        db<Alarm>(TRC) << "timer handler elapsed: " << _elapsed << "\n";
    }

    if(_master_ticks) {
	if(!(_elapsed % _master_ticks)) {
	    new Thread(&run_handler, _master, Thread::READY);
        }
    }

    if(next) {
	next--;
    }

    if(!next) {
	if(handler) {
            db<Alarm>(TRC) << "Alarm::timer_handler: Executing handler!!!\n";
	    handler->resume();
        }
	if(_requests.empty()) {
	    handler = 0;
            db<Alarm>(TRC) << "Alarm::timer_handler: _requests is empty !!!\n";
	} else {
	    Queue::Element * e = _requests.remove();
	    Alarm * alarm = e->object();

	    next = alarm->_ticks;
	    handler = alarm->_handler;

            db<Alarm>(TRC) << "Alarm::timer_handler: " << alarm << ": alarm->_times: " << alarm->_times << "\n";
	    if(alarm->_times != -1) {
		alarm->_times--;
            }
	    if(alarm->_times) {
	        e->rank(alarm->_ticks);
	        _requests.insert(e);
                /* we must create another thread since this alarm will be triggered again */
                alarm->_handler = new Thread(&run_handler, alarm->_handler_func, Thread::SUSPENDED);
                db<Alarm>(TRC) << "Alarm::timer_handler: set a new _handler\n";
	    }
	}
    }

    unlock();

    db<Alarm>(TRC) << "Alarm::timer_handler exit\n";
}

__END_SYS
