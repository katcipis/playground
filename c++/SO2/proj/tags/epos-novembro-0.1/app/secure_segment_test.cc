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

class MockCipher : public Cipher
{
private:
    OStream cout;

public:

    void encipher(void * data, size_t data_size)
    {
        cout << "MockCipher:encipher: data(" << data << ") size(" << data_size << ")\n";
    }
    void decipher(void * data, size_t data_size)
    {
        cout << "MockCipher:decipher: data(" << data << ") size(" << data_size << ")\n";
    }
};

int main()
{
    OStream cout;
    Cipher * cipher = new MockCipher();

    cout << "Secure Segment test\n";

    cout << "My address space's page directory is located at "
	 << reinterpret_cast<void *>(CPU::pdp()) << "\n";
    Address_Space self(Address_Space::SELF);

    cout << "Creating two extra data segments:\n";
    Secure_Segment * es1 = new Secure_Segment(cipher, ES1_SIZE);
    Segment * es2 = new Segment(ES2_SIZE);
    cout << "  extra segment 1 => " << ES1_SIZE << " bytes, done!\n";
    cout << "  extra segment 2 => " << ES2_SIZE << " bytes, done!\n";

    cout << "Attaching segments:\n";
    CPU::Log_Addr * extra1 = self.attach(*es1);
    CPU::Log_Addr * extra2 = self.attach(*es2);
    cout << "  extra segment 1 => " << extra1 << " done!\n";
    cout << "  extra segment 2 => " << extra2 << " done!\n";

    cout << "Writing data at segment 1!!\n";
    memset(extra1, 1, ES1_SIZE);

    cout << "Writing data at segment 2!!\n";
    memset(extra1, 2, ES1_SIZE);

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
