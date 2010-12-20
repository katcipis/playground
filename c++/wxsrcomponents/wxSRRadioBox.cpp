#include "wxSRRadioBox.hpp"

BEGIN_EVENT_TABLE(wxSRRadioBox, wxPanel)
EVT_RADIOBOX( wxID_ANY, wxSRRadioBox::OnClick )
END_EVENT_TABLE()

wxSRRadioBox::wxSRRadioBox(wxWindow* parent, wxString label, wxArrayString choices) :
wxSROptionsComponent(parent, label,choices) {

  CreateControls();
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

void wxSRRadioBox::OnClick(wxCommandEvent& event) {

  wxString selected_button = m_radiobox->GetString(m_radiobox->GetSelection());
  ShowOptionChildren(selected_button);
  RefreshSizers();

}

wxSRRadioBox::~wxSRRadioBox() {
}

void wxSRRadioBox::AddOnSizer(wxSizer* children_sizer) {
  m_sizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP, 30);
}

void wxSRRadioBox::RefreshOnGui() {
}

void wxSRRadioBox::CreateControls() {

  m_sizer = new wxBoxSizer(wxVERTICAL);
  SetSizer(m_sizer);

  m_radiobox = new wxRadioBox(this, wxID_ANY, m_label, wxDefaultPosition, wxDefaultSize, m_choices);
  m_sizer->Add(m_radiobox, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);

}

void wxSRRadioBox::RefreshState(wxCommandEvent& event, bool state) {
  if (state)
    OnClick(event);
  else
    m_children_sizer->Show(false);

  RefreshSizers();
}
