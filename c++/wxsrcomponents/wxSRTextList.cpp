#include "wxSRTextList.hpp"

BEGIN_EVENT_TABLE(wxSRTextList, wxPanel)
EVT_CHOICE( wxID_ANY, wxSRTextList::OnClick )
END_EVENT_TABLE()

wxSRTextList::wxSRTextList( wxWindow* parent, const wxString& label, wxArrayString choices) :
	wxSROptionsComponent(parent, label,choices){
 
  CreateControls();
  
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

void wxSRTextList::OnClick(wxCommandEvent& event){
	unsigned int selection = m_combo->GetCurrentSelection();
	ShowOptionChildren(m_combo->GetString(selection));
	RefreshSizers();
}

void wxSRTextList::AddOnSizer(wxSizer* children_sizer){
	m_flexsizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP, 30);
}

wxSRTextList::~wxSRTextList() {}

void wxSRTextList::CreateControls() {
  m_flexsizer = new wxFlexGridSizer(1,3,0,0);

  m_flexsizer->AddGrowableCol(1, 1);
  m_flexsizer->AddGrowableCol(2, 1);
  
  SetSizer(m_flexsizer);
  
  wxStaticText* staticText = new wxStaticText( this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, 0 );
  m_flexsizer->Add(staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxTextCtrl* textCtrl = new wxTextCtrl( this, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
  m_flexsizer->Add(textCtrl, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);
  
  m_combo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize,  m_choices, 0 );
  m_flexsizer->Add(m_combo, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);
}
