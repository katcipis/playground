// EPOS Secure Memory Segment Abstraction Declarations

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#ifndef __xor_cipher_h
#define __xor_cipher_h

#include <secure/cipher.h>
#include <system/config.h>

__BEGIN_SYS

class XOR_Cipher : public Cipher
{

private:
    void xor_data(char * data, unsigned int data_size);

public:
    XOR_Cipher();
    void encipher(void * data, unsigned int data_size);
    void decipher(void * data, unsigned int data_size);
    ~XOR_Cipher();
};

__END_SYS

#endif
