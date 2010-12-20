// EPOS Secure Memory Segment Abstraction Declarations

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#ifndef __secure_segment_manager_h
#define __secure_segment_manager_h

#include <secure/secure_segment.h>
#include <utility/list.h>
#include <mach/pc/ic.h>
#include <cpu.h>
#include <periodic_thread.h>

__BEGIN_SYS

class Secure_Segment_Manager
{
private:
    typedef List<Secure_Segment> Segment_List;
    typedef CPU::Log_Addr Log_Addr;
    typedef CPU::Reg32 Reg32;
    typedef PC_IC::Interrupt_Id Interrupt_Id;

    typedef struct _Attached_Segment {
        Secure_Segment * segment;
        Log_Addr         addr; 
    } Attached_Segment;

    typedef List<Attached_Segment> Attached_Segment_List;

    friend class Secure_Segment;
    friend class Address_Space;

    /* Got from Intel manual Order Number: 253668-036US September 2010 */
    enum PageFaultErrorCode {
        NON_PRESENT       = 0x001,
        WRITE             = 0x002,
        USER_MODE         = 0x004,
        RSVD              = 0x008,
        INSTRUCTION_FETCH = 0x010
    }; 

private:
    static void start();
    static void stop();

    static void add(const Secure_Segment *segment);
    static void add_log_addr(const Secure_Segment *segment, Log_Addr addr);

    static void remove(const Secure_Segment * segment);

    static void _pf_handler (Interrupt_Id i,
                             Reg32 error, Reg32 eip, Reg32 cs, Reg32 eflags);

    static Secure_Segment * get_segment(Log_Addr log_addr);
    static int check_segments();
    static void search();

private:
    static Segment_List             _segments;
    static Attached_Segment_List    _attached_segments;
    static Periodic_Thread *        _manager_thread;
    static PC_IC::Interrupt_Handler _default_pf_int_handler;
    static const long               check_segments_period = 500000; /* 500ms, should be at traits.h */

};

__END_SYS

#endif
