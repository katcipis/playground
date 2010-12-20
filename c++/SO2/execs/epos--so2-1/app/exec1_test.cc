// EPOS-- Thread Test Program

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <utility/ostream.h>
#include <thread.h>

__USING_SYS

const int iterations = 100;

int func_a(void);
int func_b(void);
int func_c(void);

OStream cout;

int main()
{
    Thread *a = 0;
    Thread *b = 0;
    Thread *c = 0;

    int status_a = 0;
    int status_b = 0;
    int status_c = 0;

    cout << "Exec 1 test\n";

    a = new Thread(&func_a, Thread::SUSPENDED);
    b = new Thread(&func_b, Thread::SUSPENDED);
    c = new Thread(&func_c, Thread::SUSPENDED);

    cout << "All threads are now created on suspended mode. Now we resume them up so they can exit ...\n";

    a->resume();
    b->resume();
    c->resume();

    status_a = a->join();
    status_b = b->join();
    status_c = c->join();

    cout << "Thread A exited with status " << status_a << "\n"
	 << "Thread B exited with status " << status_b << "\n"
         << "Thread C exited with status " << status_c << "\n";

    delete a;
    delete b;
    delete c;
    
    cout << "Main Thread also done, bye!\n";

    return 0;
}

int func_a(void)
{
    cout << "Starting Thread A \n";

    for(int i = iterations; i > 0; i--) {
	for(int i = 0; i < 79; i++)
	    cout << "a";
	cout << "\n";
	Thread::yield();
    }

    cout << "Exiting Thread A \n";
    return 1;   
}

int func_b(void)
{
    cout << "Starting Thread B \n";

    for(int i = iterations; i > 0; i--) {
	for(int i = 0; i < 79; i++)
	    cout << "b";
	cout << "\n";
	Thread::yield();
    }

    cout << "Exiting Thread B \n";
    return 2;   
}

int func_c(void)
{
    /* Lets test what happens if we join an already exited thread */
    cout << "Starting Thread C \n";
    Thread::yield();
    cout << "Exiting Thread C \n";
    return 2;
}
