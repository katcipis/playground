#include "xmppgui/PresenceList.hpp"

#include "xmppgui/Constants.hpp"
#include "xmppgui/util/XmppEvent.hpp"
#include "xmppgui/util/MouseEventFowarder.hpp"
#include "xmppgui/data/StateBitmaps.hpp"
#include "xmppgui/xmpp/session/roster/RosterItem.hpp"

//#include <wx/sizer.h>
#include <wx/gbsizer.h>

#include <iostream>



namespace cim{
  



  

PresenceList::PresenceList(wxWindow* parent)
      : wxPanel(parent){
  m_chat_controler.SetChildParent(parent);
  InitGui();
  // handlers
  Connect(-1, cimEVT_CallEnd,
        wxNotifyEventHandler(PresenceList::OnWxCallEnd));
  Connect(-1, cimEVT_ChangeOwnState,
        wxNotifyEventHandler(PresenceList::OnWxChangeOwnState));
  Connect(-1, cimEVT_CallState,
        wxNotifyEventHandler(PresenceList::OnWxCallState));
  Connect(-1, cimEVT_Calling,
        wxNotifyEventHandler(PresenceList::OnWxCalling));
  Connect(-1, cimEVT_InconingMessage,
        wxNotifyEventHandler(PresenceList::OnWxInconingMessage));
  Connect(-1, cimEVT_ChangeRosterStatus,
        wxNotifyEventHandler(PresenceList::OnWxChangeRosterStatus));
  Connect(-1, cimEVT_ChangeRosterData,
        wxNotifyEventHandler(PresenceList::OnWxChangeRosterData));
  
  
  Connect(-1, cimEVT_FileSessionState,
        wxNotifyEventHandler(PresenceList::OnWxFileSessionState));
  Connect(-1, cimEVT_FileUpdateProgress,
        wxNotifyEventHandler(PresenceList::OnWxFileUpdateProgress));
  Connect(-1, cimEVT_FileShareCreate,
        wxNotifyEventHandler(PresenceList::OnWxFileShareCreate));
} //LoginPanel

PresenceList::~PresenceList() {}

void PresenceList::SetMyJid(buzz::Jid jid){
  m_jid = jid;
  UpdateUpperPane();
}

buzz::Jid PresenceList::GetMyJid(){
  return m_jid;
}

void PresenceList::InitGui(){
  int l_grid_rows = 3;
  wxBoxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);
  SetSizer(main_sizer);
  
  m_upper_pane = new wxPanel(this);
  m_lower_pane = new wxPanel(this);
  m_contact_list = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition,
        wxDefaultSize, wxVSCROLL);
  m_contact_list->SetSizer(new wxBoxSizer(wxVERTICAL));
  m_contact_list->SetMinSize(wxSize(10, 200));
  
  main_sizer->Add(m_upper_pane, 0, wxEXPAND | FORM_BORDERS | wxTOP, 5);
  main_sizer->Add(m_contact_list, 1, wxEXPAND | FORM_BORDERS, 5);
  main_sizer->Add(m_lower_pane, 0, wxEXPAND | FORM_BORDERS, 5);
  
  
  InitUpperPane();
  InitStateMenu();
  
  SetMinSize(main_sizer->GetMinSize());
  
  Show(false); 
}

void PresenceList::InitUpperPane(){
  wxGridBagSizer *sizer = new wxGridBagSizer();
  m_upper_pane->SetSizer(sizer);
  sizer->AddGrowableCol(1);

  m_own_state = new wxStaticBitmap(m_upper_pane, wxID_ANY,
        StateBitmaps::GetInstance().ShowNone());
  m_own_name = new wxStaticText(m_upper_pane, wxID_ANY, wxEmptyString);
  //m_own_quote = new wxTextCtrl(m_upper_pane, wxID_ANY, wxEmptyString,
  //      wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
  
  sizer->Add(m_own_state, wxGBPosition(0, 0), wxGBSpan(1, 1));
  sizer->Add(m_own_name, wxGBPosition(0, 1), wxGBSpan(1, 1));
  //sizer->Add(m_own_quote, wxGBPosition(1, 1), wxGBSpan(1, 1));
  
  // Handlers
  //Connect(m_own_quote->GetId(), wxEVT_COMMAND_KILL_FOCUS,
  //      wxEventHandler(PresenceList::OnOwnQuoteExit));
  Connect(m_own_state->GetId(), wxEVT_LEFT_DOWN,
        wxEventHandler(PresenceList::OnOwnStateClick));
  Connect(m_own_state->GetId(), wxEVT_RIGHT_DOWN,
        wxEventHandler(PresenceList::OnOwnStateClick));

  m_own_state->PushEventHandler(g_mouse_event_fowarder);
  m_upper_pane->PushEventHandler(g_mouse_event_fowarder);
}

void PresenceList::InitStateMenu(){
  m_state_menu = new wxMenu();
  //wxMenuItem show_none(menu, wxID_ANY, wxT("None"));
  //wxMenuItem *show_offline = new wxMenuItem(m_state_menu, wxNewId(), wxT("Offline"));
  wxMenuItem *show_xa = new wxMenuItem(m_state_menu, wxNewId(), wxT("XA"));
  wxMenuItem *show_away = new wxMenuItem(m_state_menu, wxNewId(), wxT("Away"));
  wxMenuItem *show_dnd = new wxMenuItem(m_state_menu, wxNewId(), wxT("DND"));
  wxMenuItem *show_online = new wxMenuItem(m_state_menu, wxNewId(), wxT("Online"));
  wxMenuItem *show_chat = new wxMenuItem(m_state_menu, wxNewId(), wxT("Chat"));
  
  StateBitmaps &sb = StateBitmaps::GetInstance();
  //show_none.SetBitmap(sb.ShowNone());
  //show_offline->SetBitmap(sb.ShowOffline());
  show_xa->SetBitmap(sb.ShowXa());
  show_away->SetBitmap(sb.ShowAway());
  show_dnd->SetBitmap(sb.ShowDnd());
  show_online->SetBitmap(sb.ShowOnline());
  show_chat->SetBitmap(sb.ShowChat());
  
  //m_state_menu->Append(show_offline);
  m_state_menu->Append(show_xa);
  m_state_menu->Append(show_away);
  m_state_menu->Append(show_dnd);
  m_state_menu->Append(show_online);
  m_state_menu->Append(show_chat);
  
  // Handlers
  //Connect(show_offline->GetId(), wxEVT_COMMAND_MENU_SELECTED,
  //      wxCommandEventHandler(PresenceList::OnStateMenuSelect));
  Connect(show_xa->GetId(), wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(PresenceList::OnStateMenuSelect));
  Connect(show_away->GetId(), wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(PresenceList::OnStateMenuSelect));
  Connect(show_dnd->GetId(), wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(PresenceList::OnStateMenuSelect));
  Connect(show_online->GetId(), wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(PresenceList::OnStateMenuSelect));
  Connect(show_chat->GetId(), wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(PresenceList::OnStateMenuSelect));
}

void PresenceList::OnStateMenuSelect(wxCommandEvent &event){
  // (event.GetEventObject() == m_state_menu) == true
  wxMenuItem *sel = m_state_menu->FindItem(event.GetId()); 
  if (sel){
    wxString text = sel->GetLabel();
    
    buzz::Status::Show show = buzz::Status::SHOW_NONE;
    if (text == wxT("None")){
      PRU_LOG2("OnStateMenuSelect", "None??");
    } else if (text == wxT("Offline")){
      show = buzz::Status::SHOW_OFFLINE;
    } else if (text == wxT("XA")){
      show = buzz::Status::SHOW_XA;
    } else if (text == wxT("Away")){
      show = buzz::Status::SHOW_AWAY;
    } else if (text == wxT("DND")){
      show = buzz::Status::SHOW_DND;
    } else if (text == wxT("Online")){
      show = buzz::Status::SHOW_ONLINE;
      //show = buzz::Status::SHOW_NONE;
    } else if (text == wxT("Chat")){
      show = buzz::Status::SHOW_CHAT;
    } else{
      PRU_LOG2("OnStateMenuSelect", "else??");
    }
    if (m_state == show)
      return;
    m_state = show;
    UpdateOwnStateImage();
    
    CimStarter::SCimClient()->SendState(show, WxToStd(m_quote));
  }
}

void PresenceList::UpdateOwnStateImage(){
  StateBitmaps &state_bitmaps = StateBitmaps::GetInstance();
  switch (m_state){
    //case buzz::Status::SHOW_NONE: m_own_state->SetBitmap(state_bitmaps.ShowNone()); break;
    case buzz::Status::SHOW_OFFLINE: m_own_state->SetBitmap(state_bitmaps.ShowOffline()); break;
    case buzz::Status::SHOW_XA: m_own_state->SetBitmap(state_bitmaps.ShowXa()); break;
    case buzz::Status::SHOW_AWAY: m_own_state->SetBitmap(state_bitmaps.ShowAway()); break;
    case buzz::Status::SHOW_DND: m_own_state->SetBitmap(state_bitmaps.ShowDnd()); break;
    case buzz::Status::SHOW_NONE: // I actualy hope this does not work
    case buzz::Status::SHOW_ONLINE: m_own_state->SetBitmap(state_bitmaps.ShowOnline()); break;
    case buzz::Status::SHOW_CHAT: m_own_state->SetBitmap(state_bitmaps.ShowChat()); break;
  }
  m_upper_pane->GetSizer()->Layout();
}

void PresenceList::UpdateUpperPane(){
  m_own_name->SetLabel(StdToWx(m_jid.node()));
  //m_own_state->SetBitmap(StateBitmaps::GetInstance().ShowOnline());
  
  m_upper_pane->GetSizer()->Layout();
  m_upper_pane->Refresh();
}

void PresenceList::OnOwnStateClick(wxEvent &event){
  m_own_state->PopupMenu(m_state_menu, 0, m_own_state->GetSize().GetHeight());
}
void PresenceList::OnOwnQuoteExit(wxEvent &event){
  PRU_LOG1("OnOwnQuoteExit");
  //why? how?
}

bool PresenceList::AddContact(GuiContact *item){
  if ((item == NULL) || (m_contact_list->GetChildren().Find(item) != NULL))
    return false;
  item->Reparent(m_contact_list);
  m_contact_list->GetSizer()->Add(item, 0, wxEXPAND);
  //this->SetMinSize(this->GetSizer()->GetMinSize());

  // Ensure proper scrolling
  int entry_height = item->GetSize().GetHeight();
  m_contact_list->SetScrollbars( 0, entry_height,
    0, //item->GetMinSize().GetWidth(),
    entry_height
  );
  
  // handlers
  Connect(item->GetId(),
    wxEVT_COMMAND_BUTTON_CLICKED,
    wxCommandEventHandler(PresenceList::OnContactCick)
  );
 
  return true;
}

void PresenceList::OnContactCick(wxCommandEvent& event){
  GuiContact *contact = dynamic_cast<GuiContact *>(event.GetEventObject());
  if (contact){
    ChatPanel *chat = m_chat_controler.GetChatFor(contact->GetJid());
    chat->SetMyJid(m_jid);
    chat->EnableChatPanel(contact->GetVoipCap());
    chat->EnableSharePanel(contact->GetShareCap());
  }
}

//bool PresenceList::RemoveContact(const buzz::Jid &item) { return false; }

//void PresenceList::OnStatusUpdate(const buzz::Status& status){
//  wxString key = status.jid().BareJid().Str().c_str();
//  
//  GuiContact *item = NULL;
//  item = m_roster.find(key)->second;
//  if (item == NULL)
//    item = new GuiContact(this);
//  
//  item->SetJid(status.jid());
//  item->SetShow(status.show());
//  item->SetStatus(status.status());
//}

// the call
void PresenceList::OnCallEnd(cricket::Call *call){
  PRU_LOG1("OnCallEnd");
  
  CallEndEvent event(cimEVT_CallEnd);
  event.arg0 = call;
  AddPendingEvent(event);
}

// the new state
void PresenceList::OnChangeOwnState(buzz::XmppEngine::State state){
  PRU_LOG1("OnChangeOwnState");
  
  ChangeOwnStateEvent event(cimEVT_ChangeOwnState);
  event.arg0 = state;
  AddPendingEvent(event);
}

// the call, session, the call's state
void PresenceList::OnCallState(cricket::Call *call, cricket::Session *session,
      cricket::Session::State state){
  PRU_LOG1("OnCallState");
  
  CallStateEvent event(cimEVT_CallState);
  event.arg0 = call;
  event.arg1 = session;
  event.arg2 = state;
  AddPendingEvent(event);
}

// other side jid, found, has calling capabilities 
void PresenceList::OnCalling(buzz::Jid jid, bool found, bool cap){
  PRU_LOG1("OnCalling");
  
  CallingEvent event(cimEVT_Calling);
  event.arg0 = jid;
  event.arg1 = found;
  event.arg2 = cap;
  AddPendingEvent(event);
}

void PresenceList::OnInconingMessage(buzz::Jid jid, std::string msg){
  PRU_LOG1("OnInconingMessage");
  
  InconingMessageEvent event(cimEVT_InconingMessage);
  event.arg0 = jid;
  event.arg1 = msg;
  AddPendingEvent(event);
}

void PresenceList::OnChangeRosterStatus(buzz::Status status){
  PRU_LOG1("OnChangeRosterStatus");
  
  ChangeRosterStatusEvent event(cimEVT_ChangeRosterStatus);
  event.arg0 = status;
  AddPendingEvent(event);
}

void PresenceList::OnChangeRosterData(RosterItem &item){
  PRU_LOG1("OnChangeRosterData");
  
  ChangeRosterDataEvent event(cimEVT_ChangeRosterData);
  event.arg0 = item;
  AddPendingEvent(event);
}

void PresenceList::OnFileSessionState(cricket::FileShareSession *sess, cricket::FileShareState state){
  PRU_LOG1("OnFileSessionState");
  
  FileSessionStateEvent event(cimEVT_FileSessionState);
  event.arg0 = sess;
  event.arg1 = state;
  AddPendingEvent(event);
}

void PresenceList::OnFileUpdateProgress(cricket::FileShareSession *sess){
  PRU_LOG1("OnFileUpdateProgress");
  
  FileShareSessionEvent event(cimEVT_FileUpdateProgress);
  event.arg0 = sess;
  AddPendingEvent(event);
}

void PresenceList::OnFileShareCreate(cricket::FileShareSession *sess){
  PRU_LOG1("OnFileShareCreate");
  
  FileShareSessionEvent event(cimEVT_FileShareCreate);
  event.arg0 = sess;
  AddPendingEvent(event);
}


// the call
//void PresenceList::OnWxCallEnd(XmppEvent<cricket::Call *> &event){
void PresenceList::OnWxCallEnd(wxNotifyEvent &event){
  PRU_LOG1("OnWxCallEnd");
  CallEndEvent *l_event = dynamic_cast<CallEndEvent *>(&event);
  if (l_event){
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}

// the new state
//void PresenceList::OnWxChangeOwnState(XmppEvent<buzz::XmppEngine::State> &event){
void PresenceList::OnWxChangeOwnState(wxNotifyEvent &event){
  PRU_LOG1("OnWxChangeOwnState");
  ChangeOwnStateEvent *l_event = dynamic_cast<ChangeOwnStateEvent *>(&event);
  if (l_event){
    if (l_event->arg0 == buzz::XmppEngine::STATE_OPEN){
      Show(true);
      m_state = buzz::Status::SHOW_ONLINE;
      UpdateOwnStateImage();
    } else{
      Show(false);
    }
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
  PRU_LOG1("OnWxChangeOwnState");
}

// the call, session, the call's state
//void PresenceList::OnWxCallState(XmppEvent<cricket::Call *, cricket::Session *, cricket::Session::State> &event){
void PresenceList::OnWxCallState(wxNotifyEvent &event){
  PRU_LOG1("OnWxCallState");
  CallStateEvent *l_event = dynamic_cast<CallStateEvent *>(&event);
  if (l_event){
    cricket::Call *call = l_event->arg0;
    cricket::Session *session = l_event->arg1;
    cricket::Session::State state = l_event->arg2;
    std::string name = session->remote_name();
    switch (state){
      case cricket::Session::STATE_RECEIVEDINITIATE:{
        ChatPanel *chat = m_chat_controler.GetChatFor(buzz::Jid(name));
        chat->AddReceivedCallPanel(call, session);
      } break;
      case cricket::Session::STATE_SENTINITIATE:
      case cricket::Session::STATE_SENTACCEPT:
      case cricket::Session::STATE_RECEIVEDACCEPT:
      case cricket::Session::STATE_INPROGRESS:{
        ChatPanel *chat = m_chat_controler.GetChatFor(buzz::Jid(name));
        chat->AddCallInProgressPanel(call, session);
      } break;
      case cricket::Session::STATE_SENTTERMINATE:
      case cricket::Session::STATE_RECEIVEDTERMINATE:{
        ChatPanel *chat = m_chat_controler.GetChatFor(buzz::Jid(name), false);
        if (chat)
          chat->RemoveCallPanel();
      } break;
    }
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}

// other side jid, found, has calling capabilities 
//void PresenceList::OnWxCalling(XmppEvent<buzz::Jid, bool, bool> &event){
void PresenceList::OnWxCalling(wxNotifyEvent &event){
  CallingEvent *l_event = dynamic_cast<CallingEvent *>(&event);
  if (l_event){
    if (!l_event->arg1){
      ChatPanel *chat = m_chat_controler.GetChatFor(l_event->arg0);
      chat->AppendAlert(wxT("Can not call: Jid not found"));
    } else{
      if (!l_event->arg2){
        ChatPanel *chat = m_chat_controler.GetChatFor(l_event->arg0);
        chat->AppendAlert(wxT("Can not call: No calling capability"));
      }
    }
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}

//void PresenceList::OnWxInconingMessage(XmppEvent<buzz::Jid, std::string> &event){
void PresenceList::OnWxInconingMessage(wxNotifyEvent &event){
  PRU_LOG1("OnWxInconingMessage");
  InconingMessageEvent *l_event = dynamic_cast<InconingMessageEvent *>(&event);
  if (l_event){
    wxString msg(StdToWx(l_event->arg1));
    ChatPanel *chat = m_chat_controler.GetChatFor(l_event->arg0);
    chat->SetMyJid(m_jid);
    chat->ReceiveMsg(msg);
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}

//void PresenceList::OnWxChangeRosterStatus(XmppEvent<buzz::Status> &event){
void PresenceList::OnWxChangeRosterStatus(wxNotifyEvent &event){
  PRU_LOG1("OnWxChangeRosterStatus");
  ChangeRosterStatusEvent *l_event = dynamic_cast<ChangeRosterStatusEvent *>(&event);
  if (l_event){
    buzz::Status status = l_event->arg0;
    buzz::Jid jid = status.jid();
    // Our selves? Ignore this thing!
    if (jid.BareEquals(m_jid))
      return;
    wxString index(StdToWx(jid.BareJid().Str()));
    GuiContact *contact = m_roster[index];
    if (contact == NULL){
      contact = new GuiContact(this);
      m_roster[index] = contact;
    }
    AddContact(contact);
    
    if (status.know_capabilities()){
      contact->SetVoipCap(status.phone_capability());
      contact->SetShareCap(status.fileshare_capability());
    }
    
    contact->SetJid(status.jid());
    contact->SetShow(status.show());
    contact->SetStatus(wxString::FromUTF8(status.status().c_str()));
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}

//void PresenceList::OnWxChangeRosterData(XmppEvent<RosteItem> &event){
void PresenceList::OnWxChangeRosterData(wxNotifyEvent &event){
  PRU_LOG1("OnWxChangeRosterData");
  ChangeRosterDataEvent *l_event = dynamic_cast<ChangeRosterDataEvent *>(&event);
  if (l_event){
    RosterItem &item = l_event->arg0;
    buzz::Jid jid = item.GetJid();
    // Our selves? Ignore this thing!
    if (jid.BareEquals(m_jid))
      return;
    wxString index(StdToWx(jid.BareJid().Str()));
    GuiContact *contact = m_roster[index];
    if (contact == NULL){
      contact = new GuiContact(this);
      m_roster[index] = contact;
    }
    AddContact(contact);
    
  PRU_LOG1("OnWxChangeRosterData");
    contact->SetRosterItem(item);   
    //contact->SetJid(status.jid());
    
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}
  
//void PresenceList::OnWxFileSessionState(XmppEvent<cricket::FileShareSession *sess, cricket::FileShareState state>){
void PresenceList::OnWxFileSessionState(wxNotifyEvent &event){
  PRU_LOG1("OnWxFileSessionState");
  FileSessionStateEvent *l_event = dynamic_cast<FileSessionStateEvent *>(&event);
  if (l_event){
    cricket::FileShareSession *sess = l_event->arg0;
    const buzz::Jid &jid = sess->jid();
    switch (l_event->arg1){//Offer extended
      case cricket::FS_OFFER:{
        ChatPanel *chat = m_chat_controler.GetChatFor(jid);
        chat->ShareOffer(sess);
      } break;
      case cricket::FS_TRANSFER:{// In progress
        PRU_LOG1("FS_TRANSFER");
      } break;
      case cricket::FS_COMPLETE:{// Completed successfully
        ChatPanel *chat = m_chat_controler.GetChatFor(jid, false);
        if (chat)
          chat->ShareCompleted(sess);
      } break;
      case cricket::FS_LOCAL_CANCEL:// Local side cancelled
      case cricket::FS_REMOTE_CANCEL:{// Remote side cancelled
        ChatPanel *chat = m_chat_controler.GetChatFor(jid, false);
        if (chat)
          chat->ShareCancel(sess);
      } break;
      case cricket::FS_FAILURE:{// An error occurred during transfer
      } break;
    }
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}
//void PresenceList::OnWxFileUpdateProgress(XmppEvent<cricket::FileShareSession *>){
void PresenceList::OnWxFileUpdateProgress(wxNotifyEvent &event){
  PRU_LOG1("OnWxFileUpdateProgress");
  FileShareSessionEvent *l_event = dynamic_cast<FileShareSessionEvent *>(&event);
  if (l_event){
    cricket::FileShareSession *sess = l_event->arg0;
    const buzz::Jid &jid = sess->jid();
    ChatPanel *chat = m_chat_controler.GetChatFor(jid, false);
    if (chat)
      chat->ShareUpdateProgress(sess);   
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}
//void OnWxFileShareCreate(XmppEvent<cricket::FileShareSession *>){
void PresenceList::OnWxFileShareCreate(wxNotifyEvent &event){
  PRU_LOG1("OnWxFileShareCreate, just returning");
  //Do nothing. Realy! FileShareSession does not have a manifest at this point :(
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  return;
  
  FileShareSessionEvent *l_event = dynamic_cast<FileShareSessionEvent *>(&event);
  if (l_event){
    cricket::FileShareSession *sess = l_event->arg0;
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
}
  
} //namespace cim
