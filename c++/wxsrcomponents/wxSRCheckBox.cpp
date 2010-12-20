#include "wxSRCheckBox.hpp"

BEGIN_EVENT_TABLE(wxSRCheckBox, wxPanel)
EVT_CHECKBOX( wxID_ANY, wxSRCheckBox::OnClick )
END_EVENT_TABLE()

wxSRCheckBox::wxSRCheckBox(wxWindow* parent, wxString label) :
wxSRComponent(parent, label) {

  CreateControls();
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

void wxSRCheckBox::OnClick(wxCommandEvent& event) {

  if (m_children_sizer)
    m_children_sizer->Show(IsChecked());

  if (IsChecked()) {

    std::vector<wxSRComponent*>::iterator iter;

    for (iter = m_children.begin(); iter != m_children.end(); iter++) {
      wxSRComponent* tmp = *iter;
      tmp->RefreshState(event, true);
    }

  } else {
    UncheckChildren(event);
  }

  RefreshSizers();

}

void wxSRCheckBox::RefreshState(wxCommandEvent& event, bool state) {
  OnClick(event);
}

wxSRCheckBox::~wxSRCheckBox() {
}

void wxSRCheckBox::AddOnSizer(wxSizer* children_sizer) {
  m_sizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP, 30);
}

void wxSRCheckBox::RefreshOnGui() {
}

void wxSRCheckBox::CreateControls() {

  m_sizer = new wxBoxSizer(wxVERTICAL);

  m_checkbox = new wxCheckBox(this, wxID_ANY, m_label);

  m_sizer->Add(m_checkbox, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);

  SetSizer(m_sizer);

}

void wxSRCheckBox::UncheckChildren(wxCommandEvent& event) {

  for (unsigned int i = 0; i < m_children.size(); i++) {
    wxSRComponent* tmp = m_children.at(i);
    tmp->SetCheckValue(false);
    tmp->RefreshState(event);
  }
}

bool wxSRCheckBox::IsChecked() {
  return m_checkbox->IsChecked();
}

void wxSRCheckBox::SetCheckValue(bool state) {
  m_checkbox->SetValue(state);
}
