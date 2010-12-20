#include "wxSRChoiceList.hpp"

wxSRChoiceList::wxSRChoiceList(wxWindow* parent, wxString label, wxArrayString choices) :
	wxSROptionsComponent(parent, label, choices) {

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
}

wxSRChoiceList::~wxSRChoiceList() {
}

void wxSRChoiceList::CreateControls() {

	m_flexsizer = new wxFlexGridSizer(1,2,0,0);

	m_flexsizer->AddGrowableCol(1, 1);
	SetSizer(m_flexsizer);

	m_label_static_text = new wxStaticText( this, wxID_STATIC, m_label, wxDefaultPosition, wxDefaultSize, 0 );
	m_flexsizer->Add(m_label_static_text, 0, wxALIGN_CENTER|wxALL, 5);

	m_combo_box= new wxChoice( this, ID_CHOICE, wxDefaultPosition, wxDefaultSize, m_choices, 0 );
	m_flexsizer->Add(m_combo_box, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);

}
