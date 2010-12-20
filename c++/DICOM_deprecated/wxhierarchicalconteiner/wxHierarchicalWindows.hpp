#ifndef WXHIERARCHICALWINDOWS_HPP_
#define WXHIERARCHICALWINDOWS_HPP_

#include "wx/frame.h"
#include "wx/wxprec.h"
#include <wx/scrolwin.h>
#include <vector>
#include <map>

#define ID_FRAME 10035

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class wxHierarchicalWindows : public wxPanel {

public:
	wxHierarchicalWindows(wxWindow* parent, wxWindowID id,
			const wxPoint& pos, const wxSize& size, long style);
	virtual ~wxHierarchicalWindows() {};
	
	void OnClick(wxCommandEvent& event);
	
	void AddCheckBox(wxWindow* parent, std::vector<wxWindow*> children);
	
	bool Find(wxWindow* component);

private:
	wxSizer* m_sizer;
	std::map<wxWindow*, std::vector<wxWindow*> > m_checkbox_tree;
	std::map<wxWindow*, wxSizer* > m_sizer_associations;

	void CreateControls();
	
	void ShowChildren(wxWindow* choice);
	
	bool IsChecked(wxWindow* window);
	
	void UncheckChild(wxWindow* child);
	
	void AddNewCheckBox(wxWindow* parent, std::vector<wxWindow*> children);
	
	void RefreshCheckBox(wxWindow* parent, std::vector<wxWindow*> children);

	void UncheckChildren(wxWindow* choice);
	
	bool HasSizer(wxWindow* component);
	
	// This class handles events
	DECLARE_EVENT_TABLE()
};


#endif /*WXHIERARCHICALWINDOWS_HPP_*/
