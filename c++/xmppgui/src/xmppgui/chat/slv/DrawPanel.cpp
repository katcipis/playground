#include "xmppgui/chat/slv/DrawPanel.hpp"

DrawPanel::DrawPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(200,-1))
{
	SetBackgroundColour(*wxWHITE);
	m_piriplimplim = new wxPaintDC(this);

}

DrawPanel::~DrawPanel()
{
}

void DrawPanel::MoveThatThing(unsigned int x,unsigned int y) {
	m_piriplimplim->Clear();
	m_piriplimplim->CrossHair(x, y);
}
