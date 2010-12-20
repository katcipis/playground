#include "wxSRTextCtrl.hpp"

wxSRTextCtrl::wxSRTextCtrl(wxWindow* parent, wxString label) : wxSRComponent(parent, label) {
	m_text_ctrl_label = _("");

	CreateControls();
	if (GetSizer()){
		GetSizer()->SetSizeHints(this);
	}
	Centre();
}


wxSRTextCtrl::~wxSRTextCtrl() { }

void wxSRTextCtrl::AddOnSizer(wxSizer* children_sizer){
	m_flexsizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP, 30);
}

void wxSRTextCtrl::CreateControls() {

	m_flexsizer = new wxFlexGridSizer(1,2,0,0);

	m_flexsizer->AddGrowableCol(1, 1);
	SetSizer(m_flexsizer);

	m_label_static_text = new wxStaticText( this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, 0 );
	m_flexsizer->Add(m_label_static_text, 0, wxALIGN_CENTER|wxALL, 5);

	m_text_ctrl = new wxTextCtrl(this, wxID_ANY, m_text_ctrl_label, wxDefaultPosition, wxDefaultSize, 0 );
	m_flexsizer->Add(m_text_ctrl, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);
	
}
