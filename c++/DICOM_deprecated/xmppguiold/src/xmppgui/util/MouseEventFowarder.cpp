#include "xmppgui/util/MouseEventFowarder.hpp"

namespace cim{

IMPLEMENT_CLASS(MouseEventFowarder, wxEvtHandler)
BEGIN_EVENT_TABLE(MouseEventFowarder, wxEvtHandler)
  EVT_MOUSE_EVENTS(MouseEventFowarder::OnMouseEvent)
END_EVENT_TABLE()
void MouseEventFowarder::OnMouseEvent(wxMouseEvent& event){
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

IMPLEMENT_CLASS(MouseEventFowarderDelayed, wxEvtHandler)
BEGIN_EVENT_TABLE(MouseEventFowarderDelayed, wxEvtHandler)
  EVT_MOUSE_EVENTS(MouseEventFowarderDelayed::OnMouseEvent)
END_EVENT_TABLE()
void MouseEventFowarderDelayed::OnMouseEvent(wxMouseEvent& event){
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
