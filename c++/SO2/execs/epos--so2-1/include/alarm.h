// EPOS-- Alarm Abstraction Declarations

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#ifndef __alarm_h
#define __alarm_h

#include <system/config.h>
#include <utility/queue.h>
#include <utility/spin.h>
#include <tsc.h>
#include <rtc.h>
#include <timer.h>
#include <thread.h>

__BEGIN_SYS

class Alarm
{
private:
    static const bool smp              = Traits<Thread>::smp;
    static const bool active_scheduler = Traits<Thread>::active_scheduler;
    typedef Traits<Alarm> Traits;
    static const Type_Id TYPE = Type<Alarm>::TYPE;

    static const int FREQUENCY = __SYS(Traits)<Timer>::FREQUENCY;

    typedef TSC::Hertz Hertz;
    typedef TSC::Time_Stamp Time_Stamp;
    typedef RTC::Microseconds Microseconds;
    typedef RTC::Seconds Seconds;
    typedef Timer::Tick Tick;

    /* There was a bug here and in the constructor, the insertion on the Queue
       was ranked only when the Timer was reinserted on the Queue on the timer_handler.
       But on the first insertion on the constructor they where being pushed on FIFO.
       So a longer timer like 500000 would prevent a previous timer of 25000 to be run. */
    typedef Relative_Queue<Alarm, Tick> Queue;

public:
    // An alarm handler
    typedef void (* Handler)();

    // Infinite times (for alarms)
    enum { INFINITE = 0 };

public:
    Alarm(const Microseconds & time, const Handler & handler, int times = 1);
    ~Alarm();
    static void master(const Microseconds & time, const Handler & handler);

    static Hertz frequency() {	return _timer.frequency(); }

    static void delay(const Microseconds & time);

    static int init(System_Info *si);

private:
    Alarm(const Microseconds & time, Thread * handler); /* used to implement delay */
    static Microseconds period() { return 1000000 / frequency(); }
    static void timer_handler(void);
    static void lock();
    static void unlock();
    static int run_handler(Handler handler);

private:
    Tick _ticks;
    Thread * _handler;
    Handler _handler_func;
    int _times;
    Queue::Element _link;

    static Timer _timer;
    static volatile Tick _elapsed;
    static Handler _master;
    static Tick _master_ticks;
    static Queue _requests;
    static Spin _lock;
};

__END_SYS

#endif
