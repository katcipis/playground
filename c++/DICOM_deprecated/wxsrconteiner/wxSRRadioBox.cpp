#include "wxSRRadioBox.hpp"

wxSRRadioBox::wxSRRadioBox(wxWindow* parent, wxString label, wxArrayString choices) : 
	wxSROptionsComponent(parent, label, choices) {
  
	CreateControls();
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

wxSRRadioBox::~wxSRRadioBox() {
}

void wxSRRadioBox::RefreshOnGui() { }

void wxSRRadioBox::CreateControls() {
	
	m_sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(m_sizer);
	
	m_radiobox = new wxRadioBox(this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, m_choices);
	m_sizer->Add(m_radiobox, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);
	
	
}
