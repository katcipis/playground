#include "wxSRMultipleChoices..hpp"
#include <algorithm>

BEGIN_EVENT_TABLE(wxSRMultipleChoices, wxPanel)
EVT_CHECKBOX( ID_CHOICE, wxSRMultipleChoices::OnClick )
END_EVENT_TABLE()

wxSRMultipleChoices::wxSRMultipleChoices( wxWindow* parent, wxWindowID id ,
		const wxPoint& pos ,const wxSize& size, long style):
wxPanel(parent, id, pos, size, style) {
	CreateControls();
}

void wxSRMultipleChoices::CreateControls() {
	m_sizer = new wxBoxSizer(wxVERTICAL);

	SetSizer(m_sizer);

}

void wxSRMultipleChoices::AddCheckBox(wxCheckBox* parent,
		std::vector<wxCheckBox*> children) {

	if (Find(parent))

		RefreshCheckBox(parent, children);

	else

		AddNewCheckBox(parent, children);

}

void wxSRMultipleChoices::OnClick(wxCommandEvent& event) {
	std::map<wxCheckBox*, std::vector<wxCheckBox*> >::iterator iter;
	for (iter = m_checkbox_tree.begin(); iter != m_checkbox_tree.end(); iter ++) {
		wxCheckBox* tmp = iter->first;
		ShowChildren(tmp);
	}

}

void wxSRMultipleChoices::ShowChildren(wxCheckBox* choice) {

	if (Find(choice)) {
		wxSizer* sizer = m_sizer_associations[choice];
		bool is_checked = choice->IsChecked();

		if (!is_checked)
			UncheckChildren(choice);

		sizer->Show(is_checked);

		m_sizer->Layout();
	}

}

void wxSRMultipleChoices::AddNewCheckBox(wxCheckBox* parent,
		std::vector<wxCheckBox*> children) {

	wxSizer* children_sizer = new wxBoxSizer(wxVERTICAL);
	std::vector<wxCheckBox*> parent_children;
	
	m_sizer->Add(parent, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
	m_sizer->Add(children_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

	for (unsigned int i = 0; i < children.size(); i++) {

		wxCheckBox* tmp = children.at(i);

		if (!Find(tmp)) {
			wxSizer* tmp_sizer = new wxBoxSizer(wxVERTICAL);

			children_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
			children_sizer->Add(tmp_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

			m_sizer_associations[tmp] = tmp_sizer;
			m_checkbox_tree[tmp] = std::vector<wxCheckBox*>();
			
			parent_children.push_back(tmp);
		}

	}

	m_checkbox_tree[parent] = parent_children;
	m_sizer_associations[parent] = children_sizer;
	ShowChildren(parent);

}

void wxSRMultipleChoices::RefreshCheckBox(wxCheckBox* parent,
		std::vector<wxCheckBox*> children) {

	wxSizer* parent_sizer = m_sizer_associations[parent];
	std::vector<wxCheckBox*> parent_children = m_checkbox_tree[parent];

	for (unsigned int i = 0; i < children.size(); i++) {

		wxCheckBox* tmp = children.at(i);

		if (!Find(tmp)) {

			wxSizer* tmp_sizer = new wxBoxSizer(wxVERTICAL);

			parent_sizer->Add(tmp, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
			parent_sizer->Add(tmp_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT, 30);

			m_sizer_associations[tmp] = tmp_sizer;
			m_checkbox_tree[tmp] = std::vector<wxCheckBox*>();

			parent_children.push_back(tmp);

		}

	}

	m_checkbox_tree[parent] = parent_children;

	ShowChildren(parent);

}

bool wxSRMultipleChoices::Find(wxCheckBox* component) {

	bool has_sizer = m_sizer_associations.find(component)
			!= m_sizer_associations.end();
	bool is_on_tree = m_checkbox_tree.find(component) != m_checkbox_tree.end();

	return has_sizer && is_on_tree;
}

void wxSRMultipleChoices::UncheckChildren(wxCheckBox* choice) {
	if (Find(choice)) {

		std::vector<wxCheckBox*> children = m_checkbox_tree[choice];

		for (unsigned int i = 0; i < children.size(); i++) {

			wxCheckBox* child = children.at(i);

			child->SetValue(false);

			wxSizer* child_sizer = m_sizer_associations[child];

			if (child_sizer != NULL)
				child_sizer->Show(false);

			UncheckChildren(child);
		}

	}
}

bool wxSRMultipleChoices::HasSizer(wxCheckBox* component) {
	return m_sizer_associations.find(component) != m_sizer_associations.end();
}
