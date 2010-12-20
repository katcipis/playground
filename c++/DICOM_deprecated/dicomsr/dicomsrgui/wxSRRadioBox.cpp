#include "wxSRRadioBox.hpp"

wxSRRadioBox::wxSRRadioBox(wxWindow* parent, wxString label, wxArrayString choices) : wxSROptionsComponent(parent, label,choices) {

  CreateControls();
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

wxSRRadioBox::~wxSRRadioBox() {
  
}

void wxSRRadioBox::AddChoices() {
  int arraySize = m_choices.GetCount();
  wxRadioBox* aux = new wxRadioBox( this, ID_RADIOBOX, _(""), wxDefaultPosition, wxDefaultSize, m_choices, arraySize, wxRA_SPECIFY_ROWS );
  aux->SetSelection(0);
  m_flexsizer->Add(aux, 0, wxGROW|wxEXPAND|wxALL , 5);
  
}

void wxSRRadioBox::CreateControls() {

  m_static_box = new wxStaticBox(this, wxID_ANY, m_label);
  m_static_box_sizer = new wxStaticBoxSizer(m_static_box, wxHORIZONTAL);
  SetSizer(m_static_box_sizer);

  m_flexsizer = new wxFlexGridSizer(2,1,0,0);
  m_flexsizer->AddGrowableCol(0, 1);
  m_static_box_sizer->Add(m_flexsizer, 1, wxGROW|wxALL, 5);

  AddChoices();

}
