// EPOS-- Semaphore Abstraction Declarations

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#ifndef __semaphore_h
#define __semaphore_h

#include <common/synchronizer.h>

__BEGIN_SYS

class Semaphore: public Synchronizer_Common
{
private:
    typedef Traits<Semaphore> Traits;
    static const Type_Id TYPE = Type<Semaphore>::TYPE;

public:
    Semaphore(int v = 1) : _value(v) {
	db<Semaphore>(TRC) << "Semaphore(value= " << _value << ")\n";
    }
    ~Semaphore() {
	db<Semaphore>(TRC) << "~Semaphore()\n";
        _lock.acquire();

        /* lets wake up everyone if anyone is locked on this semaphore */
        wakeup_all();

        _lock.release();
    }

    void p() { 
        /* now we can guarantee atomicity ;) */
        _lock.acquire();
        db<Semaphore>(TRC) << "Semaphore::p(value=" << _value << ")\n";

	if(--_value < 0) {
	    sleep(); /* release is made inside the slee() */
        } else {
            _lock.release();
        }
    }
    void v() {
        /* now we guarantee atomicity ;) */
        _lock.acquire();
        db<Semaphore>(TRC) << "Semaphore::v(value=" << _value << ")\n";

	if(++_value < 1) {
            wakeup();
        }

        _lock.release();
    }

    static int init(System_Info *si);

private:
    volatile int _value;
};

__END_SYS

#endif
