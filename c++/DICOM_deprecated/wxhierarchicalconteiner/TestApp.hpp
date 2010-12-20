#ifndef TESTAPP_HPP_
#define TESTAPP_HPP_

#include "wx/image.h"
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wxHierarchicalWindows.hpp"
#include <vector>

class TestApp : public wxApp {
	DECLARE_CLASS( DicomSrApp )

public:
	TestApp();
	void Init();
	virtual bool OnInit();
	virtual int OnExit();

private:
	wxWindow* m_depth_1;
	wxWindow* m_other_depth_1;
	
	std::vector<wxWindow*> m_depth_1_children;
	std::vector<wxWindow*> m_other_depth_1_children;
	
	wxWindow* m_depth2;
	std::vector<wxWindow*> m_depth2_children;
	
	wxWindow* m_depth3;
	std::vector<wxWindow*> m_depth3_children;
	
	wxHierarchicalWindows* panel;
	
	void CreatCheckBoxes();

};

DECLARE_APP( TestApp )

#endif /*TESTAPP_HPP_*/
