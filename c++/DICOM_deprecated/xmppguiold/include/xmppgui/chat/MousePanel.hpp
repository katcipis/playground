#ifndef MOUSEPANEL_HPP_
#define MOUSEPANEL_HPP_

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "xmppgui/chat/DrawPanel.hpp"

class MousePanel : public wxPanel
{
public:
	MousePanel(wxWindow* parent, DrawPanel* draw_panel);
	virtual ~MousePanel();
	void OnMouseEvent(wxMouseEvent& event);
	
	DECLARE_EVENT_TABLE()
private:
	DrawPanel* m_draw_panel;
};

#endif /*MOUSEPANEL_HPP_*/
