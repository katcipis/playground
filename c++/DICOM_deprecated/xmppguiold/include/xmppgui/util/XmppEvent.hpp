#ifndef XMPPEVENT_HPP_9UVATHU7
#define XMPPEVENT_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "talk/session/phone/call.h"
#include "talk/session/fileshare/fileshare.h"
#include "talk/xmpp/xmppengine.h"
#include "talk/examples/login/status.h"

namespace cim{
  
class RosterItem;

BEGIN_DECLARE_EVENT_TYPES()
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_CallEnd, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_ChangeOwnState, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_CallState, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_Calling, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_InconingMessage, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_ChangeRosterStatus, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_ChangeRosterData, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_FileSessionState, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_FileUpdateProgress, -1)
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_FileShareCreate, -1)
END_DECLARE_EVENT_TYPES()
 
template<class arg0_type = char, class arg1_type = char, class arg2_type = char, class arg3_type = char>
class XmppEvent: public wxNotifyEvent{
public:
  XmppEvent(wxEventType eventType = wxEVT_NULL, int id = 0)
        : wxNotifyEvent(eventType, id){};
  XmppEvent( const XmppEvent<arg0_type,arg1_type,arg2_type,arg3_type> &event )
        : wxNotifyEvent(event){
    arg0 = event.arg0; arg1 = event.arg1; arg2 = event.arg2; arg3 = event.arg3;
  }
  virtual ~XmppEvent() {};
  
  wxEvent* Clone() const { return new XmppEvent<arg0_type,arg1_type,arg2_type,arg3_type>(*this); };
  
  arg0_type arg0;
  arg1_type arg1;
  arg2_type arg2;
  arg3_type arg3;
protected:
}; 
  
  
  
typedef XmppEvent<cricket::Call *> CallEndEvent;
typedef XmppEvent<buzz::XmppEngine::State> ChangeOwnStateEvent;
typedef XmppEvent<cricket::Call *, cricket::Session *, cricket::Session::State> CallStateEvent;
typedef XmppEvent<buzz::Jid, bool, bool> CallingEvent;
typedef XmppEvent<buzz::Jid, std::string> InconingMessageEvent;
typedef XmppEvent<buzz::Status> ChangeRosterStatusEvent;
typedef XmppEvent<RosterItem> ChangeRosterDataEvent;
typedef XmppEvent<cricket::FileShareSession *, cricket::FileShareState> FileSessionStateEvent;
typedef XmppEvent<cricket::FileShareSession *> FileShareSessionEvent;

}

#endif /*XMPPEVENT_HPP_9UVATHU7*/
