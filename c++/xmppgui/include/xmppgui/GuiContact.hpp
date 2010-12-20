#ifndef GUICONTACT_HPP_9UVATHU7
#define GUICONTACT_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif


#include "talk/xmpp/jid.h"
#include "talk/examples/login/status.h"

#include <wx/panel.h>
#include <wx/stattext.h>

class wxMenu;

namespace cim{

// Let's do this foward declaration thing  
class RosterItem;

class GuiContact: public wxPanel{
public:
  GuiContact(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxT("RosterItem"));
  virtual ~GuiContact();
  
  void SetJid(buzz::Jid jid);
  void SetShow(buzz::Status::Show show);
  void SetStatus(wxString status);
  void SetVoipCap(bool b);
  void SetShareCap(bool b);
  void SetRosterItem(RosterItem &item);
  //void SetPicture();
  //void SetQuote();
  buzz::Jid GetJid();
  buzz::Status::Show& GetShow();
  wxString& GetStatus(); 
  bool GetVoipCap();
  bool GetShareCap();
  const RosterItem* GetRosterItem();
  
  
  void InitGui();
private:
  buzz::Jid m_jid;
  buzz::Status::Show m_show;
  wxString m_status;
  bool m_has_voip_cap;
  bool m_has_share_cap;
  
  RosterItem *m_roster_item;
  
  wxStaticText *m_nick;
  wxStaticText *m_avalibility;
  wxStaticBitmap *m_aval_bmp;
  wxColor m_color;
  
  wxMenu *m_menu;
  
  void UpdateMenu();
  void UpdateData();
  
  void OnLeftClick(wxCommandEvent& event);
  void OnRightClick(wxCommandEvent& event);
  void OnMenuSelect(wxCommandEvent &event);
  
  void OnMouseEnter(wxMouseEvent& event);
  void OnMouseLeave(wxMouseEvent& event);
  void OnMouseMove(wxMouseEvent& event);

};

} //namespace cim

#endif /*GUICONTACT_HPP_9UVATHU7*/
