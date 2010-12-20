#include "wxSRGenericComponent.hpp"

wxSRGenericComponent::wxSRGenericComponent(wxWindow* parent, wxString label) :
	wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL) {

	m_label = label;
}

std::map<std::string, std::string> wxSRGenericComponent::GetValues(){
	return m_map;
}

wxSRGenericComponent::~wxSRGenericComponent() { }
