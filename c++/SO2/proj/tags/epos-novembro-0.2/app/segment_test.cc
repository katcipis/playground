// EPOS Segment Test Program

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#include <utility/ostream.h>
#include <address_space.h>
#include <secure/secure_segment.h>

__USING_SYS

const unsigned ES1_SIZE = 10000;
const unsigned ES2_SIZE = 100000;

int main()
{
    OStream cout;

    cout << "Segment Page fault test\n";

    cout << "My address space's page directory is located at "
	 << reinterpret_cast<void *>(CPU::pdp()) << "\n";
    Address_Space self(Address_Space::SELF);

    cout << "Creating two extra data segments:\n";
    Segment * es1 = new Segment(ES1_SIZE, static_cast<Segment::Flags>(0));
    Segment * es2 = new Segment(ES2_SIZE, static_cast<Segment::Flags>(0));
    cout << "  extra segment 1 => " << ES1_SIZE << " bytes, done!\n";
    cout << "  extra segment 2 => " << ES2_SIZE << " bytes, done!\n";

    cout << "Attaching segments:\n";
    CPU::Log_Addr * extra1 = self.attach(*es1);
    CPU::Log_Addr * extra2 = self.attach(*es2);
    cout << "  extra segment 1 => " << extra1 << " done!\n";
    cout << "  extra segment 2 => " << extra2 << " done!\n";

    cout << "Writing data at segment 1!!\n";
    for (int i = 0; i < ES1_SIZE; i++) {
        reinterpret_cast<char*>(extra1)[i]  = 'a';
    }

    cout << "Testing data written at segment 1!!\n";
    for (int i = 0; i < ES1_SIZE; i++) {
        char aux = reinterpret_cast<char*>(extra1)[i];
        if(aux != 'a') {
            cout << "Error, expected 'a' got " << aux << "\n";
            return 0;
        }
    } 

    cout << "Writing data at segment 2!!\n";
    for (int i = 0; i < ES2_SIZE; i++) {
        reinterpret_cast<char*>(extra2)[i]  = 'b';
    }

    cout << "Testing data written at segment 2!!\n";
    for (int i = 0; i < ES2_SIZE; i++) {
        char aux = reinterpret_cast<char*>(extra2)[i];
        if(aux != 'b') {
            cout << "Error, expected 'b' got " << aux << "\n";
            return 0;
        }
    }

    cout << "Clearing segments:";
    memset(extra1, 0, ES1_SIZE);
    memset(extra2, 0, ES2_SIZE);
    cout << "  done!\n";

    cout << "Detaching segments:";
    self.detach(*es1);
    self.detach(*es2);
    cout << "  done!\n";

    cout << "Deleting segments:";
    delete es1;
    delete es2;
    cout << "  done!\n";

    return 0;
}
