#include "wxSRHierarchicalConteiner.hpp"
#include <algorithm>

BEGIN_EVENT_TABLE(wxSRHierarchicalConteiner, wxPanel)
	EVT_CHECKBOX( wxID_ANY, wxSRHierarchicalConteiner::OnClick )
END_EVENT_TABLE()

wxSRHierarchicalConteiner::wxSRHierarchicalConteiner( wxWindow* parent, wxWindowID id ,
		const wxPoint& pos ,const wxSize& size, long style):
wxPanel(parent, id, pos, size, style) {
	CreateControls();
}

void wxSRHierarchicalConteiner::CreateControls() {
	m_sizer = new wxBoxSizer(wxVERTICAL);

	SetSizer(m_sizer);

}

void wxSRHierarchicalConteiner::AddComponent(wxSRGenericComponent* parent,
		std::vector<wxSRGenericComponent*> children) {

	if (Find(parent))

		RefreshComponent(parent, children);

	else

		AddNewComponent(parent, children);

}

void wxSRHierarchicalConteiner::OnClick(wxCommandEvent& event) {

	std::map<wxSRGenericComponent*, std::vector<wxSRGenericComponent*> >::iterator iter;
	for (iter = m_checkbox_tree.begin(); iter != m_checkbox_tree.end(); iter ++) {
		wxSRGenericComponent* tmp = iter->first;
		ShowChildren(tmp);
	}

}

void wxSRHierarchicalConteiner::ShowChildren(wxSRGenericComponent* choice) {

	if (Find(choice)) {
		wxSizer* sizer = m_sizer_associations[choice];

		bool is_checked = choice->IsChecked();

		if (!is_checked)
			UncheckChildren(choice);
		
		sizer->Show(is_checked);
	
		m_sizer->Layout();
	}

}

void wxSRHierarchicalConteiner::AddNewComponent(wxSRGenericComponent* parent,
		std::vector<wxSRGenericComponent*> children) {

	wxSizer* children_sizer = new wxBoxSizer(wxVERTICAL);
	std::vector<wxSRGenericComponent*> parent_children;

	m_sizer->Add(parent, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
	m_sizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

	for (unsigned int i = 0; i < children.size(); i++) {

		wxSRGenericComponent* tmp = children.at(i);

		if (!Find(tmp)) {
			wxSizer* tmp_sizer = new wxBoxSizer(wxVERTICAL);

			children_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
			children_sizer->Add(tmp_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

			m_sizer_associations[tmp] = tmp_sizer;
			m_checkbox_tree[tmp] = std::vector<wxSRGenericComponent*>();

			parent_children.push_back(tmp);
		}

	}

	m_checkbox_tree[parent] = parent_children;
	m_sizer_associations[parent] = children_sizer;
	ShowChildren(parent);

}

void wxSRHierarchicalConteiner::RefreshComponent(wxSRGenericComponent* parent,
		std::vector<wxSRGenericComponent*> children) {

	wxSizer* parent_sizer = m_sizer_associations[parent];
	std::vector<wxSRGenericComponent*> parent_children = m_checkbox_tree[parent];

	for (unsigned int i = 0; i < children.size(); i++) {

		wxSRGenericComponent* tmp = children.at(i);

		if (!Find(tmp)) {

			wxSizer* tmp_sizer = new wxBoxSizer(wxVERTICAL);

			parent_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
			parent_sizer->Add(tmp_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

			m_sizer_associations[tmp] = tmp_sizer;
			m_checkbox_tree[tmp] = std::vector<wxSRGenericComponent*>();

			parent_children.push_back(tmp);

		}

	}

	m_checkbox_tree[parent] = parent_children;

	ShowChildren(parent);

}

bool wxSRHierarchicalConteiner::Find(wxSRGenericComponent* component) {

	bool has_sizer = m_sizer_associations.find(component)
			!= m_sizer_associations.end();
	bool is_on_tree = m_checkbox_tree.find(component) != m_checkbox_tree.end();

	return has_sizer && is_on_tree;
}

void wxSRHierarchicalConteiner::UncheckChildren(wxSRGenericComponent* choice) {
	if (Find(choice)) {

		std::vector<wxSRGenericComponent*> children = m_checkbox_tree[choice];

		for (unsigned int i = 0; i < children.size(); i++) {

			wxSRGenericComponent* child = children.at(i);

			child->SetCheckValue(false);

			wxSizer* child_sizer = m_sizer_associations[child];

			if (child_sizer != NULL)
				child_sizer->Show(false);

			UncheckChildren(child);
		}

	}
}


bool wxSRHierarchicalConteiner::HasSizer(wxSRGenericComponent* component) {
	return m_sizer_associations.find(component) != m_sizer_associations.end();
}
