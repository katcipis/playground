#include "xmppgui/chat/ChatControler.hpp"

#include "xmppgui/util/MouseEventFowarder.hpp"
#include "xmppgui/Constants.hpp"

#include <wx/notebook.h>

#include <iostream>

namespace cim{
  
class ChatControlerFrame: public wxFrame{
public:
  ChatControlerFrame(ChatControler *controler, /*const buzz::Jid jid,*/
        wxWindow* parent, wxWindowID id, const wxString& title);
  virtual ~ChatControlerFrame();
  void OnFrameDestroy(wxCloseEvent &event);
  void OnRightClick(wxMouseEvent& event);
  DECLARE_EVENT_TABLE()
protected:
  ChatControler *m_controler;
  buzz::Jid others_jid;
};

ChatControler::ChatControler(): wxEvtHandler(), m_parent(NULL), m_tabs(NULL){
}

ChatControler::~ChatControler(){
}

void ChatControler::SetChildParent(wxWindow *parent){
  m_parent = parent;
}

ChatPanel *ChatControler::GetChatFor(buzz::Jid jid, bool create){
  std::string bare(jid.BareJid().Str());
  ChatMap::iterator it = m_chat_map.find(bare);
  bool exists = (it != m_chat_map.end());
  
  if (exists){
    //////////////////////////////
    // Tabs   
    ChatPanel *chat(it->second); 
    for(int i = m_tabs->GetPageCount(); --i >= 0; )
      if (chat == m_tabs->GetPage(i)){
        // TODO: Set an image showing some kind of highlight
        //m_tabs->SetSelection(i);
        break;      
      }
    m_tabs->Refresh();
    return chat;
    // Tabs
    //////////////////////////////
    //return it->second;
  } else if (create){
    //////////////////////////////
    // Tabs
    if (!m_tabs) {
      //wxFrame *frame = new wxFrame(m_parent, wxID_ANY, StdToWx(bare));
      wxFrame *frame = new ChatControlerFrame(this, m_parent, wxID_ANY, StdToWx(bare));
      m_tabs = new wxNotebook(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN);
      m_tabs->PushEventHandler(g_mouse_event_fowarder_delayed);
 
      
      frame->SetIcon(wxIcon(wxT("imgs/icon/cim.png"), wxBITMAP_TYPE_PNG));
      frame->Show(true);
    }
    // Tabs
    //////////////////////////////


    ChatPanel *chat = new ChatPanel(m_tabs, jid);
    m_tabs->Connect(chat->GetId(), wxEVT_RIGHT_DOWN, wxMouseEventHandler(ChatControlerFrame::OnRightClick));
    
    // TODO: Set an image showing some kind of highlight 
    m_tabs->AddPage(chat, StdToWx(bare));
    
    //Connect(chat->GetId(), wxEVT_CLOSE_WINDOW, wxCloseEventHandler(ChatControler::OnFrameDestroy));
    //chat->PushEventHandler(this);
 
    m_chat_map[bare] = chat;
    m_tabs->Refresh();
    return chat;
  } else{
    return NULL;
  }
}

void ChatControler::RemoveReference(buzz::Jid jid){
  m_chat_map.erase(jid.BareJid().Str());
}

void ChatControler::NullTabs(){
  //if (m_tabs && dynamic_cast<wxFrame*>(m_tabs->GetParent()))
  //  m_tabs->GetParent()->Close();
  m_tabs = NULL;
}
wxNotebook *ChatControler::GetTabs(){
  return m_tabs;
}

void ChatControler::OnFrameDestroy(wxCloseEvent &event){
//  wxFrame *frame = dynamic_cast<wxFrame *>(event.GetEventObject());
//  if (frame){
//    //good
//    ChatPanel *panel = dynamic_cast<ChatPanel *>(*(frame->GetChildren().begin()));
//    if (panel){
//      PRU_LOG2("OnFrameDestroy", panel->GetOtherJid().Str());
//      //good
//      RemoveReference(panel->GetOtherJid());
//    } else{
//      //bad
//    }
//  } else{
//    //bad
//  }
  event.Skip();
}


BEGIN_EVENT_TABLE(ChatControlerFrame, wxFrame)
  EVT_CLOSE(ChatControlerFrame::OnFrameDestroy)
  EVT_RIGHT_DOWN(ChatControlerFrame::OnRightClick)
END_EVENT_TABLE()
ChatControlerFrame::ChatControlerFrame(ChatControler *controler,
      /*const buzz::Jid jid,*/ wxWindow* parent, wxWindowID id,
      const wxString& title): wxFrame(parent, id, title),
      m_controler(controler)/*, others_jid(jid)*/{}

ChatControlerFrame::~ChatControlerFrame(){}

void ChatControlerFrame::OnRightClick(wxMouseEvent& event){
  if (m_controler){
    wxNotebook *tabs = m_controler->GetTabs();
    if (tabs){
      int tab = tabs->HitTest(event.GetPosition());
      if (tab != wxNOT_FOUND){
        ChatPanel *chat = dynamic_cast<ChatPanel *>(tabs->GetPage(tab));
        if (chat){
          m_controler->RemoveReference(chat->GetOtherJid());
          tabs->DeletePage(tab);
        }
      }
    }
  }
}

void ChatControlerFrame::OnFrameDestroy(wxCloseEvent &event){
  //ChatPanel *chat(it->second);
  if (m_controler){
    wxNotebook *panel = dynamic_cast<wxNotebook *>(*(GetChildren().begin()));
    if (panel)
      for(int i = panel->GetPageCount(); --i >= 0; ){
        ChatPanel *chat = dynamic_cast<ChatPanel *>(panel->GetPage(i));
        if (chat)
          m_controler->RemoveReference(chat->GetOtherJid());
      }
    m_controler->NullTabs();
  }
  //ChatPanel *panel = dynamic_cast<ChatPanel *>(*(GetChildren().begin()));
  //if (panel){
  //  PRU_LOG2("OnFrameDestroy", panel->GetOtherJid().Str());
  //  //good
  //  if (m_comtroler)
  //    m_controler->RemoveReference(panel->GetOtherJid());
  //} else{
  //  //bad
  //}
  //PRU_LOG2("OnFrameDestroy", others_jid.Str());
  /*if (m_controler)
    m_controler->RemoveReference(others_jid);*/
  event.Skip();
}


} // namespace cim
