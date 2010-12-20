#include "xmppgui/chat/MousePanel.hpp"

BEGIN_EVENT_TABLE(MousePanel, wxPanel)
	EVT_MOUSE_EVENTS(MousePanel::OnMouseEvent)
END_EVENT_TABLE()

MousePanel::MousePanel(wxWindow* parent, DrawPanel* draw_panel) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(200,-1))
{
	SetBackgroundColour(*wxWHITE);
	m_draw_panel = draw_panel;
}

MousePanel::~MousePanel()
{
}

void MousePanel::OnMouseEvent(wxMouseEvent& event) {
	std::cout <<"Mouse: " << event.GetX() <<", " << event.GetY()
	<< " | Left Button: " << event.LeftIsDown()
	<< " | Right Button: " << event.RightIsDown() << std::endl;
	
	m_draw_panel->MoveThatThing(event.GetX(),event.GetY());
}
