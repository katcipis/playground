// EPOS-- Thread Test Program

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <utility/ostream.h>
#include <thread.h>
#include <semaphore.h>
#include <alarm.h>

__USING_SYS

const int iterations = 100;

static Semaphore *sem = 0;

static Thread *a = 0;
static Thread *b = 0;
static Thread *c = 0;

int func_a(void);
int func_b(void);
int func_c(void);
int func_a2(void);
int func_b2(void);
int func_c2(void);
int kamikaze(void);

OStream cout;

int main()
{
    int join_ret = 0;

    cout << "<<<<<<<< Testing the destruction of a Thread that someone has joined >>>>>>>\n";

    a = new Thread(&func_a);
    b = new Thread(&func_b);
    c = new Thread(&func_c);

    join_ret = c->join();
    cout << "Thread C join() returned = " << join_ret << "\n";

    join_ret = a->join();
    cout << "Thread A join() returned = " << join_ret << "\n";

    delete a;
    delete c;
 
    cout << "<<<<<<<< It seems that the join test worked !!! >>>>>>>> \n";

    cout << "\n <<<<<<<< Lets do the first semaphore test !!! >>>>>>>> \n";

    sem = new Semaphore();
    sem->p();

    a = new Thread(&func_a2);
    b = new Thread(&func_b2);
    c = new Thread(&func_c2);

    Alarm::delay(500000);

    cout << "Deleting semaphore !!! \n";
    delete sem;
    cout << "Semaphore deleted !!! \n";
    
    join_ret = a->join();
    cout << "Thread A join() returned = " << join_ret << "\n";

    join_ret = b->join();
    cout << "Thread B join() returned = " << join_ret << "\n";

    join_ret = c->join();
    cout << "Thread C join() returned = " << join_ret << "\n";

    delete a;
    delete b;
    delete c;

    cout << "<<<<<<< First semaphore test seems to works :-) !!! >>>>>>>\n";

    cout << "\n <<<<<<<< Lets do the second semaphore test !!! >>>>>>>>\n";
    sem = new Semaphore();
    sem->p();

    a = new Thread(&func_a2);
    b = new Thread(&func_b2);
    c = new Thread(&func_c2);

    Alarm::delay(500000);

    cout << "Deleting Threads !!! \n";
    delete a;
    delete b;
    delete c;
    cout << "Threads deleted !!! \n";
   
    cout << "Releasing semaphore !!! \n";
    sem->v();

    cout << "Lets get the semaphore again to see if we messed it up\n";
    sem->p();
    sem->v();
    cout << "\n <<<<<<<<< No one got locked and no seg fault, a good signal :-) >>>>>>>>> \n";

    cout << "\n <<<<<<<<< Lets run a lot of threads that delete themselves >>>>>>>>>>>> \n";

    for (int i = 0; i < 10; i++) {
        new Thread(&kamikaze);
    }

    cout << "\n<<<<<<<< Still alive...it seems like it is working :-) >>>>>>>>\n";

    cout << "<<<<< Main Thread also done, bye! >>>>>>\n";

    return 0;
}

int func_a2(void)
{
    cout << "Thread A getting semaphore !! \n";
    sem->p();
    cout << "Thread A has been unlocked from the semaphore !! \n";
    return 1;
}

int func_b2(void)
{
    cout << "Thread B getting semaphore !! \n";
    sem->p();
    cout << "Thread B has been unlocked from the semaphore !! \n";
    return 2;
}

int func_c2(void)
{
    cout << "Thread C getting semaphore !! \n";
    sem->p();
    cout << "Thread C has been unlocked from the semaphore !! \n";
    return 3;
}

int func_a(void)
{
    cout << "Starting Thread A \n";

    cout<< "Thread A joining Thread B \n";
    cout << "Thread B exited with status = " << b->join() << "\n";

    cout << "Exiting Thread A \n";
    return 1;   
}

int kamikaze(void)
{
    cout << "Starting Kamikaze Thread \n";
    Alarm::delay(500000);
    cout << "Im killing myself !!!! \n";
    delete Thread::running();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ERROR !!!!!!" 
            "THIS SHOULD NOT BE PRINTED, IM DEAD I CANT PRINT !!!!!!!" 
            ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

int func_c(void)
{
    cout << "Starting Thread C \n";

    Alarm::delay(500000);
    cout << "Deleting thread B \n";
  
    delete b;

    cout << "Exiting Thread C \n";
    return 3;
}

int func_b(void)
{
    cout << "Starting Thread B \n";

    while(true) {
        cout << "Thread B doing nothing !!! \n";
        Thread::yield();
    }

    return 2;   
}

