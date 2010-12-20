// EPOS Thread Abstraction Implementation

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#include <secure/secure_segment.h>
#include <secure/secure_segment_manager.h>
#include <system/kmalloc.h>

__BEGIN_SYS

Secure_Segment::Secure_Segment(Cipher * cipher, unsigned int bytes, Flags flags) : MMU::Chunk(bytes, flags) 
{
    _protected = true;
    mark_as_non_present(); 

    db<Secure_Segment>(TRC) << "Secure_Segment(bytes=" << bytes << ", flags=" << _flags << ")\n";
    db<Secure_Segment>(TRC) << "Giving access permission to Thread [" << Thread::self() << "]\n";
    
    _cipher = cipher;

    /* Allowing the running thread that created the segment.
       There is no need to create a method to only do this */
    _allowed_threads.insert(new(kmalloc(sizeof(Thread_List::Element))) Thread_List::Element(Thread::self()));

    /* already marked as non present at construction, 
       Secure_Segment_Manager::add does not to mark as non-present */
    Secure_Segment_Manager::add(this);
}

Secure_Segment::~Secure_Segment()
{
    db<Secure_Segment>(TRC) << "Starting: ~Secure_Segment()\n"; 
    /* Lets free all the links */
    for (unsigned int i = 0; i < _allowed_threads.size(); i++) {
        kfree(_allowed_threads.remove());
    }
 
    Secure_Segment_Manager::remove(this);

    /* memset all the data to 0 to avoid the area to 
       be remapped and read after segment destruction. */
    if(_flags & IA32_Flags::CT) {
        memset((*_pt)[_from], _to - _from, 0);
    } else {
        for(unsigned int i = _from; i < _to; i++) {
            memset((*_pt)[i], sizeof((*_pt)[i]), 0);
        }
    }
    /* Chunk destructor will free it */
    db<Secure_Segment>(TRC) << "Finished: ~Secure_Segment()\n";
}

void Secure_Segment::mark_as_non_present()
{
    /* Marking as non present */
   db<Secure_Segment>(TRC) << "Secure_Segment::mark_as_non_present: old flag = "  << _flags << "\n"; 
   _flags = _flags & ~IA32_Flags::PRE;
   db<Secure_Segment>(TRC) << "Secure_Segment::mark_as_non_present: new flag = "  << _flags << "\n";
}

void Secure_Segment::mark_as_present()
{
    /* Marking as present */
    db<Secure_Segment>(TRC) << "Secure_Segment::mark_as_present: old flag = "  << _flags << "\n";
    _flags = _flags | IA32_Flags::PRE;
    db<Secure_Segment>(TRC) << "Secure_Segment::mark_as_present: new flag = "  << _flags << "\n";
    /* FIXME why after fixing the flag it gives a GPF ? */
}

void Secure_Segment::decipher()
{
    if(_flags & IA32_Flags::CT) {
        db<Secure_Segment>(TRC) << "Secure_Segment::decipher() contiguous segment \n";
        _cipher->decipher((*_pt)[_from], _to - _from);
    } else {
        db<Secure_Segment>(TRC) << "Secure_Segment::decipher() non-contiguous segment \n";
        for(unsigned int i = _from; i < _to; i++) {
            _cipher->decipher((*_pt)[i], sizeof((*_pt)[i]));
        }
    }

    _protected = false;
}


void Secure_Segment::encipher()
{
    if(_flags & IA32_Flags::CT) {
       db<Secure_Segment>(TRC) << "Secure_Segment::encipher() contiguous segment \n";
        _cipher->encipher((*_pt)[_from], _to - _from);
    } else {
        db<Secure_Segment>(TRC) << "Secure_Segment::encipher() non-contiguous segment \n";
        for(unsigned int i = _from; i < _to; i++) {
            _cipher->encipher((*_pt)[i], sizeof((*_pt)[i]));
        }
    }

    _protected = true;
}


bool Secure_Segment::allow(Thread *t)
{
    if (!is_allowed(Thread::self())) {
        return false;
    }

    _allowed_threads.insert(new(kmalloc(sizeof(Thread_List::Element))) Thread_List::Element(t));
    return true;
}

bool Secure_Segment::is_allowed(Thread *t)
{
   if (_allowed_threads.search(t)) {
       return true;
   } 

   return false;
}

bool Secure_Segment::is_protected()
{
    return _protected;
}

bool Secure_Segment::is_used()
{
    return (_flags & IA32_Flags::ACC) ? true: false;
}

void Secure_Segment::mark_as_unused()
{
    db<Secure_Segment>(TRC) << "Secure_Segment::mark_as_unused: old flag = "  << _flags << "\n";
    _flags = _flags & ~IA32_Flags::ACC;
    db<Secure_Segment>(TRC) << "Secure_Segment::mark_as_unused: new flag = "  << _flags << "\n";
}

__END_SYS

