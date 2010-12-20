#ifndef CHATCONTROLER_HPP_9UVATHU7
#define CHATCONTROLER_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "xmppgui/chat/ChatPanel.hpp"

#include "talk/xmpp/jid.h"

#include <wx/window.h>

#include <map>
//#include <string>

class wxNotebook;

namespace cim{
  
class ChatControler: protected wxEvtHandler{
//class ChatControler: protected wxFrame{
public:
  ChatControler();
  virtual ~ChatControler();
  
  void SetChildParent(wxWindow *parent);
  
  ChatPanel *GetChatFor(buzz::Jid jid, bool create = true);
  
  void RemoveReference(buzz::Jid jid);
  
  void NullTabs();
  wxNotebook *GetTabs();
    
protected:
  typedef std::map<std::string, ChatPanel*> ChatMap;
  ChatMap m_chat_map;
  
  wxWindow *m_parent;
  wxNotebook *m_tabs;

private:
  void OnFrameDestroy(wxCloseEvent &event);
  
};

} // namespace cim


#endif /*CHATCONTROLER_HPP_9UVATHU7*/
