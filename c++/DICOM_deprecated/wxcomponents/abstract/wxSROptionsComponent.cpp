#include "wxSROptionsComponent.hpp"

wxSROptionsComponent::wxSROptionsComponent(wxWindow* parent, wxString label, wxArrayString choices) :
	wxSRGenericComponent(parent, label){
	
	m_choices = choices;
}

wxSROptionsComponent::~wxSROptionsComponent(){}
