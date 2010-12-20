#ifndef TEXTCTRL_
#define TEXTCTRL_

#include "./abstract/wxSRComponent.hpp"

class wxSRTextCtrl : public wxSRComponent {

public:
	/// Constructors
	wxSRTextCtrl(wxWindow* parent, wxString label);

	/// Destructor
	virtual ~wxSRTextCtrl();

	virtual void SetCheckValue(bool state){};

	virtual void RefreshState(wxCommandEvent& event, bool state){};

protected:

	/// Creates the controls and sizers
	virtual void CreateControls();

	virtual void RefreshOnGui() {};

	virtual void AddOnSizer(wxSizer* children_sizer);

private:

	wxString m_text_ctrl_label;
	wxStaticText* m_label_static_text;
	wxTextCtrl* m_text_ctrl;
	wxFlexGridSizer* m_flexsizer;

};

#endif /*TEXTCTRL_*/
