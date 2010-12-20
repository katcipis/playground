#ifndef FILESHAREPANELS_HPP_9UVATHU7
#define FILESHAREPANELS_HPP_9UVATHU7

#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif

#include "xmppgui/xmpp/CimStarter.hpp"

#include <wx/richtext/richtextctrl.h>

namespace cim{

// must foward declare it
class ChatPanel;
  
class ShareFiles: public wxPanel{
public:
  ShareFiles(wxWindow *parent, buzz::Jid jid);
  ~ShareFiles();
   
  void MakeVisible(bool b);
  
  void OnShare(wxCommandEvent &event);
private:
  wxButton *m_share;
  buzz::Jid m_jid;
  
  void Init();
};

class TransferBase: public wxEvtHandler{
public:
  TransferBase(ChatPanel *panel, cricket::FileShareSession *sess, wxRichTextCtrl *text_area);
  TransferBase(ChatPanel *panel, cricket::FileShareSession *sess, wxRichTextCtrl *text_area, long begin_pos,
        long end_pos, long links_begin_pos, long links_end_pos);
  
  virtual ~TransferBase() {};
  virtual void OnCancel() = 0;
protected:
  ChatPanel *m_panel; 
  cricket::FileShareSession *m_sess;
  long m_begin_pos;
  long m_end_pos;
  long m_links_begin_pos;
  long m_links_end_pos;
  
  wxRichTextCtrl *m_text_area;
  bool m_pending;
  
  wxTextAttrEx m_original_stile;
  
  long m_id;
  
  void UnistalHandler();
};

class InconingTransfer: public TransferBase{
public:
  InconingTransfer(ChatPanel *panel, wxRichTextCtrl *text_area, cricket::FileShareSession *sess);
  virtual ~InconingTransfer();
  
  void OnUrlClick(wxTextUrlEvent &event);
  void OnAccept();
  void OnReject();
  virtual void OnCancel();
protected:
  wxString m_accept_str;
  wxString m_reject_str;
  
  bool GetPath(wxString &path);
  
  void Init();
};

class CurrentTransfer: public TransferBase {
public:
  CurrentTransfer(ChatPanel *panel, wxRichTextCtrl *text_area, cricket::FileShareSession *sess,
        long begin_pos, long end_pos, long links_begin_pos, long links_end_pos);
  virtual ~CurrentTransfer();
  
  void OnUrlClick(wxTextUrlEvent &event);
  virtual void OnCancel();
  void OnComplete();
  void UpdateProgress(bool good_curr, size_t curr_transfered, bool good_total, size_t total_size);
protected:
  wxString m_cancel_str;
  
  void Init();
};  

} //namespace cim

#endif /*FILESHAREPANELS_HPP_9UVATHU7*/
