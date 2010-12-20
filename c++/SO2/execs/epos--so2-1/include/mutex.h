// EPOS-- Mutex Abstraction Declarations

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#ifndef __mutex_h
#define __mutex_h

#include <common/synchronizer.h>

__BEGIN_SYS

class Mutex: public Synchronizer_Common
{
private:
    typedef Traits<Mutex> Traits;
    static const Type_Id TYPE = Type<Mutex>::TYPE;

public:
    Mutex() : _locked(false) { db<Mutex>(TRC) << "Mutex()\n"; }
    ~Mutex() { db<Mutex>(TRC) << "~Mutex()\n"; }

    void lock() { 
	db<Mutex>(TRC) << "Mutex::lock()\n";
        _lock.acquire();
        
	if(_locked) {
	    sleep(); /* release is made inside the sleep before making the Thread sleep */

            /* now that it has been wakedup it must try to get the lock again.
               because we have a race between a waked up Thread and other thread that might be
               trying to acquire the lock too. The fastest one wins :-) */
            lock(); 
        } else {
            _locked = true;
            _lock.release();
        }

    }
    void unlock() { 
	db<Mutex>(TRC) << "Mutex::unlock()\n";
        _lock.acquire();

	_locked = false;
        /* There will always be an extra wakeup here (wakeups no one), 
           we must protect it on the wakeup method implementation */
	wakeup();

        _lock.release();
    }

    static int init(System_Info *si);

private:
    volatile bool _locked;
};

__END_SYS

#endif
