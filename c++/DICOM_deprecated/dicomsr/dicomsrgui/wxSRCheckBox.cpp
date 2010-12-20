#include "wxSRCheckBox.hpp"

wxSRCheckBox::wxSRCheckBox(wxWindow* parent, wxString label) :
	wxSRGenericComponent(parent, label) {

	CreateControls();
	if (GetSizer()) {
		GetSizer()->SetSizeHints(this);
	}
	Centre();
}

wxSRCheckBox::~wxSRCheckBox() {
}

void wxSRCheckBox::RefreshOnGui() { }

void wxSRCheckBox::CreateControls() {

	m_sizer = new wxBoxSizer(wxVERTICAL);
	
	m_checkbox = new wxCheckBox(this, wxID_ANY, m_label);
	
	m_sizer->Add(m_checkbox, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);

	SetSizer(m_sizer);

}

bool wxSRCheckBox::IsChecked(){
	return m_checkbox->IsChecked();
}

void wxSRCheckBox::SetCheckValue(bool state){
	m_checkbox->SetValue(state);
}
