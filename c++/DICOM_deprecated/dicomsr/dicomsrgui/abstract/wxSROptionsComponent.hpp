#ifndef WXOPTIONSCCOMPONENT_HPP_
#define WXOPTIONSCCOMPONENT_HPP_

#include "wxSRGenericComponent.hpp"

class wxSROptionsComponent : public wxSRGenericComponent {

public:

	wxSROptionsComponent(wxWindow* parent, wxString label, wxArrayString choices);

	/// Destructor
	virtual ~wxSROptionsComponent();

protected:
	wxArrayString m_choices;

};

#endif /*WXOPTIONSCCOMPONENT_HPP_*/
