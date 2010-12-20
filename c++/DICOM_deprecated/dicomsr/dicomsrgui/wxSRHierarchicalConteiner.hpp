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

#include "./abstract/wxSRGenericComponent.hpp"

class wxSRHierarchicalConteiner : public wxPanel {

public:
	wxSRHierarchicalConteiner(wxWindow* parent, wxWindowID id,
			const wxPoint& pos, const wxSize& size, long style);
	virtual ~wxSRHierarchicalConteiner() {};
	
	void OnClick(wxCommandEvent& event);
	
	void AddComponent(wxSRGenericComponent* parent, std::vector<wxSRGenericComponent*> children);
	
	bool Find(wxSRGenericComponent* component);

private:
	wxSizer* m_sizer;
	std::map<wxSRGenericComponent*, std::vector<wxSRGenericComponent*> > m_checkbox_tree;
	std::map<wxSRGenericComponent*, wxSizer* > m_sizer_associations;

	void CreateControls();
	
	void ShowChildren(wxSRGenericComponent* choice);
	
	void AddNewComponent(wxSRGenericComponent* parent, std::vector<wxSRGenericComponent*> children);
	
	void RefreshComponent(wxSRGenericComponent* parent, std::vector<wxSRGenericComponent*> children);

	void UncheckChildren(wxSRGenericComponent* choice);
	
	bool HasSizer(wxSRGenericComponent* component);
	
	// This class handles events
	DECLARE_EVENT_TABLE()
};


#endif /*WXHIERARCHICALWINDOWS_HPP_*/
