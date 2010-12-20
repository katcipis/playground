#ifndef TESTFRAME_HPP_
#define TESTFRAME_HPP_

#include "wx/frame.h"
#include "wx/wxprec.h"
#include <wx/scrolwin.h>
#include <vector>
#include <map>

#define ID_CHOICE 10030
#define ID_FRAME 10035

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class wxSRMultipleChoices : public wxPanel {

public:
	wxSRMultipleChoices(wxWindow* parent, wxWindowID id,
			const wxPoint& pos, const wxSize& size, long style);
	virtual ~wxSRMultipleChoices() {};
	
	void OnClick(wxCommandEvent& event);
	
	void AddCheckBox(wxCheckBox* parent, std::vector<wxCheckBox*> children);
	
	bool Find(wxCheckBox* component);

private:
	wxSizer* m_sizer;
	std::map<wxCheckBox*, std::vector<wxCheckBox*> > m_checkbox_tree;
	std::map<wxCheckBox*, wxSizer* > m_sizer_associations;

	void CreateControls();
	
	void ShowChildren(wxCheckBox* choice);
	
	void AddNewCheckBox(wxCheckBox* parent, std::vector<wxCheckBox*> children);
	
	void RefreshCheckBox(wxCheckBox* parent, std::vector<wxCheckBox*> children);

	void UncheckChildren(wxCheckBox* choice);
	
	bool HasSizer(wxCheckBox* component);
	
	// This class handles events
	DECLARE_EVENT_TABLE()
};

#endif /*TESTFRAME_HPP_*/
