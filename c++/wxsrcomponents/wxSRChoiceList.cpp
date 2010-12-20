#include "wxSRChoiceList.hpp"

BEGIN_EVENT_TABLE(wxSRChoiceList, wxPanel)
EVT_CHOICE( wxID_ANY, wxSRChoiceList::OnClick )
END_EVENT_TABLE()

wxSRChoiceList::wxSRChoiceList(wxWindow* parent, wxString label, wxArrayString choices) :
wxSROptionsComponent(parent, label,choices) {

  InsertDefaultOption();

  CreateControls();
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

void wxSRChoiceList::OnClick(wxCommandEvent& event) {
  unsigned int selection = m_choicelist->GetCurrentSelection();
  ShowOptionChildren(m_choicelist->GetString(selection));
  RefreshSizers();
}

wxSRChoiceList::~wxSRChoiceList() {
}

void wxSRChoiceList::AddOnSizer(wxSizer* children_sizer) {
  m_flexsizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP, 30);
  RefreshSizers();
}

void wxSRChoiceList::CreateControls() {

  m_flexsizer = new wxFlexGridSizer(1,2,0,0);

  m_flexsizer->AddGrowableCol(1, 1);
  SetSizer(m_flexsizer);

  m_label_static_text = new wxStaticText( this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, 0 );
  m_flexsizer->Add(m_label_static_text, 0, wxALIGN_CENTER|wxALL, 5);

  m_choicelist= new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choices, 0 );
  m_flexsizer->Add(m_choicelist, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);

}


