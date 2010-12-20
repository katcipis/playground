#ifndef WXSRCHECKBOX_HPP_
#define WXSRCHECKBOX_HPP_

#include "./abstract/wxSRComponent.hpp"

class wxSRCheckBox : public wxSRComponent {

public:
	wxSRCheckBox(wxWindow* parent, wxString label);

	virtual ~wxSRCheckBox();

	virtual bool IsChecked();

	virtual void SetCheckValue(bool state);
	
	void OnClick(wxCommandEvent& event); 
	
	virtual void RefreshState(wxCommandEvent& event, bool state);

protected:

	void CreateControls();

	virtual void RefreshOnGui();

	virtual void AddOnSizer(wxSizer* children_sizer);
	

private:
	wxCheckBox* m_checkbox;
	wxSizer* m_sizer;

	void UncheckChildren(wxCommandEvent& event);

	// This class handles events
	DECLARE_EVENT_TABLE()
};

#endif /*WXSRCHECKBOX_HPP_*/
