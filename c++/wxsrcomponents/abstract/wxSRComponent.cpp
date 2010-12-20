#include "wxSRComponent.hpp"
#include <algorithm>

wxSRComponent::wxSRComponent(wxWindow* parent, wxString label) :
	wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER |wxTAB_TRAVERSAL) {

	m_parent = parent;
	m_label = label;
	m_values["label"] = label;
	m_children_sizer = NULL;
}

std::map<std::string, wxString> wxSRComponent::GetValues() {
	return m_values;
}

std::vector<wxSRComponent*> wxSRComponent::GetChildren() {
	return m_children;
}

void wxSRComponent::SetChildrenSizer(wxSizer* sizer) {
	m_children_sizer = sizer;
	
	for (unsigned int i = 0; i < m_children.size(); i++)
			InsertComponent(m_children.at(i));
	
}

bool wxSRComponent::IsRootComponent() {
	return m_children_sizer == NULL;
}

wxSizer* wxSRComponent::GetChildrenSizer() {

	if (IsRootComponent()) 
		m_children_sizer = new wxBoxSizer(wxVERTICAL);
	
	return m_children_sizer;
}

void wxSRComponent::InsertComponent(wxSRComponent* child) {
	if (child != NULL) {
		wxSizer* child_sizer = new wxBoxSizer(wxVERTICAL);
		m_children_sizer->Add(child, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
		m_children_sizer->Add(child_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);
		child->SetChildrenSizer(child_sizer);
		m_children_sizer->Show(IsChecked());
	}
}

void wxSRComponent::AddComponent(wxSRComponent* child) {

	GetChildrenSizer();

	if (child)
		if (!FindChild(child)) {

			m_children.push_back(child);
			InsertComponent(child);
		}
}

void wxSRComponent::AddComponents(std::vector<wxSRComponent*> children) {
	std::vector<wxSRComponent*>::iterator iter;
	for (iter = children.begin(); iter != children.end(); iter++)
		AddComponent(*iter);
}

bool wxSRComponent::FindChild(wxSRComponent* child) {
	return find(m_children.begin(), m_children.end(), child) != m_children.end();
}

void wxSRComponent::SetValues(std::map<std::string, wxString> values) {

	std::map<std::string, wxString>::iterator iter;

	for (iter = values.begin(); iter != values.end(); iter++) {
		std::string key = iter->first;

		if (m_values.find(key) != m_values.end())
			m_values[key] = iter->second;
	}

	RefreshOnGui();
}

wxSRComponent::~wxSRComponent() {
}

bool wxSRComponent::IsChecked() {
	return false;
}

void wxSRComponent::RefreshSizers() {
  m_parent->FitInside();
  m_parent->Layout();
}
