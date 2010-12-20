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

#include "./abstract/wxSRComponent.hpp"

class wxSRHierarchicalConteiner : public wxPanel {

public:
	wxSRHierarchicalConteiner(wxWindow* parent, wxWindowID id,
			const wxPoint& pos, const wxSize& size, long style = wxNO_BORDER|wxTAB_TRAVERSAL);
	virtual ~wxSRHierarchicalConteiner() {};
	
	void OnClick(wxCommandEvent& event);
	
	void AddComponent(wxSRComponent* parent, std::vector<wxSRComponent*> children);
	
	bool Find(wxSRComponent* component);

private:
	wxSizer* m_sizer;
	std::map<wxSRComponent*, std::vector<wxSRComponent*> > m_checkbox_tree;
	std::map<wxSRComponent*, wxSizer* > m_sizer_associations;

	void CreateControls();
	
	void ShowChildren(wxSRComponent* choice);
	
	void AddNewComponent(wxSRComponent* parent, std::vector<wxSRComponent*> children);
	
	void RefreshComponent(wxSRComponent* parent, std::vector<wxSRComponent*> children);

	void UncheckChildren(wxSRComponent* choice);
	
	bool HasSizer(wxSRComponent* component);
	
	// This class handles events
	DECLARE_EVENT_TABLE()
};


#endif /*WXHIERARCHICALWINDOWS_HPP_*/
