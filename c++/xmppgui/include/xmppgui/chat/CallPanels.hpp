#ifndef CALLPANELS_HPP_9UVATHU7
#define CALLPANELS_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "xmppgui/xmpp/CimStarter.hpp"


namespace cim{

class IncomingCall: public wxPanel{
public:
  IncomingCall(wxWindow *parent, buzz::Jid jid);
  virtual ~IncomingCall();
  
  void SetData(cricket::Call *call, cricket::Session *session);
  void MakeVisible(bool b);
  
  void OnAccept(wxCommandEvent &event);
  void OnReject(wxCommandEvent &event);
private:
  wxButton *m_accept;
  wxButton *m_reject;
  buzz::Jid m_jid;
  cricket::Call *m_call;
  cricket::Session *m_session;
  
  void Init();

};


class CurrentCall: public wxPanel{
public:
  CurrentCall(wxWindow *parent, buzz::Jid jid);
  ~CurrentCall();
  
  void SetData(cricket::Call *call, cricket::Session *session);
  void MakeVisible(bool b);
  
  void OnHangup(wxCommandEvent &event);
private:
  wxButton *m_hangup;
  buzz::Jid m_jid;
  cricket::Call *m_call;
  cricket::Session *m_session;
  
  void Init();
};


class DoCall: public wxPanel{
public:
  DoCall(wxWindow *parent, buzz::Jid jid);
  ~DoCall();
  
  void MakeVisible(bool b);
  
  void OnCall(wxCommandEvent &event);
private:
  wxButton *m_call;
  buzz::Jid m_jid;
  
  void Init();
};


} //namespace cim

#endif /*CALLPANELS_HPP_9UVATHU7*/
