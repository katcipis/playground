#ifndef RADIOBOX_HPP_
#define RADIOBOX_HPP_

#define ID_RADIOBOX 10003
#include "./abstract/wxSROptionsComponent.hpp"

class wxSRRadioBox : public wxSROptionsComponent {

public:
	wxSRRadioBox(wxWindow* parent, wxString label, wxArrayString choices);

	~wxSRRadioBox();

protected:

	void CreateControls();
	
	virtual void RefreshOnGui(){};
	
private:
	wxStaticBox* m_static_box;
	wxStaticBoxSizer* m_static_box_sizer;
	void AddChoices();
};

#endif /*RADIOBOX_HPP_*/
