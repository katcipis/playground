#ifndef DRCHECKLISTBOX_HPP_
#define DRCHECKLISTBOX_HPP_

#define ID_DRCHECKLISTBOX 10003
#include "./abstract/wxSROptionsComponent.hpp"

class wxSRCheckListBox : public wxSROptionsComponent {

public:
	/// Constructors
	wxSRCheckListBox(wxWindow* parent, wxString label, wxArrayString choices);

	/// Destructor
	~wxSRCheckListBox();

	virtual void SetValues(std::map<std::string, std::string> map) {};

protected:
	/// Creates the controls and sizers
	void CreateControls();

private:

	void AddChoices();

	wxStaticBox* m_static_box;
	wxStaticBoxSizer* m_static_box_sizer;

};

#endif /*DRCHECKLISTBOX_HPP_*/
