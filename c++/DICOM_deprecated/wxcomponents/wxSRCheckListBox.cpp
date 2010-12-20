#include "wxSRCheckListBox.hpp"


wxSRCheckListBox::wxSRCheckListBox(wxWindow* parent, wxString label,
		wxArrayString choices) : wxSROptionsComponent(parent, label,choices) {

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
}

wxSRCheckListBox::~wxSRCheckListBox() {
}

void wxSRCheckListBox::AddChoices() {
	int choices_size = m_choices.GetCount();

	for (int i = 0; i < choices_size; i++) {
		wxString tmp = m_choices[i]; 
		wxCheckBox* aux = new wxCheckBox( this, wxID_ANY, tmp, wxDefaultPosition, wxDefaultSize, 0 );
		
		m_flexsizer->Add(aux, 0, wxALIGN_LEFT|wxALIGN_TOP|wxALL , 5);
	}
}

void wxSRCheckListBox::CreateControls() {

	m_static_box = new wxStaticBox(this, wxID_ANY, m_label);
	m_static_box_sizer = new wxStaticBoxSizer(m_static_box, wxHORIZONTAL);
	SetSizer(m_static_box_sizer);

	m_flexsizer = new wxFlexGridSizer(2,1,0,0);
	m_flexsizer->AddGrowableCol(0, 1);
	m_static_box_sizer->Add(m_flexsizer, 1, wxGROW|wxALL, 5);

	AddChoices();

}
