#include "xmppgui/GuiContact.hpp"

#include "xmppgui/Constants.hpp"
#include "xmppgui/util/MouseEventFowarder.hpp"
#include "xmppgui/data/StateBitmaps.hpp"
#include "xmppgui/xmpp/session/roster/RosterItem.hpp"
#include "xmppgui/xmpp/CimStarter.hpp"

#include <wx/gbsizer.h>

//#include <stdlib.h>

namespace cim{

GuiContact::GuiContact(wxWindow* parent, wxWindowID id, const wxPoint& pos,
      const wxSize& size, long style, const wxString& name)
      :wxPanel(parent, id, pos, size, style, name), m_has_voip_cap(false),
      m_has_share_cap(false), m_roster_item(NULL), m_menu(NULL){
  //SetBackgroundColour(wxColour((rand() % 256), (rand() % 256), (rand() % 256)));
  //SetMinSize(wxSize(50,50));
  InitGui();
  m_color = GetBackgroundColour();
}

GuiContact::~GuiContact() {}

void GuiContact::InitGui(){
  m_nick = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
        wxDefaultSize, wxALIGN_LEFT | wxST_NO_AUTORESIZE);
  m_avalibility = new wxStaticText(this, wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT | wxST_NO_AUTORESIZE);
  m_aval_bmp = new wxStaticBitmap(this, wxID_ANY,
        StateBitmaps::GetInstance().ShowNone());
      
  wxFont font = m_avalibility->GetFont();
  font.SetWeight(wxFONTWEIGHT_LIGHT);
  font.SetPointSize(font.GetPointSize() - 1);
  m_avalibility->SetFont(font);
  
  /*
  wxGridSizer *sizer = new wxGridSizer(2, 1, 0, 0);
  this->SetSizer(sizer);
  sizer->Add(m_nick, 0, wxEXPAND);
  sizer->Add(m_avalibility, 0, wxEXPAND | wxLEFT, 10);
  */
  wxGridBagSizer *sizer = new wxGridBagSizer();
  
  this->SetSizer(sizer);
  sizer->Add(m_aval_bmp, wxGBPosition(0, 0),  wxGBSpan(1, 1));
  sizer->Add(m_nick, wxGBPosition(0, 1),  wxGBSpan(1, 1));
  sizer->Add(m_avalibility, wxGBPosition(1, 1),  wxGBSpan(1, 1));
  
  // handlers 
  // click
  Connect(wxID_ANY, wxEVT_LEFT_DOWN, wxCommandEventHandler(GuiContact::OnLeftClick));
  Connect(wxID_ANY, wxEVT_RIGHT_DOWN, wxCommandEventHandler(GuiContact::OnRightClick));
  // visual feedback
  Connect(wxID_ANY, wxEVT_ENTER_WINDOW, wxMouseEventHandler(GuiContact::OnMouseEnter));
  Connect(wxID_ANY, wxEVT_LEAVE_WINDOW, wxMouseEventHandler(GuiContact::OnMouseLeave));
  Connect(wxID_ANY, wxEVT_MOTION, wxMouseEventHandler(GuiContact::OnMouseMove));
  
  m_nick->PushEventHandler(g_mouse_event_fowarder);
  m_avalibility->PushEventHandler(g_mouse_event_fowarder);
  m_aval_bmp->PushEventHandler(g_mouse_event_fowarder);
  
      
}


void GuiContact::OnLeftClick(wxCommandEvent& event){
  wxCommandEvent my_event(wxEVT_COMMAND_BUTTON_CLICKED, GetId());
  my_event.SetEventObject(this);
  //GetEventHandler()->ProcessEvent(my_event);//throw an event
  ProcessEvent(my_event);
}

void GuiContact::OnRightClick(wxCommandEvent& event){
  PRU_LOG1("OnRightClick");
  UpdateMenu();
  if (m_menu){
    PRU_LOG1("OnRightClick");
    PopupMenu(m_menu);
  }
  PRU_LOG1("OnRightClick");
}

void GuiContact::UpdateMenu(){
  if (!m_roster_item)
    return;
  if (m_menu){
    // ugly
    delete m_menu;
    m_menu = NULL;
  }
  m_menu = new wxMenu();
  
  wxMenuItem *new_nick = new wxMenuItem(m_menu, wxNewId(), wxT("Change contact's name"));
  wxMenuItem *new_group = new wxMenuItem(m_menu, wxNewId(), wxT("Add group"));
  m_menu->Append(new_nick);
  m_menu->Append(new_group);
  
  Connect(new_nick->GetId() , wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(GuiContact::OnMenuSelect));
  Connect(new_group->GetId() , wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(GuiContact::OnMenuSelect));
  
  std::set<std::string>::const_iterator group = m_roster_item->GroupsBegin();
  std::set<std::string>::const_iterator end = m_roster_item->GroupsEnd();
  if (group != end){
    wxMenu *remove_group = new wxMenu();
    for (; group != end; ++group){
      wxMenuItem *group_menu = new wxMenuItem(remove_group, wxNewId(), StdToWx(*group));
      remove_group->Append(group_menu);
      Connect(group_menu->GetId() , wxEVT_COMMAND_MENU_SELECTED,
            wxCommandEventHandler(GuiContact::OnMenuSelect));
    }
    m_menu->AppendSubMenu(remove_group, wxT("Remove group"));
  }
}
    
//void RosterItem::SetJid() {}
//void RosterItem::SetStatus() {}
//void RosterItem::SetPicture() {}
//void RosterItem::SetQuote() {}

void GuiContact::SetVoipCap(bool b){
  if (m_has_voip_cap == b)
    return;
  m_has_voip_cap = b;
  UpdateData();
} 
bool GuiContact::GetVoipCap(){
  return m_has_voip_cap;
}

void GuiContact::SetShareCap(bool b){
  if (m_has_share_cap == b)
    return;
  m_has_share_cap = b;
  UpdateData();
}
bool GuiContact::GetShareCap(){
  return m_has_share_cap;
}

void GuiContact::SetJid(buzz::Jid jid){
  if (m_jid == jid)
    return;
  m_jid = jid;
  UpdateData();
}  
buzz::Jid GuiContact::GetJid(){
  //return m_jid;
  if (m_roster_item){
    m_jid = m_roster_item->GetJid();
  }
  return m_jid;
}

void GuiContact::SetShow(buzz::Status::Show show){
  if (m_show == show)
    return;
  m_show = show;
  UpdateData();
}
buzz::Status::Show& GuiContact::GetShow(){
  return m_show;
}

void GuiContact::SetStatus(wxString status){
  if (m_status == status)
    return;
  m_status = status;
  UpdateData();
}
wxString& GuiContact::GetStatus(){
  return m_status;
}

void GuiContact::SetRosterItem(RosterItem &item){
  m_roster_item = new RosterItem(item);
  UpdateData();
}

const RosterItem *GuiContact::GetRosterItem(){
  return m_roster_item;
}

void GuiContact::UpdateData(){
  // test, so we know it's updating
  //SetBackgroundColour(wxColour((rand() % 127)+126, (rand() % 127), (rand() % 256)));
  if (m_roster_item){
    std::string name = m_roster_item->GetName();
    if (name.empty())
      m_nick->SetLabel(StdToWx(m_roster_item->GetJid().node()));
    else
      m_nick->SetLabel(StdToWx(m_roster_item->GetName()));
  } else{
    m_nick->SetLabel(StdToWx(m_jid.node()));
  }
  
  m_avalibility->SetLabel(m_status);
  
  StateBitmaps &state_bitmaps = StateBitmaps::GetInstance();
  switch (m_show){
    case buzz::Status::SHOW_NONE: m_aval_bmp->SetBitmap(state_bitmaps.ShowNone()); break;
    case buzz::Status::SHOW_OFFLINE: m_aval_bmp->SetBitmap(state_bitmaps.ShowOffline()); break;
    case buzz::Status::SHOW_XA: m_aval_bmp->SetBitmap(state_bitmaps.ShowXa()); break;
    case buzz::Status::SHOW_AWAY: m_aval_bmp->SetBitmap(state_bitmaps.ShowAway()); break;
    case buzz::Status::SHOW_DND: m_aval_bmp->SetBitmap(state_bitmaps.ShowDnd()); break;
    case buzz::Status::SHOW_ONLINE: m_aval_bmp->SetBitmap(state_bitmaps.ShowOnline()); break;
    case buzz::Status::SHOW_CHAT: m_aval_bmp->SetBitmap(state_bitmaps.ShowChat()); break;
  }
  
  GetSizer()->Layout();  
  Refresh();
}

void GuiContact::OnMouseEnter(wxMouseEvent& event){
  // ugly way to avoid the control getting the wrong color
  if (event.GetEventType() == wxEVT_ENTER_WINDOW){
    event.SetEventType(wxEVT_MOTION);
    AddPendingEvent(event);
    event.SetEventType(wxEVT_ENTER_WINDOW);
  } else{
    static wxColour highlight(wxTheColourDatabase->Find(wxT("SKY BLUE")));
    if (m_color == GetBackgroundColour()){
      SetBackgroundColour(highlight);
      GetSizer()->Layout();
      Refresh();
    }
    event.Skip();
  }
}
void GuiContact::OnMouseLeave(wxMouseEvent& event){
  if (m_color != GetBackgroundColour()){
    SetBackgroundColour(m_color);
    GetSizer()->Layout();
    Refresh();
  }
  event.Skip();
}
void GuiContact::OnMouseMove(wxMouseEvent& event){
//  if (m_color == GetBackgroundColour())
  OnMouseEnter(event);
}

void GuiContact::OnMenuSelect(wxCommandEvent &event){
  // (event.GetEventObject() == m_menu) == true
  wxMenu *parent_menu = NULL;
  wxMenuItem *sel = m_menu->FindItem(event.GetId(), &parent_menu); 
  if (sel){
    wxString text = sel->GetLabel();
    
    if (parent_menu && (parent_menu != m_menu)){
      RosterItem item(*m_roster_item);
      item.RemoveGroup(WxToStd(text));
      CimStarter::SCimClient()->UpdateRosterItem(item);
    } else{
      //wxT("Change contact's name")
      //wxT("Add group")
      if (text == wxT("Change contact's name")){
        wxString name;
        if (m_roster_item)
          name = StdToWx(m_roster_item->GetName());
        name = name.Trim();
        wxTextEntryDialog diag(this, wxT("New nick to use"), wxEmptyString, name);
        if (diag.ShowModal() == wxID_OK){
          RosterItem item(*m_roster_item);
          if (item.SetName(WxToStd(diag.GetValue())))
            CimStarter::SCimClient()->UpdateRosterItem(item);
        }
      } else if (text == wxT("Add group")){
        wxTextEntryDialog diag(this, wxT("Group"), wxEmptyString);
        if (diag.ShowModal() == wxID_OK){
          RosterItem item(*m_roster_item);
          if (item.AddGroup(WxToStd(diag.GetValue())))
            CimStarter::SCimClient()->UpdateRosterItem(item);
        }
      } else{
        PRU_LOG2("OnMenuSelect", "else??");
      }
    }
  }
}

} //namespace cim
