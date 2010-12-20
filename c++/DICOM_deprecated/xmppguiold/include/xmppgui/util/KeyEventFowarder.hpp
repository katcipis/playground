#ifndef KEYEVENTFOWARDER_HPP_9UVATHU7
#define KEYEVENTFOWARDER_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

namespace cim{
  
class KeyEventFowarder : public wxEvtHandler{
DECLARE_CLASS(KeyEventFowarder)
public:
  void OnKeyEvent(wxKeyEvent& event);
  DECLARE_EVENT_TABLE()
};

static KeyEventFowarder * const g_key_event_fowarder = new KeyEventFowarder();

class KeyEventFowarderDelayed : public wxEvtHandler{
DECLARE_CLASS(KeyEventFowarderDelayed)
public:
  void OnKeyEvent(wxKeyEvent& event);
  DECLARE_EVENT_TABLE()
};

static KeyEventFowarderDelayed * const g_key_event_fowarder_delayed = new KeyEventFowarderDelayed();

}

#endif /*KEYEVENTFOWARDER_HPP_9UVATHU7*/
