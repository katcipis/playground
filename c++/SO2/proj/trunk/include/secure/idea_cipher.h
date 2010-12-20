// EPOS Secure Memory Segment Abstraction Declarations

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#ifndef __idea_cipher_h
#define __idea_cipher_h

#include <secure/cipher.h>
#include <system/config.h>

__BEGIN_SYS

class IDEA_Cipher : public Cipher
{
public:
    typedef unsigned long ulong;
    typedef unsigned short ushort;

private:
    char * buffer;
    unsigned int buffer_size;

private:
    ushort add(long a, long b);
    ushort multiply(long a, long b);
    void encryption(ushort *X, ushort *Y, long **K);
    void ushort_to_bits(ushort number, ushort *bits);
    void cyclic_left_shift(ushort index, ushort *bits1, ushort *bits2, long **K);
    void encryption_key_schedule(ushort *key, long **K);
    void extended_euclidean(long a, long b, long *x, long *y, long *d);
    long inv(ushort ub);
    void decryption_key_schedule(long **K, long **L);
    ushort bits_to_ushort(ushort *bits);


public:
    IDEA_Cipher();
    void encipher(void * data, unsigned int data_size);
    void decipher(void * data, unsigned int data_size);
    ~IDEA_Cipher();
};

__END_SYS

#endif
