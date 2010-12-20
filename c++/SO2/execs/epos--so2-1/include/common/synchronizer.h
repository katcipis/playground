// EPOS-- Synchronizer Abstractions Common Package

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#ifndef __synchronizer_h
#define __synchronizer_h

#include <system/config.h>
#include <cpu.h>
#include <thread.h>
#include <utility/spin.h>

__BEGIN_SYS

class Synchronizer_Common
{
protected:
    Synchronizer_Common() {}
    
private:
    typedef Queue<Thread> Queue;
    static const bool busy_waiting = Traits<Thread>::busy_waiting;

protected:
    // Atomic operations
    bool tsl(volatile bool & lock) { return CPU::tsl(lock); }
    int inc(volatile int & number) { return CPU::finc(number); }
    int dec(volatile int & number) { return CPU::fdec(number); }

    // Thread operations
    void sleep() {
        /* The lock must be done before calling this method and unlock must
           be called inside the Thread implementation, only when it is safe
           to do that, this way we can guarantee atomicity of the sleep() / wakeup calls */
        Thread::sleep(&_sleeping, _lock);
    }

    void wakeup() {
        /* The lock must be done before calling this method */
        wakeup_next();
        /* The unlock must be done after calling this method */
    }

    void wakeup_all() {
        /* The lock must be done before calling this method */
        while (wakeup_next()) ;
        /* The unlock must be done after calling this method */ 
    }
  
    bool is_empty() {
        return _sleeping.empty();
    }


protected: 
    Spin _lock; /* used to guarantee atomicity of the methods */


private:
    bool wakeup_next() {
        return Thread::wakeup(_sleeping);
    }


private:
    /* The sleeping Threads Queue */
    Queue _sleeping;
};

__END_SYS

#endif
