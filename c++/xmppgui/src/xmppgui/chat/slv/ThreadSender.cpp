#include "xmppgui/chat/slv/ThreadSender.hpp"

namespace cim {

ThreadSender::ThreadSender(CapturePanel *panel, buzz::Jid other_jid) {
	m_other_jid = other_jid;
	m_panel = panel;
}

ThreadSender::~ThreadSender() {
}

void* ThreadSender::Entry() {
	wxString ant = wxT("");
	while (true) {
		wxString position = m_panel->GetPositionString();
		CimClient *client = CimStarter::GetInstance().GetCimClient();

		if (!ant.IsSameAs(position)) {
			wxString draw_position = wxT("SVL$") + position;
			client->SendTextMessage(m_other_jid.Str(),
					draw_position.utf8_str().data());
		}

		if (m_panel->MouseLeftIsDown() && !ant.IsSameAs(position)) {
			wxString msg =
					wxT("Arrastando o mouse com o botão esquerdo na posição: ")
							+ position;
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		if (m_panel->MouseLeftIsDoubleClicked()) {
			wxString msg = wxT("Clique duplo com o botão esquerdo na posição: ")
					+ position;
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		if (m_panel->MouseLeftIsClicked()) {
			wxString msg = wxT("Clique simples com o botão esquerdo na posição: ")
					+ position;
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		if (m_panel->MouseRightIsClicked()) {
			wxString msg = wxT("Clique simples com o botão direito na posição: ")
					+ position;
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		if (m_panel->MouseEnteredWindow()) {
			wxString msg = wxT("Mouse entrou na janela");
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		if (m_panel->MouseLeaveWindow()) {
			wxString msg = wxT("Mouse saiu da janela");
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		if (m_panel->MouseLeftIsUp()) {
			wxString msg = wxT("Mouse parou de arrastar na posição: ") + position;;
			client->SendTextMessage(m_other_jid.Str(), msg.utf8_str().data());
		}

		Sleep(1);
		ant = position;
	}
}

}
