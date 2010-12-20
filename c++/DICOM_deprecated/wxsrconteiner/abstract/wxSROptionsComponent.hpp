#ifndef WXSROPTIONSCOMPONENT_HPP_
#define WXSROPTIONSCOMPONENT_HPP_

#include "./wxSRComponent.hpp"

class wxSROptionsComponent: public wxSRComponent {    

public:
	wxSROptionsComponent( wxWindow* parent, const wxString& label = _(""), wxArrayString choices = wxArrayString() );
  
  virtual ~wxSROptionsComponent();
    
protected:
	wxArrayString m_choices;
	
};

#endif /*WXSROPTIONSCOMPONENT_HPP_*/
