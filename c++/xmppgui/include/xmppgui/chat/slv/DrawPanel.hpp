#ifndef DRAWPANEL_HPP_
#define DRAWPANEL_HPP_

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include <wx/dcclient.h>

class DrawPanel : public wxPanel
{
public:
	DrawPanel(wxWindow* parent);
	virtual ~DrawPanel();
	void MoveThatThing(unsigned int x,unsigned int y);
	
	
private:
	wxPaintDC* m_piriplimplim;
};

#endif /*DRAWPANEL_HPP_*/
