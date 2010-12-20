#include "xmppgui/Login.hpp"

#include "xmppgui/Constants.hpp"
#include "xmppgui/util/XmppEvent.hpp"

#include <wx/sizer.h>

namespace cim{

Login::Login(wxWindow* parent, wxWindowID id, const wxPoint& pos,
      const wxSize& size, long style, const wxString& name)
      : wxPanel(parent, id, pos, size, style, name){
  InitGui();
  ConnectHandlers();
}

Login::~Login() {}

wxString Login::GetLogin(){
  return m_login_name->GetLabel();
}

void Login::InitGui(){
  int l_grid_rows = 3 + 2;
  wxFlexGridSizer *main_sizer = new wxFlexGridSizer(l_grid_rows, 1, 0, 0);
  this->SetSizer(main_sizer);

  m_login_name = new wxTextCtrl(this, wxID_ANY);
  m_password = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
  m_ok_button = new wxButton(this, wxID_ANY, wxT("Loggin"));

  main_sizer->AddGrowableCol(0, 1);
  main_sizer->AddGrowableRow(0, 1);
  main_sizer->AddGrowableRow(l_grid_rows - 1, 1);

  main_sizer->AddStretchSpacer();
  main_sizer->Add(m_login_name, 0, wxEXPAND | FORM_BORDERS | wxTOP, 5);
  main_sizer->Add(m_password, 0, wxEXPAND | FORM_BORDERS, 5);
  main_sizer->Add(m_ok_button, 0, wxALIGN_CENTER | FORM_BORDERS, 5);
  main_sizer->AddStretchSpacer();

  this->SetMinSize(main_sizer->GetMinSize());

  //test
  //m_login_name->SetValue(wxT("renam.passos@gmail.com"));
  //m_password->SetValue(wxT("tu!@dova#$le"));

  m_login_name->SetValue(wxT("teste.xmppgui@gmail.com"));
  m_password->SetValue(wxT("abacateabacate"));
}

void Login::ConnectHandlers(){
  this->Connect(m_ok_button->GetId(),
    wxEVT_COMMAND_BUTTON_CLICKED,
    wxCommandEventHandler(Login::OnLoginClick)
  );
  this->Connect(-1,
    cimEVT_ChangeOwnState,
    wxNotifyEventHandler(Login::OnWxChangeOwnState)
  );
}

void Login::OnLoginClick(wxCommandEvent& event){
  m_ok_button->Enable(false);
  //------------------------
  //Aqui nao tava funcionando no linux, mas no windows sim
  //porque devia ser getValue :D
  //------------------------

//  CimStarter::GetInstance().DoLogin(m_login_name->GetLabel().utf8_str().data(),
//        m_password->GetLabel().utf8_str().data());

  CimStarter::GetInstance().DoLogin(m_login_name->GetValue().utf8_str().data(),
          m_password->GetValue().utf8_str().data());
}


void Login::OnChangeOwnState(buzz::XmppEngine::State state){
  ChangeOwnStateEvent event(cimEVT_ChangeOwnState);
  event.arg0 = state;
  AddPendingEvent(event);
}
void Login::OnWxChangeOwnState(wxNotifyEvent &event){
  ChangeOwnStateEvent *l_event = dynamic_cast<ChangeOwnStateEvent *>(&event);
  if (l_event){
    Show(!(l_event->arg0 == buzz::XmppEngine::STATE_OPEN));
    if (l_event->arg0 == buzz::XmppEngine::STATE_CLOSED){
      m_ok_button->Enable(true);
    }
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}



} //namespace cim
