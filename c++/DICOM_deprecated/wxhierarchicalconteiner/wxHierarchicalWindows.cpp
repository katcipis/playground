#include "wxHierarchicalWindows.hpp"
#include <algorithm>

BEGIN_EVENT_TABLE(wxHierarchicalWindows, wxPanel)
EVT_CHECKBOX( wxID_ANY, wxHierarchicalWindows::OnClick )
END_EVENT_TABLE()

wxHierarchicalWindows::wxHierarchicalWindows( wxWindow* parent, wxWindowID id ,
		const wxPoint& pos ,const wxSize& size, long style):
wxPanel(parent, id, pos, size, style) {
	CreateControls();
}

void wxHierarchicalWindows::CreateControls() {
	m_sizer = new wxBoxSizer(wxVERTICAL);

	SetSizer(m_sizer);

}

void wxHierarchicalWindows::AddCheckBox(wxWindow* parent,
		std::vector<wxWindow*> children) {

	if (Find(parent))

		RefreshCheckBox(parent, children);

	else

		AddNewCheckBox(parent, children);

}

void wxHierarchicalWindows::OnClick(wxCommandEvent& event) {

	std::map<wxWindow*, std::vector<wxWindow*> >::iterator iter;
	for (iter = m_checkbox_tree.begin(); iter != m_checkbox_tree.end(); iter ++) {
		wxWindow* tmp = iter->first;
		ShowChildren(tmp);
	}

}

bool wxHierarchicalWindows::IsChecked(wxWindow* window) {
	wxCheckBox* checkbox = dynamic_cast<wxCheckBox*>(window);

	if (checkbox)
		return checkbox->IsChecked();

	return false;
}

void wxHierarchicalWindows::ShowChildren(wxWindow* choice) {

	if (Find(choice)) {
		wxSizer* sizer = m_sizer_associations[choice];

		bool is_checked = IsChecked(choice);

		if (!is_checked)
			UncheckChildren(choice);

		sizer->Show(is_checked);

		m_sizer->Layout();
	}

}

void wxHierarchicalWindows::AddNewCheckBox(wxWindow* parent,
		std::vector<wxWindow*> children) {

	wxSizer* children_sizer = new wxBoxSizer(wxVERTICAL);
	std::vector<wxWindow*> parent_children;

	m_sizer->Add(parent, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
	m_sizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

	for (unsigned int i = 0; i < children.size(); i++) {

		wxWindow* tmp = children.at(i);

		if (!Find(tmp)) {
			wxSizer* tmp_sizer = new wxBoxSizer(wxVERTICAL);

			children_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
			children_sizer->Add(tmp_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

			m_sizer_associations[tmp] = tmp_sizer;
			m_checkbox_tree[tmp] = std::vector<wxWindow*>();

			parent_children.push_back(tmp);
		}

	}

	m_checkbox_tree[parent] = parent_children;
	m_sizer_associations[parent] = children_sizer;
	ShowChildren(parent);

}

void wxHierarchicalWindows::RefreshCheckBox(wxWindow* parent,
		std::vector<wxWindow*> children) {

	wxSizer* parent_sizer = m_sizer_associations[parent];
	std::vector<wxWindow*> parent_children = m_checkbox_tree[parent];

	for (unsigned int i = 0; i < children.size(); i++) {

		wxWindow* tmp = children.at(i);

		if (!Find(tmp)) {

			wxSizer* tmp_sizer = new wxBoxSizer(wxVERTICAL);

			parent_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
			parent_sizer->Add(tmp_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

			m_sizer_associations[tmp] = tmp_sizer;
			m_checkbox_tree[tmp] = std::vector<wxWindow*>();

			parent_children.push_back(tmp);

		}

	}

	m_checkbox_tree[parent] = parent_children;

	ShowChildren(parent);

}

bool wxHierarchicalWindows::Find(wxWindow* component) {

	bool has_sizer = m_sizer_associations.find(component)
			!= m_sizer_associations.end();
	bool is_on_tree = m_checkbox_tree.find(component) != m_checkbox_tree.end();

	return has_sizer && is_on_tree;
}

void wxHierarchicalWindows::UncheckChildren(wxWindow* choice) {
	if (Find(choice)) {

		std::vector<wxWindow*> children = m_checkbox_tree[choice];

		for (unsigned int i = 0; i < children.size(); i++) {

			wxWindow* child = children.at(i);

			UncheckChild(child);

			wxSizer* child_sizer = m_sizer_associations[child];

			if (child_sizer != NULL)
				child_sizer->Show(false);

			UncheckChildren(child);
		}

	}
}

void wxHierarchicalWindows::UncheckChild(wxWindow* child) {
	
	wxCheckBox* checkbox = dynamic_cast<wxCheckBox*>(child);

	if(checkbox)
		checkbox->SetValue(false);
}

bool wxHierarchicalWindows::HasSizer(wxWindow* component) {
	return m_sizer_associations.find(component) != m_sizer_associations.end();
}
