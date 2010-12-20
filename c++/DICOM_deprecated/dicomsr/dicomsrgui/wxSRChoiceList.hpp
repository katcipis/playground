#ifndef COMBOBOX_HPP_
#define COMBOBOX_HPP_

#define ID_CHOICE 10002
#include "./abstract/wxSROptionsComponent.hpp"

class wxSRChoiceList : public wxSROptionsComponent {

public:
	/// Constructors
	wxSRChoiceList(wxWindow* parent, wxString label, wxArrayString choices);

	/// Destructor
	~wxSRChoiceList();


protected:
	/// Creates the controls and sizers
	void CreateControls();
	
	virtual void RefreshOnGui(){};

private:
	wxStaticText* m_label_static_text;
	wxChoice* m_combo_box;

};

#endif /*COMBOBOX_HPP_*/
