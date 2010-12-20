#ifndef CHATPANEL_HPP_9UVATHU7
#define CHATPANEL_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "xmppgui/chat/CallPanels.hpp"
#include "xmppgui/chat/FileSharePanels.hpp"

#include "talk/xmpp/jid.h"

#include <wx/richtext/richtextctrl.h>
#include "xmppgui/chat/MousePanel.hpp"
#include "xmppgui/chat/DrawPanel.hpp"

namespace cim {

BEGIN_DECLARE_EVENT_TYPES()
  DECLARE_LOCAL_EVENT_TYPE(cimEVT_Delete_Transfer, -1)
END_DECLARE_EVENT_TYPES()
  
class ChatPanel: public wxPanel{
public:
  ChatPanel(wxWindow* parent, buzz::Jid other_jid);
  virtual ~ChatPanel();
  
  void ReceiveMsg(wxString &text);
  
  buzz::Jid GetOtherJid();
  void SetMyJid(buzz::Jid other_jid);
  
  void EnableChatPanel(bool b);
  void AddReceivedCallPanel(cricket::Call *call, cricket::Session *session);
  void AddCallInProgressPanel(cricket::Call *call, cricket::Session *session);
  void RemoveCallPanel();
  
  void EnableSharePanel(bool b);
  void AddTransfer(cricket::FileShareSession *sess, TransferBase *trans);
  void RemoveTransferFor(cricket::FileShareSession *sess);
  void DeleteTransfer(TransferBase *trans);
  void ShareOffer(cricket::FileShareSession *sess);
  void ShareCompleted(cricket::FileShareSession *sess);
  void ShareCancel(cricket::FileShareSession *sess);
  void ShareUpdateProgress(cricket::FileShareSession *sess);
  
  void AppendAlert(wxString s);
  
  void EnsureLastLineVisibility();

private:
  buzz::Jid m_other_jid;
  buzz::Jid m_my_jid;
  buzz::Jid m_last_talk;
  
  wxTextAttrEx m_original_stile;
  wxRichTextCtrl *m_chat_text;
  //wxTextCtrl *m_chat_text;
  wxTextCtrl *m_message;
  wxButton   *m_send;
  
  wxSizer *m_upper_sizer;
  
  MousePanel* m_mousePanel;
  DrawPanel* m_draw_panel;
  
  IncomingCall *m_incoming_call_pane;
  CurrentCall *m_current_call_pane;
  DoCall *m_do_call_pane;
  
  ShareFiles *m_share_files;
  
  typedef std::map<cricket::FileShareSession *, TransferBase*> TransferMap; 
  TransferMap m_transfers;
  
  void PutMessage(buzz::Jid &source, wxString &text);
  
  void InitCallPanels();
  void InitSharePanel();
  
  void OnDeleteTransfer(wxEvent &event);
  void OnEnterKeyPress(wxEvent &event);
  void OnKeyPressInWrongField(wxKeyEvent &event);
  void OnMouseMotion(wxMouseEvent &event);
  
  //void SendMsg(wxString &msg);
  
  void OnResize(wxEvent &event);
};
  
  
} //namespace cim

#endif /*CHATPANEL_HPP_9UVATHU7*/
