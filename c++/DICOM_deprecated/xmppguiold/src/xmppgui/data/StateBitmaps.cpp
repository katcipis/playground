#include "xmppgui/data/StateBitmaps.hpp"  
  

namespace cim{  
  
StateBitmaps::StateBitmaps(){
  m_show_offline = wxBitmap(wxT("imgs/state/SHOW_OFFLINE.PNG"), wxBITMAP_TYPE_PNG);
  m_show_xa = wxBitmap(wxT("imgs/state/SHOW_XA.PNG"), wxBITMAP_TYPE_PNG);
  m_show_away = wxBitmap(wxT("imgs/state/SHOW_AWAY.PNG"), wxBITMAP_TYPE_PNG);
  m_show_dnd = wxBitmap(wxT("imgs/state/SHOW_DND.PNG"), wxBITMAP_TYPE_PNG);
  m_show_online = wxBitmap(wxT("imgs/state/SHOW_ONLINE.PNG"), wxBITMAP_TYPE_PNG);
  m_show_chat = wxBitmap(wxT("imgs/state/SHOW_CHAT.PNG"), wxBITMAP_TYPE_PNG);
  m_show_none = m_show_offline;
}
StateBitmaps::~StateBitmaps(){
}

StateBitmaps &StateBitmaps::GetInstance(){
  static StateBitmaps my_instance;
  return my_instance;
}
  
wxBitmap &StateBitmaps::ShowNone(){
  return m_show_none;
}
wxBitmap &StateBitmaps::ShowOffline(){
  return m_show_offline;
}
wxBitmap &StateBitmaps::ShowXa(){
  return m_show_xa;
}
wxBitmap &StateBitmaps::ShowAway(){
  return m_show_away;
}
wxBitmap &StateBitmaps::ShowDnd(){
  return m_show_dnd;
}
wxBitmap &StateBitmaps::ShowOnline(){
  return m_show_online;
}
wxBitmap &StateBitmaps::ShowChat(){
  return m_show_chat;
}
  
}
