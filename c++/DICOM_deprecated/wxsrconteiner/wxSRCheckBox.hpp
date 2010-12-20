#ifndef WXSRCHECKBOX_HPP_
#define WXSRCHECKBOX_HPP_

#include "./abstract/wxSRComponent.hpp"

class wxSRCheckBox : public wxSRComponent{

public:
	wxSRCheckBox(wxWindow* parent, wxString label);

	~wxSRCheckBox();

	virtual bool IsChecked();

	virtual void SetCheckValue(bool state);

protected:

	void CreateControls();

	virtual void RefreshOnGui();
	
private:
	wxCheckBox* m_checkbox;
	wxSizer* m_sizer;
};

#endif /*WXSRCHECKBOX_HPP_*/
