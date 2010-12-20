#ifndef CAPTUREPANEL_HPP_
#define CAPTUREPANEL_HPP_

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif


#include "xmppgui/chat/ChatPanel.hpp"
#include "xmppgui/chat/slv/CapturePanel.hpp"


#include "xmppgui/Constants.hpp"

#include "xmppgui/xmpp/CimStarter.hpp"

#include "xmppgui/util/KeyEventFowarder.hpp"
#include "xmppgui/util/XmppEvent.hpp"


namespace cim{

class CapturePanel : public wxPanel {
public:
	CapturePanel(wxWindow* parent, buzz::Jid other_jid);
	virtual ~CapturePanel();

	void OnMouseEvent(wxMouseEvent &event);
	wxString GetPositionString();
	bool MouseLeftIsDown();
	bool MouseLeftIsUp();
	bool MouseLeftIsDoubleClicked();
	bool MouseRightIsClicked();
	bool MouseLeftIsClicked();

	bool MouseEnteredWindow();
	bool MouseLeaveWindow();

private:
	int m_pos_x;
	int m_pos_y;

	bool m_mouse_left_is_down;
	bool m_mouse_left_is_up;
	bool m_mouse_left_is_clicked;
	bool m_mouse_left_double_clicked;
	bool m_mouse_right_is_clicked;

	bool m_mouse_entered_window;
	bool m_mouse_leave_window;

	buzz::Jid m_other_jid;
};

}

#endif /*CAPTUREPANEL_HPP_*/
