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

#include "wxSRCheckBox.hpp"
#include "wxSRRadioBox.hpp"
#include "wxSRTextCtrl.hpp"
#include "wxSRTextBox.hpp"
#include "wxSRTextList.hpp"
#include "wxSRChoiceList.hpp"
#include "wxSRData.hpp"
#include <vector>

class TestApp : public wxApp {
	DECLARE_CLASS( DicomSrApp )

public:
	TestApp();
	void Init();
	virtual bool OnInit();
	virtual int OnExit();

private:
	
	void CreateAndInsertDepthOneChildren(wxPanel* frame);

	wxSizer* m_sizer;
	
	wxSRComponent* m_data;
	wxSRComponent* root_one;
	wxSRComponent* root_1_child1;
	wxSRComponent* root_1_child2;
	wxSRComponent* root_1_child3;

	wxSRComponent* root_two;
	wxSRComponent* root_2_child1;
	wxSRComponent* root_2_child2;
	wxSRComponent* root_2_child3;
	
	wxSROptionsComponent* choice_list;
	wxSROptionsComponent* radio_box;
	wxSRComponent* text_box;
	wxSRComponent* text_ctrl;
	wxSROptionsComponent* text_list;
	wxScrolledWindow* m_panel;
	
	wxArrayString m_options;
};

DECLARE_APP( TestApp )

#endif /*TESTAPP_HPP_*/
