#include "xmppgui/chat/CallPanels.hpp"

#include "xmppgui/Constants.hpp"

#include "talk/base/thread.h"

namespace cim{
  
//////////////////////
// IncomingCall
//////////////////////
IncomingCall::IncomingCall(wxWindow *parent, buzz::Jid jid)
      : wxPanel(parent), m_jid(jid), m_call(NULL), m_session(NULL){
  Init();
  GetSizer()->SetSizeHints(this);
}

IncomingCall::~IncomingCall(){
}

void IncomingCall::SetData(cricket::Call *call, cricket::Session *session){
  m_call = call;
  m_session = session;
}
  
void IncomingCall::MakeVisible(bool b){
  m_accept->Enable(b);
  m_reject->Enable(b);
  Show(b);
}

void IncomingCall::Init(){
  wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(sizer);
  
  m_accept = new wxButton(this, wxID_ANY, wxT("Accept"));
  m_reject = new wxButton(this, wxID_ANY, wxT("Reject"));;
  
  sizer->Add(m_accept, 0, wxFIXED_MINSIZE, 5);
  sizer->Add(m_reject, 0, wxFIXED_MINSIZE | wxLEFT, 5);
  
  // handlers
  Connect(m_accept->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(IncomingCall::OnAccept));  
  Connect(m_reject->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(IncomingCall::OnReject));  
}


void IncomingCall::OnAccept(wxCommandEvent &event){
  if (m_call && m_session){
    CimClient *client = CimStarter::GetInstance().GetCimClient();
    client->AcceptCall(m_call, m_session);
    m_accept->Enable(false);
    m_reject->Enable(false);
    
    m_call = NULL;
    m_session = NULL;
  }
}

void IncomingCall::OnReject(wxCommandEvent &event){
  if (m_call && m_session){
    CimClient *client = CimStarter::GetInstance().GetCimClient();
    client->RejectCall(m_call, m_session);
    m_accept->Enable(false);
    m_reject->Enable(false);
    
    m_call = NULL;
    m_session = NULL;
  }
}


//////////////////////
// CurrentCall
//////////////////////
CurrentCall::CurrentCall(wxWindow *parent, buzz::Jid jid)
      : wxPanel(parent), m_jid(jid), m_call(NULL), m_session(NULL) {
  Init();
  GetSizer()->SetSizeHints(this);
}


CurrentCall::~CurrentCall(){
}

void CurrentCall::SetData(cricket::Call *call, cricket::Session *session){
  m_call = call;
  m_session = session;
}
  
void CurrentCall::MakeVisible(bool b){
  m_hangup->Enable(b);
  Show(b);
}
  
  
void CurrentCall::Init(){
  wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(sizer);
  
  m_hangup = new wxButton(this, wxID_ANY, wxT("Hangup"));
  
  sizer->Add(m_hangup, 0, wxFIXED_MINSIZE, 5);
  
  // handlers
  Connect(m_hangup->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(CurrentCall::OnHangup));
}

void CurrentCall::OnHangup(wxCommandEvent &event){
  if (m_call && m_session){
    CimClient *client = CimStarter::GetInstance().GetCimClient();
    client->HangupCall(m_call, m_session);
    m_hangup->Enable(false);
    
    m_call = NULL;
    m_session = NULL;
  }
}

//////////////////////
// DoCall
//////////////////////
DoCall::DoCall(wxWindow *parent, buzz::Jid jid)
      : wxPanel(parent), m_jid(jid){
  Init();
  GetSizer()->SetSizeHints(this);
}


DoCall::~DoCall(){
}

void DoCall::MakeVisible(bool b){
  m_call->Enable(b);
  Show(b);
}
  
void DoCall::Init(){
  wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(sizer);
  
  m_call = new wxButton(this, wxID_ANY, wxT("Call"));
  
  sizer->Add(m_call, 0, wxFIXED_MINSIZE, 5);
  
  // handlers
  Connect(m_call->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(DoCall::OnCall));
}

void DoCall::OnCall(wxCommandEvent &event){
  CimClient *client = CimStarter::GetInstance().GetCimClient();
  client->MakeCallTo(m_jid.BareJid().Str());
  m_call->Enable(false);
}

} //nampace cim
