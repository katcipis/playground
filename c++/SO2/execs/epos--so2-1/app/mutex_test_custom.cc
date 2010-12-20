// EPOS-- Mutex Test Program

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <utility/ostream.h>
#include <thread.h>
#include <mutex.h>
#include <alarm.h>
#include <display.h>

__USING_SYS

const int iterations = 10;

/* Lets create a semaphore to print things, to avoid race 
   conditions when printing information and configuring the display */
Mutex mutex_display;

Thread * phil[5];
Mutex * chopstick[5];

OStream cout;

int philosopher(int n, int l, int c)
{
    Display display;

    int first = (n < 4)? n : 0;
    int second = (n < 4)? n + 1 : 4;

    for(int i = iterations; i > 0; i--) {

	mutex_display.lock();
        display.position(l, c);
 	cout << "thinking";
	mutex_display.unlock();

 	Alarm::delay(500000);

	chopstick[first]->lock();   // get first chopstick
        chopstick[second]->lock();   // get second chopstick

	mutex_display.lock();
        display.position(l, c);
	cout << " eating ";
	mutex_display.unlock();
  
  	Alarm::delay(1000000);
  	chopstick[first]->unlock();   // release first chopstick
 	chopstick[second]->unlock();   // release second chopstick
    }
 
    mutex_display.lock();
    display.position(l, c);
    cout << " is done ";
    mutex_display.unlock();
 
    return(iterations);
}

 
int main()
{
    mutex_display.lock();

    Display display;
    display.clear();

    cout << "The mutex custom Philosopher's Dinner:\n";
	
    for(int i = 0; i < 5; i++) {
	chopstick[i] = new Mutex;
    }

    phil[0] = new Thread(&philosopher, 0,  5, 32);
    phil[1] = new Thread(&philosopher, 1, 10, 44);
    phil[2] = new Thread(&philosopher, 2, 16, 39);
    phil[3] = new Thread(&philosopher, 3, 16, 24);
    phil[4] = new Thread(&philosopher, 4, 10, 20);

    cout << "Philosophers are alife and hungry!\n";

    cout << "The dinner is served!\n";
    display.position(7, 44);
    cout << '/';
    display.position(13, 44);
    cout << '\\';
    display.position(16, 35);
    cout << '|';
    display.position(13, 27);
    cout << '/';
    display.position(7, 27);
    cout << '\\';
	

    mutex_display.unlock();


    for(int i = 0; i < 5; i++) {
	int ret = phil[i]->join();
	mutex_display.lock();
        display.position(20 + i, 0);
	cout << "Philosopher " << i << " ate " << ret << " times \n";
	mutex_display.unlock();
    }

    for(int i = 0; i < 5; i++) {
	delete chopstick[i];
    }

    for(int i = 0; i < 5; i++) {
	delete phil[i];
    }

    cout << "The end!\n";
    return 0;
}

