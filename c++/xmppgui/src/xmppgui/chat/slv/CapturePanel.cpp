#include "xmppgui/chat/slv/CapturePanel.hpp"
#include "xmppgui/chat/slv/ThreadSender.hpp"

#include <wx/gbsizer.h>

namespace cim {

CapturePanel::CapturePanel(wxWindow* parent, buzz::Jid other_jid) :
	wxPanel(parent, wxID_ANY) {

	Connect(GetId(), wxEVT_MOTION,
			wxMouseEventHandler(CapturePanel::OnMouseEvent));

	Connect(GetId(), wxEVT_LEFT_DCLICK, wxMouseEventHandler(
			CapturePanel::OnMouseEvent));
	Connect(GetId(), wxEVT_LEFT_UP, wxMouseEventHandler(
			CapturePanel::OnMouseEvent));

	Connect(GetId(), wxEVT_ENTER_WINDOW, wxMouseEventHandler(
			CapturePanel::OnMouseEvent));
	Connect(GetId(), wxEVT_LEAVE_WINDOW, wxMouseEventHandler(
			CapturePanel::OnMouseEvent));

	Connect(GetId(), wxEVT_RIGHT_DOWN, wxMouseEventHandler(
			CapturePanel::OnMouseEvent));
	Connect(GetId(), wxEVT_LEFT_DOWN, wxMouseEventHandler(
			CapturePanel::OnMouseEvent));

	m_pos_x = -1;
	m_pos_y = -1;
	m_other_jid = other_jid;

	ThreadSender *sender = new ThreadSender(this, other_jid);
	sender->Create();
	sender->Run();
}

CapturePanel::~CapturePanel() {

}

void CapturePanel::OnMouseEvent(wxMouseEvent &event) {
	m_pos_x = event.GetX();
	m_pos_y = event.GetY();

	if(m_mouse_left_is_down && !event.Dragging())
		m_mouse_left_is_up = true;

	m_mouse_left_is_down = event.Dragging();

	if (!m_mouse_left_double_clicked)
		m_mouse_left_double_clicked = event.LeftDClick();

	if (!m_mouse_left_is_clicked)
		m_mouse_left_is_clicked = event.LeftDown();

	if (!m_mouse_right_is_clicked)
		m_mouse_right_is_clicked = event.RightDown();

	if (!m_mouse_entered_window)
		m_mouse_entered_window = event.Entering();

	if (!m_mouse_leave_window)
		m_mouse_leave_window = event.Leaving();

}

wxString CapturePanel::GetPositionString() {
	wxString pos = wxString::Format(wxT("%d"), m_pos_x) + wxT("|")
			+ wxString::Format(wxT("%d"), m_pos_y);
	return pos;
}

bool CapturePanel::MouseLeftIsDown() {
	return m_mouse_left_is_down;
}

bool CapturePanel::MouseLeftIsUp() {
	bool tmp = m_mouse_left_is_up;
	m_mouse_left_is_up = false;

	return tmp;
}

bool CapturePanel::MouseLeftIsDoubleClicked() {
	bool tmp = m_mouse_left_double_clicked;
	m_mouse_left_double_clicked = false;

	return tmp;
}

bool CapturePanel::MouseRightIsClicked() {
	bool tmp = m_mouse_right_is_clicked;
	m_mouse_right_is_clicked = false;

	return tmp;
}

bool CapturePanel::MouseLeftIsClicked() {
	bool tmp = m_mouse_left_is_clicked;
	m_mouse_left_is_clicked = false;

	return tmp;
}

bool CapturePanel::MouseEnteredWindow() {
	bool tmp = m_mouse_entered_window;
	m_mouse_entered_window = false;

	return tmp;
}
bool CapturePanel::MouseLeaveWindow() {
	bool tmp = m_mouse_leave_window;
	m_mouse_leave_window = false;

	return tmp;
}

}
