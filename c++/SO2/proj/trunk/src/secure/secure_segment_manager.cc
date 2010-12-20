// EPOS Thread Abstraction Implementation

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#include <secure/secure_segment_manager.h>
#include <utility/malloc.h>
#include <cpu.h>


__BEGIN_SYS
extern "C" { void _exit(int s); } /* Magic got from /mach/pc/ic.cc */


/* Class attributes */
Secure_Segment_Manager::Segment_List              Secure_Segment_Manager::_segments;
Secure_Segment_Manager::Attached_Segment_List     Secure_Segment_Manager::_attached_segments;
const long                                        Secure_Segment_Manager::check_segments_period; /* should be at traits.h */
Periodic_Thread *                                 Secure_Segment_Manager::_manager_thread;
PC_IC::Interrupt_Handler                          Secure_Segment_Manager::_default_pf_int_handler;

void Secure_Segment_Manager::start()
{
    if (_manager_thread) {
        /* already started !!!*/
        return;
    }

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::start()\n";

    CPU::int_disable();

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: getting old handler\n";
    _default_pf_int_handler  = PC_IC::int_vector(IA32::EXC_PF);

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: installing new handler\n";
    PC_IC::int_vector(IA32::EXC_PF, reinterpret_cast<PC_IC::Interrupt_Handler>(&_pf_handler));

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: Creating the periodic check_segments thread\n";
    _manager_thread = new(kmalloc(sizeof(Periodic_Thread))) Periodic_Thread(&Secure_Segment_Manager::check_segments, check_segments_period);

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: exiting start call\n";

    CPU::int_enable();
}

void Secure_Segment_Manager::stop()
{
    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::stop()\n";

    CPU::int_disable();

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: installing old handler\n";
    PC_IC::int_vector(IA32::EXC_PF,  reinterpret_cast<PC_IC::Interrupt_Handler>(&_default_pf_int_handler));

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: Destroying the periodic check_segments thread\n";
    delete _manager_thread;
    _manager_thread = 0;

    db<Init, Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager:: exiting stop\n";

    CPU::int_enable();
}


void Secure_Segment_Manager::add(const Secure_Segment * segment){
    db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::add(segment = " << segment <<")\n";
    Segment_List::Element * link = new(kmalloc(sizeof(Segment_List::Element))) Segment_List::Element(segment);
    _segments.insert(link);

    Secure_Segment_Manager::start();
}


void Secure_Segment_Manager::add_log_addr(const Secure_Segment * segment, Log_Addr addr){
    db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::add_log_addr(segment = " << segment << ", addr = " << addr << ")\n";

    Attached_Segment * attached_seg = reinterpret_cast<Attached_Segment *> (kmalloc(sizeof(Attached_Segment)));
    attached_seg->segment = (Secure_Segment *) segment;
    attached_seg->addr    = addr;

    _attached_segments.insert(new(kmalloc(sizeof(Attached_Segment_List::Element))) Attached_Segment_List::Element(attached_seg));
}


void Secure_Segment_Manager::remove(const Secure_Segment * segment){
    db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::remove(segment = " << segment <<")\n";
    kfree(_segments.remove(segment)); /* Freeing the previously allocated link */

    /* Freeing previously allocates link and data */
    for(Attached_Segment_List::Iterator i = _attached_segments.begin(); i != _attached_segments.end(); i++) {
	Attached_Segment * att = i->object();
        if (att->segment == segment) {
            db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::remove segment had a log_addr " << att->addr << "\n";
            /* Removing Log_Addr of the segment*/
            kfree(_attached_segments.remove(att));
            kfree(att);
        }
    }

    if (_segments.empty()) {
        Secure_Segment_Manager::stop();
    }
}


int Secure_Segment_Manager::check_segments()
{
    while (true) {
        db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::check_segments() fired !!!\n";
        search();
        Periodic_Thread::wait_next();
    }

    return 0;
}


Secure_Segment * Secure_Segment_Manager::get_segment(Log_Addr log_addr)
{
    db<PC>(TRC) << "Secure_Segment_Manager::get_segment(log_addr = " << log_addr << "\n";
    /*FIXME make it more efficient, but since the page presence mechanism was not even used at EPOS (like swap)
            all page faults caused by a non-present page will mostly be a Secure_Segment */

    for(Attached_Segment_List::Iterator i = _attached_segments.begin(); i != _attached_segments.end(); i++) {
        Attached_Segment * att = i->object();
        /* check if the Log_Addr belong to a Secure_Segment */
        if (att->addr <= log_addr && log_addr <= (att->addr + att->segment->size())) {
            db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::get_segment the log_addr maps to segment = " << att->segment << "\n";
            return att->segment;
        }
    }
    return 0;
}


void Secure_Segment_Manager::_pf_handler (Interrupt_Id i, Reg32 error, Reg32 eip, Reg32 cs, Reg32 eflags)
{
    /* According to intel manual (Order Number: 253668-036US September 2010. 
       Volume 3A: System Programming Guide, Part 1) page 282 the processor pushes on the stack
       an error code (32bits) and the content of the CR2 register (32 bits). Read the section that starts
       at pag 280 to full understand all the black magic. Something pretty simple is done here.*/

   /*  There is this too: Processors update CR2 whenever a page fault is detected. If a second page fault occurs while an
       earlier page fault is being delivered, the faulting linear address of the second fault will overwrite
       the contents of CR2 (replacing the previous address). These updates to CR2 occur even if the
       page fault results in a double fault or occurs during the delivery of a double fault.
   */
      
    PC_IC::Reg32 cr2 = CPU::cr2(); /* Making the function reentrant! */
    char * stack_addr = (char*) &i;

    db<Secure_Segment_Manager>(TRC) << "\nInterrupt_Id i address [" << (void*) &i <<  "] = [" << (void*) i << "]\n";
    db<Secure_Segment_Manager>(TRC) << "Reg32 error address [" << (void*) &error <<  "] = [" << (void*) error << "]\n";
    db<Secure_Segment_Manager>(TRC) << "Reg32 eip address [" << (void*) &eip <<  "] = [" << (void*) eip << "]\n";
    db<Secure_Segment_Manager>(TRC) << "Reg32 cs address [" << (void*) &cs <<  "] = [" << (void*) cs << "]\n";
    db<Secure_Segment_Manager>(TRC) << "Reg32 eflags address [" << (void*) &eflags <<  "] = [" << (void*) eflags << "]\n\n";

    for (int j = -40; j <= 40; j += 4) {
        int * aux = (int *) (stack_addr + j);
        db<Secure_Segment_Manager>(TRC) << "Stack address [" << (void*) aux <<  "] = [" << (void*) *aux << "]\n";
    }
    
    if (error & NON_PRESENT) {
        db<Secure_Segment_Manager>(TRC) << "\nSecure_Segment_Manager::_pf_handler: the error is a non-presence \n";

        Secure_Segment * seg = get_segment(static_cast<Log_Addr>(cr2));
        if (seg && seg->is_allowed(Thread::self())) {
            seg->mark_as_present();
            seg->decipher();
            db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::_pf_handler:" 
                                               "a Secure_Segment page fault has been handled ok! returning from handler!, \n";
            return;
        }
    } 

    db<Secure_Segment_Manager>(WRN) << "Secure_Segment_Manager::_pf_handler: Unexpected page fault at Thread" << Thread::self() << "!\n";
    db<Secure_Segment_Manager>(WRN) << "Secure_Segment_Manager::_pf_handler: The running thread will now be terminated!\n";
    _exit(-1); 
}


void Secure_Segment_Manager::search()
{
    db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::search() fired !!!\n";
    for (Segment_List::Iterator i = _segments.begin(); i != _segments.end(); i++)
    {
        Secure_Segment * seg = i->object();
	if(!seg->is_protected()) {
            db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::search() - Segment is not protected !!!\n";
	    if(seg->is_used()) {
                db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::search() - Segment is used !!!\n";
	        seg->mark_as_unused();
	    } else {
                db<Secure_Segment_Manager>(TRC) << "Secure_Segment_Manager::search() - encipher segment !!!\n";
		seg->encipher();
            }
        }
    }
}
__END_SYS

