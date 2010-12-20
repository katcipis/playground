#include <utility/ostream.h>
#include <alarm.h>
#include <thread.h>

__USING_SYS

OStream cout;

static int a_count = 0;
static int b_count = 0;
static int end = 0;

void handler_a()
{
    a_count++;
    cout << "Handler A is running for the [" << a_count << "] time!!! \n";
}

void handler_b()
{
    b_count++;
    cout << "Handler B is running for the [" << b_count << "] time!!! \n";
}

int main()
{
    Alarm * a = new Alarm(500000, handler_a, 10);
    Alarm * b = new Alarm(250000, handler_b, 20);

    cout << "<<<<<<<<<< Lets delay the main Thread >>>>>>>>>>\n";
    Alarm::delay(50000000);
    cout << "<<<<<<<<<< Main thread exiting !!!! >>>>>>>>>>>\n";
    return 0;
}
