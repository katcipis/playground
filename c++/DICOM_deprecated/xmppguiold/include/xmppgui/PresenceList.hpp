#ifndef PRESENCELIST_HPP_9UVATHU7
#define PRESENCELIST_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif


#include "xmppgui/xmpp/CimClient.hpp"
#include "xmppgui/GuiContact.hpp"
#include "xmppgui/chat/ChatControler.hpp"

#include "talk/xmpp/jid.h"
#include "talk/examples/login/status.h"
#include "talk/base/sigslot.h"

#include <wx/panel.h>

#include <map>

namespace cim{

class PresenceList: public wxPanel, public sigslot::has_slots<> {
public:
  PresenceList(wxWindow* parent);
  virtual ~PresenceList();

  void InitGui();
  
  // the call
  void OnCallEnd(cricket::Call *call);
  // the new state
  void OnChangeOwnState(buzz::XmppEngine::State state);
  // the call, session, the call's state
  void OnCallState(cricket::Call *call, cricket::Session *session, cricket::Session::State state);
  // other side jid, found, has calling capabilities 
  void OnCalling(buzz::Jid jid, bool found, bool cap);
  void OnInconingMessage(buzz::Jid jid, std::string msg);
  void OnChangeRosterStatus(buzz::Status status);
  void OnChangeRosterData(RosterItem &item);
  
  void OnFileSessionState(cricket::FileShareSession *sess, cricket::FileShareState state);
  void OnFileUpdateProgress(cricket::FileShareSession *sess);
  void OnFileShareCreate(cricket::FileShareSession *sess);
  
  //void OnStatusUpdate(const buzz::Status& status);
  
  void SetMyJid(buzz::Jid jid);
  buzz::Jid GetMyJid();

private:
  typedef std::map<wxString, GuiContact*> GuiRosterMap;
  GuiRosterMap m_roster;
  
  wxString m_quote;
  buzz::Status::Show m_state;
    
  wxPanel *m_upper_pane;
  wxPanel *m_lower_pane;
  wxScrolledWindow *m_contact_list;
  
  ChatControler m_chat_controler;
  buzz::Jid m_jid;
  
  wxStaticBitmap *m_own_state;
  wxStaticText *m_own_name;
  wxTextCtrl *m_own_quote;
  
  wxMenu *m_state_menu;
  
  bool AddContact(GuiContact *item);
  //bool RemoveContact(const buzz::Jid &item);
  void OnContactCick(wxCommandEvent& event);
  
  void InitStateMenu();
  void OnStateMenuSelect(wxCommandEvent& event);
  void InitUpperPane();
  void UpdateUpperPane();
  void OnOwnStateClick(wxEvent &event);
  void OnOwnQuoteExit(wxEvent &event);
  void UpdateOwnStateImage();

  // the call
  //void OnWxCallEnd(XmppEvent<cricket::Call *> &event);
  void OnWxCallEnd(wxNotifyEvent &event);
  // the new state
  //void OnWxChangeOwnState(XmppEvent<buzz::XmppEngine::State> &event);
  void OnWxChangeOwnState(wxNotifyEvent &event);
  // the call, session, the call's state
  //void OnWxCallState(XmppEvent<cricket::Call *, cricket::Session *, cricket::Session::State> &event);
  void OnWxCallState(wxNotifyEvent &event);
  // other side jid, found, has calling capabilities 
  //void OnWxCalling(XmppEvent<buzz::Jid, bool, bool> &event);
  void OnWxCalling(wxNotifyEvent &event);
  //void OnWxInconingMessage(XmppEvent<buzz::Jid, std::string> &event);
  void OnWxInconingMessage(wxNotifyEvent &event);
  //void OnWxChangeRosterStatus(XmppEvent<buzz::Status> &event);
  void OnWxChangeRosterStatus(wxNotifyEvent &event);
  //void OnWxChangeRosterData(XmppEvent<RosterItem> &event);
  void OnWxChangeRosterData(wxNotifyEvent &event);
  
  //void OnWxFileSessionState(XmppEvent<cricket::FileShareState>);
  void OnWxFileSessionState(wxNotifyEvent &event);
  //void OnWxFileUpdateProgress(XmppEvent<cricket::FileShareSession *>);
  void OnWxFileUpdateProgress(wxNotifyEvent &event);
  //void OnWxFileShareCreate(XmppEvent<cricket::FileShareSession *>);
  void OnWxFileShareCreate(wxNotifyEvent &event);
};

} //namespace cim

#endif /*PRESENCELIST_HPP_9UVATHU7*/
