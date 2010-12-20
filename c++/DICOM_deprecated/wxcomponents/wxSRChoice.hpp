#ifndef COMBOBOX_HPP_
#define COMBOBOX_HPP_

#define ID_CHOICE 10002
#include "./abstract/wxSROptionsComponent.hpp"

class wxSRChoice : public wxSROptionsComponent {

public:
	/// Constructors
	wxSRChoice(wxWindow* parent, wxString label, wxArrayString choices);

	/// Destructor
	~wxSRChoice();

	virtual void SetValues(std::map<std::string, std::string> map) {};

protected:
	/// Creates the controls and sizers
	void CreateControls();

private:
	wxStaticText* m_label_static_text;
	wxChoice* m_combo_box;

};

#endif /*COMBOBOX_HPP_*/
