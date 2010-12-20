#include "wxSROptionsComponent.hpp"

wxSROptionsComponent::wxSROptionsComponent( wxWindow* parent, const wxString& label, 
		                                        wxArrayString choices) : wxSRComponent(parent, label){
	m_choices = choices;
}
  
wxSROptionsComponent::~wxSROptionsComponent(){
	
}
