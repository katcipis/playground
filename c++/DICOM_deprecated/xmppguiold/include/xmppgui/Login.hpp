#ifndef LOGIN_HPP_9UVATHU7
#define LOGIN_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "xmppgui/xmpp/CimStarter.hpp"

#include <wx/panel.h>

namespace cim{

class Login: public wxPanel, public sigslot::has_slots<> {
public:
  Login(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxT("LoginPanel"));
  virtual ~Login();

  void InitGui();
  void ConnectHandlers();
  
  void OnLoginClick(wxCommandEvent& event);
  
  void OnChangeOwnState(buzz::XmppEngine::State state);
  
  wxString GetLogin();
    
private:
  wxTextCtrl *m_login_name;
  wxTextCtrl *m_password;
  wxButton   *m_ok_button;
  
  //void OnWxChangeOwnState(XmppEvent<buzz::XmppEngine::State> &event);
  void OnWxChangeOwnState(wxNotifyEvent &event);
};

} //namespace cim

#endif /*LOGIN_HPP_9UVATHU7*/
