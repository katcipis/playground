#ifndef _WXSRTEXTLIST__
#define _WXSRTEXTLIST__

#include "wx/combo.h"
#include "./abstract/wxSROptionsComponent.hpp"

class wxSRTextList : public wxSROptionsComponent {

public:
	wxSRTextList(wxWindow* parent, const wxString& label = _(""), wxArrayString choice = wxArrayString());

	virtual ~wxSRTextList();
	
	void OnClick(wxCommandEvent& event);

protected:
	void CreateControls();

	virtual void RefreshOnGui() {};

	virtual void AddOnSizer(wxSizer* children_sizer);

private:
	wxString m_label;
	wxChoice* m_combo;
	wxFlexGridSizer* m_flexsizer;

	// This class handles events
	DECLARE_EVENT_TABLE()

};

#endif
// _WXSRTEXTLIST__
