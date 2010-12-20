#ifndef WXSRDATA_HPP_
#define WXSRDATA_HPP_

#include "./abstract/wxSRComponent.hpp"
#include <wx/datectrl.h>

class wxSRData: public wxSRComponent {

public:
	wxSRData(wxWindow* parent, wxString label);
	
	virtual ~wxSRData();
	
	virtual void SetCheckValue(bool state){};

	virtual void RefreshState(wxCommandEvent& event, bool state);
	
protected:

	/// Creates the controls and sizers
	virtual void CreateControls();

	virtual void RefreshOnGui() {};

	virtual void AddOnSizer(wxSizer* children_sizer);
	
private:

	wxString m_text_ctrl_label;
	wxStaticText* m_label_static_text;
	wxDatePickerCtrl* m_data_picker;
	wxFlexGridSizer* m_flexsizer;

};

#endif /*WXSRDATA_HPP_*/
