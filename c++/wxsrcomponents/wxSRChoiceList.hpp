#ifndef COMBOBOX_HPP_
#define COMBOBOX_HPP_

#include "./abstract/wxSROptionsComponent.hpp"
#include <vector>

class wxSRChoiceList : public wxSROptionsComponent {

public:
	/// Constructors
	wxSRChoiceList(wxWindow* parent, wxString label = _(""), wxArrayString choices = wxArrayString());

	/// Destructor
	virtual ~wxSRChoiceList();
	
	void OnClick(wxCommandEvent& event);

protected:
	/// Creates the controls and sizers
	void CreateControls();

	virtual void RefreshOnGui() {};

	virtual void AddOnSizer(wxSizer* children_sizer);
	

private:
	std::vector< std::vector<wxSRComponent> > m_children;
	wxStaticText* m_label_static_text;
	wxChoice* m_choicelist;
	wxFlexGridSizer* m_flexsizer;

	// This class handles events
	DECLARE_EVENT_TABLE()
};

#endif /*COMBOBOX_HPP_*/
