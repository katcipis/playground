#include "xmppgui/util/KeyEventFowarder.hpp"
#include "xmppgui/Constants.hpp"

namespace cim{

IMPLEMENT_CLASS(KeyEventFowarder, wxEvtHandler)
BEGIN_EVENT_TABLE(KeyEventFowarder, wxEvtHandler)
  EVT_CHAR(KeyEventFowarder::OnKeyEvent)
  EVT_KEY_DOWN(KeyEventFowarder::OnKeyEvent)
  EVT_KEY_UP(KeyEventFowarder::OnKeyEvent)
END_EVENT_TABLE()
void KeyEventFowarder::OnKeyEvent(wxKeyEvent& event){
  PRU_LOG1("KeyEventFowarder");
  event.Skip();
  wxWindow * win = dynamic_cast<wxWindow *>(event.GetEventObject());
  if (win){
    wxWindow * parent = win->GetParent();
    if (parent){
      int old = event.StopPropagation();
      if (old > 0)
        event.ResumePropagation(old);
      else
        event.ResumePropagation(1);
      win->GetParent()->ProcessEvent(event);
      event.ResumePropagation(old);
    }
  }
  event.Skip();
}

IMPLEMENT_CLASS(KeyEventFowarderDelayed, wxEvtHandler)
BEGIN_EVENT_TABLE(KeyEventFowarderDelayed, wxEvtHandler)
  EVT_CHAR(KeyEventFowarderDelayed::OnKeyEvent)
  EVT_KEY_DOWN(KeyEventFowarderDelayed::OnKeyEvent)
  EVT_KEY_UP(KeyEventFowarderDelayed::OnKeyEvent)
END_EVENT_TABLE()
void KeyEventFowarderDelayed::OnKeyEvent(wxKeyEvent& event){
  PRU_LOG1("KeyEventFowarderDelayed");
  event.Skip();
  wxWindow * win = dynamic_cast<wxWindow *>(event.GetEventObject());
  if (win){
    wxWindow * parent = win->GetParent();
    if (parent){
      int old = event.StopPropagation();
      if (old > 0)
        event.ResumePropagation(old);
      else
        event.ResumePropagation(1);
      win->GetParent()->AddPendingEvent(event);
      event.ResumePropagation(old);
    }
  }
  event.Skip();
}


}
