// EPOS Secure Memory Segment Abstraction Declarations

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#ifndef __cipher_h
#define __cipher_h

__BEGIN_SYS

class Cipher
{
public:
    virtual void encipher(void * data, size_t data_size) = 0;
    virtual void decipher(void * data, size_t data_size) = 0;
    virtual ~Cipher(){};
};

__END_SYS

#endif
