#include "wxSRGenericComponent.hpp"

wxSRGenericComponent::wxSRGenericComponent(wxWindow* parent, wxString label) :
	wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL) {
	m_parent = parent;
	m_label = label;
	m_values["label"] = label;
}

std::map<std::string, wxString> wxSRGenericComponent::GetValues(){
	return m_values;
}


void wxSRGenericComponent::SetValues(std::map<std::string, wxString> values){
	
	std::map<std::string, wxString>::iterator iter;
	
	for(iter = values.begin(); iter != values.end(); iter++){
		std::string key = iter->first;
		
		if(m_values.find(key) != m_values.end())
			m_values[key] = iter->second;
	}
	
	RefreshOnGui();
}

wxSRGenericComponent::~wxSRGenericComponent() { }

bool wxSRGenericComponent::IsChecked(){
	return false;
}

void wxSRGenericComponent::SetCheckValue(bool state){ }
