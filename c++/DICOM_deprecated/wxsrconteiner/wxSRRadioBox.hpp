#ifndef WXSRRADIOBOX_HPP_
#define WXSRRADIOBOX_HPP_

#include "./abstract/wxSROptionsComponent.hpp"

class wxSRRadioBox : public wxSROptionsComponent {

public:
	wxSRRadioBox(wxWindow* parent, wxString label = _(""), wxArrayString choices = wxArrayString() );

	~wxSRRadioBox();

protected:

	void CreateControls();
	
	virtual void RefreshOnGui();
	
private:
	wxRadioBox* m_radiobox; 
	wxSizer* m_sizer;
};

#endif /*WXSRRADIOBOX_HPP_*/
