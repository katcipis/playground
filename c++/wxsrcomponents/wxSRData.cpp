#include "wxSRData.hpp"

wxSRData::wxSRData(wxWindow* parent, wxString label) : wxSRComponent(parent, label) {
	m_text_ctrl_label = _("");

	CreateControls();
	if (GetSizer()){
		GetSizer()->SetSizeHints(this);
	}
	Centre();
}

wxSRData::~wxSRData(){}

void wxSRData::AddOnSizer(wxSizer* children_sizer){
	m_flexsizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxTAB_TRAVERSAL, 30);
}

void wxSRData::RefreshState(wxCommandEvent& event, bool state){
  RefreshSizers();
}

void wxSRData::CreateControls() {

	m_flexsizer = new wxFlexGridSizer(1,2,0,0);

	m_flexsizer->AddGrowableCol(1, 1);
	SetSizer(m_flexsizer);

	m_label_static_text = new wxStaticText( this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, 0 );
	m_flexsizer->Add(m_label_static_text, 0, wxALIGN_CENTER|wxALL|wxTAB_TRAVERSAL, 5);

	m_data_picker = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY|wxTAB_TRAVERSAL, wxDefaultValidator, _("DataPicker") );
	m_flexsizer->Add(m_data_picker, 0, wxALIGN_CENTER|wxGROW|wxALL|wxTAB_TRAVERSAL, 5);
	
}
