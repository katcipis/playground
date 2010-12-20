#ifndef MOUSEEVENTFOWARDER_HPP_9UVATHU7
#define MOUSEEVENTFOWARDER_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif


namespace cim{

class MouseEventFowarder : public wxEvtHandler{
DECLARE_CLASS(MouseEventFowarder)
public:
  void OnMouseEvent(wxMouseEvent& event);
  DECLARE_EVENT_TABLE()
};
static MouseEventFowarder * const g_mouse_event_fowarder
      = new MouseEventFowarder();

class MouseEventFowarderDelayed : public wxEvtHandler{
DECLARE_CLASS(MouseEventFowarderDelayed)
public:
  void OnMouseEvent(wxMouseEvent& event);
  DECLARE_EVENT_TABLE()
};
static MouseEventFowarderDelayed * const g_mouse_event_fowarder_delayed
      = new MouseEventFowarderDelayed();

}

#endif /*MOUSEEVENTFOWARDER_HPP_9UVATHU7*/
