// EPOS PLASMA NULL NIC Mediator Declarations

// This work is licensed under the EPOS Software License v1.0.
// A copy of this license is available at the EPOS system source tree root.
// A copy of this license is also available online at:
// http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0
// Note that EPOS Software License applies to both source code and executables.

#ifndef __plasma_nic_h
#define __plasma_nic_h

#include <nic.h>

__BEGIN_SYS

class PLASMA_NIC: public NIC_Common
{
private:
    //typedef Traits<PLASMA_NIC>::NICS NICS;
    //static const unsigned int UNITS = NICS::Length;
    static const unsigned int UNITS = 0;

public:
    PLASMA_NIC() {  }

    ~PLASMA_NIC() {}

    int send(const Address & dst, const Protocol & prot, 
	     const void * data, unsigned int size) {
        return 0;
    }

    int receive(Address * src, Protocol * prot,
		void * data, unsigned int size) {
        return 0;
    }

    void reset() {}

    unsigned int mtu() const { return (unsigned int)0; }

    const Address & address() {
        return _Addr;
    }

    const Statistics & statistics() {
	return _Stat;
    }

    static void init();

private:
    Address _Addr;
    Statistics _Stat;
};

__END_SYS

#endif
