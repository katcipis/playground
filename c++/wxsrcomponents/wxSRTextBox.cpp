#include "wxSRTextBox.hpp"

wxSRTextBox::wxSRTextBox(wxWindow* parent, wxString label) :
  wxSRComponent(parent, label) {
  m_text_Box_label = _("");

  CreateControls();
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

wxSRTextBox::~wxSRTextBox() {
}

void wxSRTextBox::RefreshState(wxCommandEvent& event, bool state){
  RefreshSizers();
}

void wxSRTextBox::AddOnSizer(wxSizer* children_sizer) {
  m_flexsizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP, 30);
}

void wxSRTextBox::CreateControls() {

  m_flexsizer = new wxFlexGridSizer(1,2,0,0);

  m_flexsizer->AddGrowableCol(1, 1);
  SetSizer(m_flexsizer);

  m_label_static_text = new wxStaticText( this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, 0 );
  m_flexsizer->Add(m_label_static_text, 0, wxALIGN_CENTER|wxALL, 5);

  m_textBox = new wxTextCtrl( this, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
  m_flexsizer->Add(m_textBox, 0, wxGROW|wxEXPAND|wxALL, 5);

}
