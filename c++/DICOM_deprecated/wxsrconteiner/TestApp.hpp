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

#include "wxSRHierarchicalConteiner.hpp"
#include "wxSRCheckBox.hpp"
#include "wxSRRadioBox.hpp"
#include "wxSRTextCtrl.hpp"
#include "wxSRTextBox.hpp"
#include "wxSRTextList.hpp"
#include "wxSRChoiceList.hpp"
#include <vector>

class TestApp : public wxApp {
	DECLARE_CLASS( DicomSrApp )

public:
	TestApp();
	void Init();
	virtual bool OnInit();
	virtual int OnExit();

private:
	wxSRComponent* m_checkbox_depth_1;
	wxSRComponent* m_other_checkbox_depth_1;
	
	std::vector<wxSRComponent*> m_checkbox_depth_1_children;
	std::vector<wxSRComponent*> m_other_checkbox_depth_1_children;
	
	wxSRComponent* m_checkbox_depth2;
	std::vector<wxSRComponent*> m_checkbox_depth2_children;
	
	wxSRComponent* m_checkbox_depth3;
	std::vector<wxSRComponent*> m_checkbox_depth3_children;	
	
	wxSRHierarchicalConteiner* conteiner;
	wxArrayString m_choices;
	
	void CreatCheckBoxes();
	
	void CreateRadioButtons();

};

DECLARE_APP( TestApp )

#endif /*TESTAPP_HPP_*/
