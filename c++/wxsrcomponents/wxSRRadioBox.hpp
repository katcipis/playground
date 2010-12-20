#ifndef WXSRRADIOBOX_HPP_
#define WXSRRADIOBOX_HPP_

#include "./abstract/wxSROptionsComponent.hpp"

class wxSRRadioBox : public wxSROptionsComponent {

public:
	wxSRRadioBox(wxWindow* parent, wxString label = _(""), wxArrayString choices = wxArrayString());

	virtual ~wxSRRadioBox();

	void OnClick(wxCommandEvent& event);
	
protected:

	void CreateControls();

	virtual void RefreshOnGui();

	virtual void AddOnSizer(wxSizer* children_sizer);
	
	virtual void RefreshState(wxCommandEvent& event, bool state = false);
	

private:
	wxRadioBox* m_radiobox;
	wxSizer* m_sizer;
	
	// This class handles events
	DECLARE_EVENT_TABLE()
};

#endif /*WXSRRADIOBOX_HPP_*/
