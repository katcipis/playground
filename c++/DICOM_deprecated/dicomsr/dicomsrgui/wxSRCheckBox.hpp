#ifndef WXSRCHECKBOX_HPP_
#define WXSRCHECKBOX_HPP_

#include "./abstract/wxSRGenericComponent.hpp"

class wxSRCheckBox : public wxSRGenericComponent{

public:
	wxSRCheckBox(wxWindow* parent, wxString label);

	~wxSRCheckBox();

	virtual bool IsChecked();

	virtual void SetCheckValue(bool state);

protected:

	void CreateControls();

	virtual void RefreshOnGui();
	
private:
	wxSizer* m_sizer;
	wxCheckBox* m_checkbox;
};

#endif /*WXSRCHECKBOX_HPP_*/
