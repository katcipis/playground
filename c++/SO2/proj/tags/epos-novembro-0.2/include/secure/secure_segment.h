// EPOS Secure Memory Segment Abstraction Declarations

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#ifndef __secure_segment_h
#define __secure_segment_h

#include <mmu.h>
#include <thread.h>
#include <utility/list.h>
#include <secure/cipher.h>

__BEGIN_SYS

class Secure_Segment: public MMU::Chunk
{
private:
    typedef List<Thread> Thread_List;
    typedef MMU::Flags Flags;
    friend class Secure_Segment_Manager;

public:
    Secure_Segment(Cipher * cipher, unsigned int bytes, Flags flags = Flags::APP);
    ~Secure_Segment();

    bool allow(Thread *t);


private:
    void mark_as_non_present();
    void mark_as_present();
    void decipher();
    void encipher();
    bool is_allowed(Thread *t);
    bool is_protected();
    bool is_used();
    void mark_as_unused();

private:
    Thread_List _allowed_threads;
    Cipher * _cipher;

};

__END_SYS

#endif
