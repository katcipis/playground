#include "xmppgui/chat/ChatPanel.hpp"

#include "xmppgui/Constants.hpp"

#include "xmppgui/xmpp/CimStarter.hpp"

#include "xmppgui/util/KeyEventFowarder.hpp"
#include "xmppgui/util/XmppEvent.hpp"

#include <wx/gbsizer.h>

namespace cim {

DEFINE_LOCAL_EVENT_TYPE(cimEVT_Delete_Transfer)

const wxString text_two_dots(wxT(": "));
const wxString text_enter(wxT("\n"));
const wxString text_tab(wxT("    "));
const wxString text_alert(wxT(" *** "));

ChatPanel::ChatPanel(wxWindow* parent, buzz::Jid other_jid)
: wxPanel(parent), m_other_jid(other_jid), m_my_jid(buzz::JID_EMPTY),
m_last_talk("...@.../...") {
	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	SetSizer(mainSizer);
	
	wxGridBagSizer *sizer = new wxGridBagSizer();
	sizer->AddGrowableCol(0);
	sizer->AddGrowableRow(1);
	mainSizer->Add(sizer, 0, wxALL|wxGROW, 5);
	
	m_draw_panel = new DrawPanel(this);
	
	m_mousePanel = new MousePanel(this, m_draw_panel);
	mainSizer->Add(m_mousePanel, 0, wxALL|wxGROW, 5);
	mainSizer->Add(m_draw_panel, 0, wxALL|wxGROW, 5);
	
	m_chat_text = new wxRichTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize,
			wxRE_MULTILINE | wxTE_READONLY);
	m_message = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize,
			wxTE_PROCESS_ENTER);
	m_send = new wxButton(this, wxID_ANY, wxT("Send"));
	m_upper_sizer = new wxBoxSizer(wxHORIZONTAL);

	
	// layout
	sizer->Add(m_upper_sizer, wxGBPosition(0, 0), wxGBSpan(1, 2),
			wxEXPAND);
	sizer->Add(m_chat_text, wxGBPosition(1, 0), wxGBSpan(1, 2),
			wxEXPAND | FORM_BORDERS | wxTOP, 5);
	sizer->Add(m_message, wxGBPosition(2, 0), wxGBSpan(1, 1),
			wxEXPAND | FORM_BORDERS, 5);
	sizer->Add(m_send, wxGBPosition(2, 1), wxGBSpan(1, 1),
			wxEXPAND | wxRIGHT | wxBOTTOM, 5);

	

	sizer->SetSizeHints(this);
	// event handlers
	Connect(GetId(), wxEVT_SIZE, wxEventHandler(ChatPanel::OnResize));
	
	//m_mousePanel->Connect(m_mousePanel->GetId(), wxEVT_MOUSE_EVENTS, wxMouseEventHandler(ChatPanel::OnMouseMotion));
	
	Connect(GetId(), cimEVT_Delete_Transfer, wxEventHandler(ChatPanel::OnDeleteTransfer));
	Connect(m_message->GetId(), wxEVT_COMMAND_TEXT_ENTER, wxEventHandler(ChatPanel::OnEnterKeyPress));
	Connect(m_send->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxEventHandler(ChatPanel::OnEnterKeyPress));
	Connect(m_chat_text->GetId(), wxEVT_KEY_DOWN, wxKeyEventHandler(ChatPanel::OnKeyPressInWrongField));
	// TODO: Reinsert the line bellow... PushEventHandler seen not to been working
	// It behaves baddly the sob
	//m_chat_text->PushEventHandler(g_key_event_fowarder_delayed);
	m_chat_text->BeginSuppressUndo();

	// ...
	InitCallPanels();
	InitSharePanel();
	m_original_stile = m_chat_text->GetDefaultStyleEx();

	// fixing size issues... please, find a better way to do it
	sizer->SetSizeHints(this);
	wxSize min_size = GetMinSize();
	min_size.IncBy(10, 70);
	SetMinSize(min_size);
	wxSize curr_size = GetSize();
	if (min_size.GetWidth() > curr_size.GetWidth())
		curr_size.SetWidth(min_size.GetWidth());
	if (min_size.GetHeight() > curr_size.GetHeight())
		curr_size.SetHeight(min_size.GetHeight());
	
	SetSize(curr_size);
}

ChatPanel::~ChatPanel() {
	if (m_current_call_pane->IsShown()) {
		wxCommandEvent event;
		m_current_call_pane->OnHangup(event);
	}
	if (m_incoming_call_pane->IsShown()) {
		wxCommandEvent event;
		m_incoming_call_pane->OnReject(event);
	}
}

void ChatPanel::InitCallPanels() {
	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
	m_upper_sizer->Add(sizer, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);

	m_incoming_call_pane = new IncomingCall(this, m_other_jid);
	m_current_call_pane = new CurrentCall(this, m_other_jid);
	m_do_call_pane = new DoCall(this, m_other_jid);

	sizer->Add(m_do_call_pane);
	sizer->Add(m_incoming_call_pane);
	sizer->Add(m_current_call_pane);

	// m_current_call_pane is the bigger
	m_incoming_call_pane->MakeVisible(false);
	m_current_call_pane->MakeVisible(true);
	m_do_call_pane->MakeVisible(false);

	sizer->Layout();
}

void ChatPanel::InitSharePanel() {
	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
	m_upper_sizer->Add(sizer, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);

	m_share_files = new ShareFiles(this, m_other_jid);

	sizer->Add(m_share_files);

	// m_current_call_pane is the bigger
	m_share_files->MakeVisible(true);

	sizer->Layout();
}

void ChatPanel::PutMessage(buzz::Jid &source, wxString &text) {
	m_chat_text->SetDefaultStyle(m_original_stile);
	m_chat_text->SetDefaultStyle(m_original_stile);
	if (m_last_talk.BareEquals(source)) {
		m_chat_text->AppendText(text_tab);
	} else {
		m_last_talk = source;
		m_chat_text->BeginBold();
		m_chat_text->AppendText(wxString::FromUTF8(source.node().c_str()));
		m_chat_text->EndBold();
		m_chat_text->AppendText(text_two_dots);
	}
	if (!text.IsEmpty()) {
		m_chat_text->AppendText(text);
		m_chat_text->Newline();
	}
	EnsureLastLineVisibility();
}

void ChatPanel::EnsureLastLineVisibility() {
	m_chat_text->ShowPosition(m_chat_text->GetLastPosition());
}

void ChatPanel::AppendAlert(wxString s) {
	if (s.IsEmpty())
	return;
	m_chat_text->SetDefaultStyle(m_original_stile);

	m_chat_text->BeginItalic();
	m_chat_text->AppendText(text_alert);
	m_chat_text->AppendText(s);
	m_chat_text->AppendText(text_alert);
	m_chat_text->EndItalic();
	//m_chat_text->AppendText(text_enter);
	m_chat_text->Newline();
	EnsureLastLineVisibility();
}

void ChatPanel::SetMyJid(buzz::Jid jid) {
	m_my_jid = jid;
}

buzz::Jid ChatPanel::GetOtherJid() {
	return m_other_jid;
}

void ChatPanel::ReceiveMsg(wxString &text) {
	if (text.IsEmpty())
	return;
	PutMessage(m_other_jid, text);
}

void ChatPanel::OnEnterKeyPress(wxEvent &event) {
	wxString msg(m_message->GetValue());
	if (msg.IsEmpty())
	return;
	//SendMsg(msg);
	PutMessage(m_my_jid, msg);

	CimClient *client = CimStarter::GetInstance().GetCimClient();
	client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());

	m_message->Clear();
}

void ChatPanel::OnKeyPressInWrongField(wxKeyEvent &event) {
	if (event.GetModifiers() == wxMOD_SHIFT) {
		m_message->SetFocus();
	} else if (event.GetModifiers() == wxMOD_NONE) {
		wxKeyEvent event2(event);
		event2.SetId(m_message->GetId());
		m_message->EmulateKeyPress(event2);
		//m_message->SetFocus();
	}
	event.Skip();
}

void ChatPanel::EnableChatPanel(bool b) {
	m_incoming_call_pane->MakeVisible(false);
	m_current_call_pane->MakeVisible(false);
	m_do_call_pane->MakeVisible(b);

	m_upper_sizer->Layout();
	GetSizer()->Layout();
}

void ChatPanel::EnableSharePanel(bool b) {
	m_share_files->MakeVisible(b);

	m_upper_sizer->Layout();
	GetSizer()->Layout();
}

void ChatPanel::AddReceivedCallPanel(cricket::Call *call, cricket::Session *session) {
	//GetSizer()->GetItem(m_upper_sizer)->DeleteWindows();
	//m_upper_sizer->Clear(true);
	//IncomingCall *incomong = new IncomingCall(this, m_other_jid, call, session);
	//m_upper_sizer->Add(incomong, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);
	m_incoming_call_pane->SetData(call, session);
	m_incoming_call_pane->MakeVisible(true);
	m_current_call_pane->MakeVisible(false);
	m_do_call_pane->MakeVisible(false);

	m_upper_sizer->Layout();
	GetSizer()->Layout();
}

void ChatPanel::AddCallInProgressPanel(cricket::Call *call, cricket::Session *session) {
	//GetSizer()->GetItem(m_upper_sizer)->DeleteWindows();
	//m_upper_sizer->Clear(true);
	//CurrentCall *current = new CurrentCall(this, m_other_jid, call, session);
	//m_upper_sizer->Add(current, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);
	m_current_call_pane->SetData(call, session);
	m_incoming_call_pane->MakeVisible(false);
	m_current_call_pane->MakeVisible(true);
	m_do_call_pane->MakeVisible(false);

	m_upper_sizer->Layout();
	GetSizer()->Layout();
}

void ChatPanel::RemoveCallPanel() {
	//GetSizer()->GetItem(m_upper_sizer)->DeleteWindows();
	//m_upper_sizer->Clear(true);
	//DoCall *menu_call = new DoCall(this, m_other_jid);
	//m_upper_sizer->Add(menu_call, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);
	m_incoming_call_pane->MakeVisible(false);
	m_current_call_pane->MakeVisible(false);
	m_do_call_pane->MakeVisible(true);

	m_upper_sizer->Layout();
	GetSizer()->Layout();
}

void ChatPanel::OnResize(wxEvent &event) {
	EnsureLastLineVisibility();
	event.Skip();
}

typedef XmppEvent<TransferBase *> TransferDeleteEvent;
void ChatPanel::OnDeleteTransfer(wxEvent &event) {
	TransferDeleteEvent *l_event = dynamic_cast<TransferDeleteEvent *>(&event);
	if (l_event) {
		delete l_event->arg0;
	} else {
		PRU_LOG1("ChatPanel::OnDeleteTransfer (l_event == NULL)");
	}
}
void ChatPanel::DeleteTransfer(TransferBase *trans) {
	if (trans) {
		TransferDeleteEvent event(GetId(), cimEVT_Delete_Transfer);
		event.arg0 = trans;
		AddPendingEvent(event);
	}
}

void ChatPanel::AddTransfer(cricket::FileShareSession *sess, TransferBase *trans) {
	TransferMap::iterator it = m_transfers.find(sess);
	if (it != m_transfers.end())
	DeleteTransfer(it->second);

	m_transfers[sess] = trans;
}
void ChatPanel::RemoveTransferFor(cricket::FileShareSession *sess) {
	TransferMap::iterator it = m_transfers.find(sess);
	if (it != m_transfers.end()) {
		DeleteTransfer(it->second);
		m_transfers.erase(it);
	}
}

void ChatPanel::ShareOffer(cricket::FileShareSession *sess) {
	wxString dummy;
	PutMessage(sess->is_sender() ? m_my_jid : m_other_jid, dummy);
	m_chat_text->Newline();

	InconingTransfer *inc_trans = new InconingTransfer(this, m_chat_text, sess);
	EnsureLastLineVisibility();
}

void ChatPanel::ShareCompleted(cricket::FileShareSession *sess) {
	CurrentTransfer *curr = dynamic_cast<CurrentTransfer*>(m_transfers[sess]);
	if (curr) {
		curr->OnComplete();
	}
}

void ChatPanel::ShareCancel(cricket::FileShareSession *sess) {
	TransferMap::iterator it = m_transfers.find(sess);
	if (it != m_transfers.end())
	it->second->OnCancel();
}

void ChatPanel::ShareUpdateProgress(cricket::FileShareSession *sess) {
	TransferBase* tmp= m_transfers[sess];
	if (!sess)
	PRU_LOG1("(sess == NULL)");
	if (!tmp)
	PRU_LOG1("(tmp == NULL)");

	CurrentTransfer *curr = dynamic_cast<CurrentTransfer*>(tmp);
	if (curr) {
		size_t size, total;
		bool good1 = sess->GetProgress(size);
		bool good2 = sess->GetTotalSize(total);
		curr->UpdateProgress(good1, size, good2, total);
	} else {
		PRU_LOG1("(curr == NULL)");
	}
}
}

//} // namespace cim
