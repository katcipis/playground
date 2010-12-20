// EPOS-- Thread Test Program

// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-NoDerivs License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-nd/2.0/ or send a letter to 
// Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

#include <utility/ostream.h>
#include <cpu.h>

__USING_SYS

OStream cout;

int main()
{
    volatile int test = 0;

    cout << "test: " << test << "\n";
    cout << "ret CPU::finc: " << CPU::finc(test) << "\n";

    cout << "test: " << test << "\n";

    cout << "ret CPU::fdec: " << CPU::fdec(test) << "\n";
    cout << "test: " << test << "\n";
    return 0;
}

