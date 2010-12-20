#ifndef THREADSENDER_HPP_
#define THREADSENDER_HPP_

#include <wx/thread.h>
#include "xmppgui/chat/slv/CapturePanel.hpp"

namespace cim {

class ThreadSender : public wxThread {
public:
	ThreadSender(CapturePanel *panel, buzz::Jid other_jid);
	virtual ~ThreadSender();
	void* Entry();
	
private:
	CapturePanel *m_panel;
	buzz::Jid m_other_jid;
};
}

#endif /*THREADSENDER_HPP_*/
