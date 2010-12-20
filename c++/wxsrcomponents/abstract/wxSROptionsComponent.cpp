#include "./wxSROptionsComponent.hpp"
#include <algorithm>

wxSROptionsComponent::wxSROptionsComponent(wxWindow* parent, wxString label, wxArrayString choices) :
  wxSRComponent(parent, label) {
  m_choices = choices;

  for (unsigned int i = 0; i < m_choices.GetCount(); i++)
    m_options_children[m_choices[i]] = std::vector<wxSRComponent*>();

  }

wxSROptionsComponent::~wxSROptionsComponent() {
}

void wxSROptionsComponent::InsertDefaultOption() {
  wxString selec = _("Selecione");
  m_options_children[selec] = std::vector<wxSRComponent*>();

  wxArrayString tmp;
  tmp.Add(selec);

  for (unsigned int i = 0; i < m_choices.GetCount(); i++)
  tmp.Add(m_choices[i]);

  m_choices = tmp;
}

void wxSROptionsComponent::AddComponent(wxSRComponent* child) {
}

void wxSROptionsComponent::AddComponents(std::vector<wxSRComponent*> children) {
}

wxArrayString wxSROptionsComponent::GetOptions() {
  return m_choices;
}

void wxSROptionsComponent::ShowOptionChildren(wxString option) {

  if (HasChildren(option) && m_children_sizer) {

    m_children_sizer->Show(false);
    m_children_sizer->Clear();

    std::vector<wxSRComponent*> children = m_options_children[option];

    for (unsigned int i = 0; i < children.size(); i++) {
      if (children.at(i)) {
        wxSRComponent* tmp = children.at(i);
        if (tmp) {
          wxSizer* aux = new wxBoxSizer(wxVERTICAL);
          m_children_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
          m_children_sizer->Add(aux, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);
          tmp->SetChildrenSizer(aux);
        }
      }
    }

    m_children_sizer->Show(true);

    for (unsigned int i = 0; i < children.size(); i++) {
      wxCommandEvent event;
      wxSRComponent* tmp = children.at(i);
      if (tmp) {
        tmp->SetCheckValue(false);
        tmp->RefreshState(event, false);
      }
    }
  }
  
  RefreshSizers();

}

bool wxSROptionsComponent::HasOption(wxString option) {
  for (unsigned int i = 0; i <= (m_choices.GetCount() - 1); i++)
    if (m_choices[i] == option)
      return true;

  return false;
}

bool wxSROptionsComponent::HasChildren(wxString parent) {
  return m_options_children.find(parent) != m_options_children.end();
}

void wxSROptionsComponent::AddComponent(wxString option, wxSRComponent* child) {

  GetChildrenSizer();

  if (HasOption(option) && child != NULL) {
    std::vector<wxSRComponent*> tmp = m_options_children[option];

    if (find(tmp.begin(), tmp.end(), child) == tmp.end()) {
      tmp.push_back(child);
      m_children.push_back(child);
      child->Show(false);
    }

    m_options_children[option] = tmp;

  }

}

void wxSROptionsComponent::AddComponents(wxString option, std::vector<wxSRComponent*> children) {
  for (unsigned int i = 0; i <= (children.size() - 1); i++)
    AddComponent(option, children[i]);
}

void wxSROptionsComponent::SetCheckValue(bool state) {
}

void wxSROptionsComponent::RefreshState(wxCommandEvent& event, bool state) {
  m_children_sizer->Show(false);
  RefreshSizers();
}
