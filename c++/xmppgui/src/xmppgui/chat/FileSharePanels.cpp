#include "xmppgui/chat/FileSharePanels.hpp"

#include "xmppgui/chat/ChatPanel.hpp"
#include "xmppgui/Constants.hpp"

#include <wx/filedlg.h>
#include <wx/filename.h>

#include <stack>


namespace cim{
  
// Helper functions
wxString Bytes2String(size_t bytes){
  wxString val;
  if (bytes < 1000) {
    val << bytes << wxT(" Bytes");
  } else if (bytes < 1000 * 1024) {
    val << (double)bytes / 1024.0 << wxT(" KB");
  } else if (bytes < 1000 * 1024 * 1024) {
    val << (double)bytes / (1024.0 * 1024.0) << wxT(" MB");
  } else {
    val << (double)bytes / (1024.0 * 1024.0 * 1024.0) << wxT(" GB");
  }
  return val;
}

  
static wxString text_tab(wxT("    "));

///////////////////////////////////////
// ShareFiles
///////////////////////////////////////
ShareFiles::ShareFiles(wxWindow *parent, buzz::Jid jid): wxPanel(parent), m_jid(jid){
  Init();
}
ShareFiles::~ShareFiles(){
}
 
void ShareFiles::Init(){
  wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(sizer);
  
  m_share = new wxButton(this, wxID_ANY, wxT("Send Files"));
  
  sizer->Add(m_share, 0, wxFIXED_MINSIZE, 5);
  
  // handlers
  Connect(m_share->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(ShareFiles::OnShare));
}
  
void ShareFiles::MakeVisible(bool b){
  m_share->Enable(b);
  Show(b);
}
  
void ShareFiles::OnShare(wxCommandEvent &event){
  wxFileDialog file(GetParent(), wxT("Choose the files"), wxT(""), wxT(""), wxT("*.*"),
        wxFD_DEFAULT_STYLE | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE);
  if (file.ShowModal() == wxID_OK){
    wxArrayString paths;
    wxArrayString names;;
    file.GetPaths(paths);
    file.GetFilenames(names);
    size_t elements = names.GetCount(); 
    if (elements > 0){
      cricket::FileShareManifest *manifest = new cricket::FileShareManifest();
      for (int i = 0; i < elements; i++){
        wxFileName fname(paths[i]);
        wxULongLong file_size = fname.GetSize();
        manifest->AddFile(names[i].utf8_str().data(), file_size.GetValue());
      }
      CimStarter::SCimClient()->MakeShare(m_jid.Str(), manifest,
            wxFileName(paths[0]).GetPath().utf8_str().data());
      PRU_LOG1(manifest);
    }
  }
}

///////////////////////////////////////
// TransferBase
///////////////////////////////////////
TransferBase::TransferBase(ChatPanel *panel, cricket::FileShareSession *sess,
      wxRichTextCtrl *text_area): m_panel(panel), m_sess(sess), m_text_area(text_area),
      m_id(wxNewId()), m_pending(true), m_original_stile(text_area->GetDefaultStyleEx()){
}
TransferBase::TransferBase(ChatPanel *panel, cricket::FileShareSession *sess,
      wxRichTextCtrl *text_area, long begin_pos, long end_pos, long links_begin_pos,
      long links_end_pos): m_panel(panel), m_sess(sess), m_text_area(text_area),
      m_id(wxNewId()), m_pending(true), m_original_stile(text_area->GetDefaultStyleEx()),
      m_begin_pos(begin_pos), m_end_pos(end_pos), m_links_begin_pos(links_begin_pos),
      m_links_end_pos(links_end_pos){
}

void TransferBase::UnistalHandler(){
  m_text_area->RemoveEventHandler(this);
  /*
  wxEvtHandler *temp;
  std::stack<wxEvtHandler*> handlers;
  temp = m_text_area->PopEventHandler();
  while (temp){
    if (temp != this){
      handlers.push(temp);
      temp = m_text_area->PopEventHandler();
    } else{
      break;
    }
  }
  while (!handlers.empty()){
    m_text_area->PushEventHandler(handlers.top());
    handlers.pop();
  }
  */
}
///////////////////////////////////////
// InconingTransfer
///////////////////////////////////////
InconingTransfer::InconingTransfer(ChatPanel *panel, wxRichTextCtrl *text_area,
      cricket::FileShareSession *sess): TransferBase(panel, sess, text_area){     
  Init();
  panel->AddTransfer(sess, this);
  m_text_area->PushEventHandler(this);
  if (sess){
    if (!(sess->is_sender()))
      Connect(m_text_area->GetId(), wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler(InconingTransfer::OnUrlClick));
    else
      OnAccept();
  }
}
InconingTransfer::~InconingTransfer(){
}

void InconingTransfer::Init(){
  //m_text_area->Delete(wxRichTextRange(m_begin_pos, m_end_pos));
  //m_text_area->SetInsertionPoint(m_begin_pos);
  bool outgoing = m_sess && (m_sess->is_sender());
  m_text_area->SetDefaultStyle(m_original_stile);
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
  
  m_begin_pos = m_text_area->GetInsertionPoint();
  
  
  m_text_area->WriteText(text_tab);
  m_text_area->BeginBold();
  if (outgoing){
    m_text_area->WriteText(wxT("Outgoing transfer: "));
  } else{
    m_text_area->WriteText(wxT("Incoming transfer: "));
  }
  m_text_area->EndBold();
  
  // read the manifest
  const cricket::FileShareManifest *manifest = m_sess->manifest();
  if (manifest){
    std::stringstream buff;
    int size = manifest->size();
    //if (size > 0){
    //  buff << "\"";
    //  buff << manifest->item(0).name;
    //  buff << "\"";
    //}
    for (int i = 0; i < size; i++){
      //buff << " ";
      buff << "\"";
      buff << manifest->item(i).name;
      buff << "\"";
      buff << " ";
    }
    m_text_area->WriteText(wxString::FromUTF8(buff.str().c_str()));
  } else{
    m_text_area->WriteText(wxT(" No files?"));
  }
  m_text_area->Newline();
  
  // the options
  m_links_begin_pos = m_text_area->GetInsertionPoint();
  
  m_accept_str = wxString::Format(wxT("%x-%x#Accept"), m_id, this);
  m_reject_str = wxString::Format(wxT("%x-%x#Reject"), m_id, this);
  
  m_text_area->WriteText(text_tab);
  
  m_text_area->BeginURL(m_accept_str);
  m_text_area->BeginUnderline();
  m_text_area->BeginTextColour(*wxBLUE);
  m_text_area->WriteText(wxT("Accept"));
  m_text_area->EndTextColour();
  m_text_area->EndUnderline();
  m_text_area->EndURL();
  
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  
  m_text_area->BeginURL(m_reject_str);
  m_text_area->BeginUnderline();
  m_text_area->BeginTextColour(*wxBLUE);
  m_text_area->WriteText(wxT("Decline"));
  m_text_area->EndTextColour();
  m_text_area->EndUnderline();
  m_text_area->EndURL();
  
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(text_tab);
  
  m_links_end_pos = m_text_area->GetInsertionPoint();
  
  m_text_area->Newline();
  
  m_end_pos = m_text_area->GetInsertionPoint();
  //m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
}

void InconingTransfer::OnUrlClick(wxTextUrlEvent &event){
  wxString text = event.GetString();
  if (m_pending){
    if (text == m_accept_str){
      m_pending = false;
      OnAccept();
    } else if (text == m_reject_str){
      m_pending = false;
      OnReject();
    } else{
      //PRU_LOG("InconingTransfer::OnUrlClick - None");
    }
  }
  event.Skip();
}

void InconingTransfer::OnAccept(){
  PRU_LOG1("InconingTransfer::OnAccept");
  m_text_area->SetDefaultStyle(m_original_stile);
  // the new text MUST have the same size or others will suffer for your fault 
  // let's accept after updating the gui
  bool incoming = m_sess && !(m_sess->is_sender());
  
  if (incoming){
    wxString path(wxT("."));
    if (!GetPath(path)){
      m_pending = true;
      return;
    }
    m_sess->SetLocalFolder(path.utf8_str().data());
  }
  UnistalHandler();
  
  CurrentTransfer *transfer = new CurrentTransfer(m_panel, m_text_area, m_sess, m_begin_pos,
        m_end_pos, m_links_begin_pos, m_links_end_pos);
  m_panel->AddTransfer(m_sess, transfer);
  
  // let's accept after updating the gui
  if (m_sess){
    if (incoming)
      CimStarter::GetInstance().GetCimClient()->AcceptShare(m_sess);
  } else{
    PRU_LOG1("InconingTransfer::OnAccept m_sess == NULL");
  }
}

void InconingTransfer::OnReject(){
  PRU_LOG1("InconingTransfer::OnReject");
  m_text_area->SetDefaultStyle(m_original_stile);
  // the new text MUST have the same size or others will suffer for your fault
  // let's decline after updating the gui

  wxString new_text(text_tab + wxT("Declined"));
  wxString dummy(wxChar(' '), m_links_end_pos - (m_links_begin_pos + new_text.Len()));
  new_text << dummy;
  
  m_text_area->Delete(wxRichTextRange(m_links_begin_pos, m_links_end_pos));
  m_text_area->SetInsertionPoint(m_links_begin_pos);
  //ASSERT(new_text.Len() == (m_links_begin_pos - m_links_end_pos) );
  m_text_area->WriteText(new_text);
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
  
  UnistalHandler();
  m_panel->RemoveTransferFor(m_sess);
  
  // let's decline after updating the gui
  if (m_sess)
    CimStarter::GetInstance().GetCimClient()->RejectShare(m_sess);
  else
    PRU_LOG1("InconingTransfer::OnReject m_sess == NULL");
}

void InconingTransfer::OnCancel(){
  m_text_area->SetDefaultStyle(m_original_stile);
  
  m_text_area->Delete(wxRichTextRange(m_links_begin_pos, m_links_end_pos));
  m_text_area->SetInsertionPoint(m_links_begin_pos);
  //ASSERT(new_text.Len() == (m_links_begin_pos - m_links_end_pos) );
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(wxT("Canceled"));
  
  //ASSERT(m_links_end_pos >= m_text_area->GetInsertionPoint());
  m_text_area->WriteText(wxString(wxChar(' '),
        m_links_end_pos - m_text_area->GetInsertionPoint()));
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
  
  UnistalHandler();
  m_panel->RemoveTransferFor(m_sess);
}

bool InconingTransfer::GetPath(wxString &path){
  wxDirDialog dialog(m_text_area->GetParent(), wxT("Choose a directory"), path);
  if (dialog.ShowModal() == wxID_OK){
    path = dialog.GetPath();
    return true;
  } else{
    return false;
  }
}

  
///////////////////////////////////////
// CurrentTransfer
/////////////////////////////////////// 
CurrentTransfer::CurrentTransfer(ChatPanel *panel, wxRichTextCtrl *text_area,
      cricket::FileShareSession *sess, long begin_pos, long end_pos,
      long links_begin_pos, long links_end_pos): TransferBase(panel, sess, text_area, begin_pos,
      end_pos, links_begin_pos, links_end_pos){
  Init();
  Connect(m_text_area->GetId(), wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler(CurrentTransfer::OnUrlClick));
  m_text_area->PushEventHandler(this);
};
      
CurrentTransfer::~CurrentTransfer(){
}

void CurrentTransfer::Init(){
  m_cancel_str = wxString::Format(wxT("%x-%x#Cancel"), m_id, this);
  
  m_text_area->Delete(wxRichTextRange(m_links_begin_pos, m_links_end_pos));
  m_text_area->SetInsertionPoint(m_links_begin_pos);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(wxT("Accepted. "));
  
  m_text_area->BeginURL(m_cancel_str);
  m_text_area->BeginUnderline();
  m_text_area->BeginTextColour(*wxBLUE);
  m_text_area->WriteText(wxT("Cancel"));
  m_text_area->EndTextColour();
  m_text_area->EndUnderline();
  m_text_area->EndURL();
  
  //ASSERT(m_links_end_pos >= m_text_area->GetInsertionPoint());
  m_text_area->WriteText(wxString(wxChar(' '),
        m_links_end_pos - m_text_area->GetInsertionPoint()));
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
}

void CurrentTransfer::OnUrlClick(wxTextUrlEvent &event){
  wxString text = event.GetString();
  if (m_pending){
    if ((text == m_cancel_str)){
      m_pending = false;
      OnCancel();
    } else{
      //PRU_LOG("InconingTransfer::OnUrlClick - None");
    }
  }
  event.Skip();
}

void CurrentTransfer::OnCancel(){
  m_text_area->SetDefaultStyle(m_original_stile);
  
  m_text_area->Delete(wxRichTextRange(m_links_begin_pos, m_links_end_pos));
  m_text_area->SetInsertionPoint(m_links_begin_pos);
  //ASSERT(new_text.Len() == (m_links_begin_pos - m_links_end_pos) );
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(wxT("Canceled"));
  
  //ASSERT(m_links_end_pos >= m_text_area->GetInsertionPoint()); 
  m_text_area->WriteText(wxString(wxChar(' '),
        m_links_end_pos - m_text_area->GetInsertionPoint()));
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
  
  if (!m_pending && (m_sess && (m_sess->is_sender()))){
    CimStarter::SCimClient()->CancelShare(m_sess);
  }
  UnistalHandler();
  m_panel->RemoveTransferFor(m_sess);
}

void CurrentTransfer::OnComplete(){
  m_pending = false;
  m_text_area->SetDefaultStyle(m_original_stile);
  
  m_text_area->Delete(wxRichTextRange(m_links_begin_pos, m_links_end_pos));
  m_text_area->SetInsertionPoint(m_links_begin_pos);
  m_text_area->WriteText(text_tab);
  m_text_area->WriteText(wxT("Completed"));
  
  //ASSERT(m_links_end_pos >= m_text_area->GetInsertionPoint());
  m_text_area->WriteText(wxString(wxChar(' '),
        m_links_end_pos - m_text_area->GetInsertionPoint()));
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
  
  UnistalHandler();
  m_panel->RemoveTransferFor(m_sess);
}

void CurrentTransfer::UpdateProgress(bool good_curr, size_t curr_transfered,
      bool good_total, size_t total_size){
  //m_pending = false;
  m_text_area->SetDefaultStyle(m_original_stile);
  
  m_text_area->Delete(wxRichTextRange(m_links_begin_pos, m_links_end_pos));
  m_text_area->SetInsertionPoint(m_links_begin_pos);
  
  m_text_area->WriteText(text_tab);
  
  m_text_area->BeginURL(m_cancel_str);
  m_text_area->BeginUnderline();
  m_text_area->BeginTextColour(*wxBLUE);
  m_text_area->WriteText(wxT("Cancel"));
  m_text_area->EndTextColour();
  m_text_area->EndUnderline();
  m_text_area->EndURL();
  m_text_area->WriteText(wxT(". "));
  
  if (good_total && good_curr){
    m_text_area->WriteText(wxT("Remaning: "));
    size_t remaning = total_size - curr_transfered;
    m_text_area->WriteText(Bytes2String(remaning));
    m_text_area->WriteText(wxT("."));
  } else if (good_total){
    m_text_area->WriteText(wxT("Total: "));
    m_text_area->WriteText(Bytes2String(total_size)); 
    m_text_area->WriteText(wxT("."));
  } else if (good_curr){
    m_text_area->WriteText(wxT("Tranfered: "));
    m_text_area->WriteText(Bytes2String(curr_transfered));
    m_text_area->WriteText(wxT("."));
  } else{
    m_text_area->WriteText(wxT("No progress data."));
  }

  //ASSERT(m_links_end_pos >= m_text_area->GetInsertionPoint());
  m_text_area->WriteText(wxString(wxChar(' '),
        m_links_end_pos - m_text_area->GetInsertionPoint()));
  m_text_area->SetInsertionPoint(m_text_area->GetLastPosition());
} 
  
} //namespace cim
