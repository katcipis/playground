#include "TestApp.hpp"

IMPLEMENT_APP( TestApp )
IMPLEMENT_CLASS( TestApp, wxApp )

TestApp::TestApp() {
	Init();
}

int TestApp::OnExit() {
	return 0;
}

void TestApp::Init() {
}

bool TestApp::OnInit() {
#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif

	wxFrame
			* frame =
					new wxFrame( NULL, wxID_ANY,_("teste"), wxDefaultPosition, wxSize(200, 600), wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX|wxRESIZE_BORDER|wxVSCROLL|wxTAB_TRAVERSAL);

  m_panel = new wxScrolledWindow(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxVSCROLL|wxCLIP_CHILDREN  );
  m_panel->SetScrollbars(20, 20, 50, 50);
  
	m_options.Add(_("Choice 1"));
	m_options.Add(_("Choice 2"));
	m_options.Add(_("Choice 3"));
	
	m_data = new wxSRData(m_panel, _("Data Picker"));
	choice_list = new wxSRChoiceList(m_panel, _("Choice List"), m_options);
	radio_box = new wxSRRadioBox(m_panel, _("Radio Box"), m_options);
	text_box = new wxSRTextBox(m_panel, _("TextBox"));
	text_ctrl = new wxSRTextCtrl(m_panel, _("TextCtrl"));
	text_list = new wxSRTextList(m_panel, _("Text List"), m_options);

	m_sizer = new wxBoxSizer(wxVERTICAL);
	m_panel->SetSizer(m_sizer);

	root_one = new wxSRCheckBox(m_panel, _("Root One"));
	root_two = new wxSRCheckBox(m_panel, _("Root Two"));
	
	m_sizer->Add(m_data,0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxGROW, 0);

	m_sizer->Add(root_one, 0, wxALIGN_CENTER_VERTICAL|wxGROW|wxALL, 0);
	m_sizer->Add(root_one->GetChildrenSizer(), 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxGROW, 20);

	m_sizer->Add(root_two, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);
	m_sizer->Add(root_two->GetChildrenSizer(), 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxGROW,20);

	CreateAndInsertDepthOneChildren(m_panel);
	
	m_panel->FitInside();
	m_panel->Layout();
	
	frame->Show();
	return true;
}

void TestApp::CreateAndInsertDepthOneChildren(wxPanel* panel) {

	root_1_child1 = new wxSRCheckBox(panel, _("Checkbox"));
	root_1_child2 = new wxSRCheckBox(panel, _("Checkbox"));
	root_1_child3 = new wxSRCheckBox(panel, _("Checkbox"));

	root_2_child1 = new wxSRCheckBox(panel, _("Checkbox"));
	root_2_child2 = new wxSRCheckBox(panel, _("Checkbox"));
	root_2_child3 = new wxSRCheckBox(panel, _("Checkbox"));

	root_one->AddComponent(root_1_child1);
	root_one->AddComponent(root_1_child2);
	root_one->AddComponent(root_1_child3);

	root_two->AddComponent(root_2_child1);
	root_two->AddComponent(root_2_child2);
	root_two->AddComponent(root_2_child3);

	wxSRComponent* tmp = new wxSRCheckBox(panel, _("Checkbox"));

	for (int i = 0; i <= 2; i++) {

		root_1_child2->AddComponent(new wxSRCheckBox(panel, _("Checkbox")));

		root_2_child3->AddComponent(new wxSRCheckBox(panel, _("Checkbox")));

	}

	root_1_child2->AddComponent(tmp);

	tmp->AddComponent(text_box);

	root_1_child1->AddComponent(choice_list);

	root_2_child3->AddComponent(radio_box);

	std::vector<wxSRComponent*> wurul = root_1_child2->GetChildren();
	if (wurul.front()) {
		wxSRComponent* aux = wurul.front();
		if (aux) {
			aux->AddComponent(text_list);
			aux->AddComponent(text_ctrl);
		}
	}

	radio_box->AddComponent(_("Choice 1"), new wxSRCheckBox(panel, _("Checkbox Choice 1")));
	radio_box->AddComponent(_("Choice 1"), new wxSRChoiceList(panel, _("Choice List Choice 1"), m_options));

	radio_box->AddComponent(_("Choice 2"), new wxSRCheckBox(panel, _("Checkbox Choice 2")));
	radio_box->AddComponent(_("Choice 2"), new wxSRTextCtrl(panel, _("TextCtrl Choice 2")));

	radio_box->AddComponent(_("Choice 3"), new wxSRTextList(panel, _("TextList Choice 3"), m_options));
	radio_box->AddComponent(_("Choice 3"), new wxSRCheckBox(panel, _("Checkbox Choice 3")));

	
	text_list->AddComponent(_("Choice 1"), new wxSRTextCtrl(panel, _("TextCtrl Choice 1")));
	text_list->AddComponent(_("Choice 1"), new wxSRChoiceList(panel, _("Choice List Choice 1"), m_options));

	text_list->AddComponent(_("Choice 2"), new wxSRCheckBox(panel, _("Checkbox Choice 2")));
	text_list->AddComponent(_("Choice 2"), new wxSRTextCtrl(panel, _("TextCtrl Choice 2")));

	text_list->AddComponent(_("Choice 3"), new wxSRTextList(panel, _("TextList Choice 3"), m_options));
	text_list->AddComponent(_("Choice 3"), new wxSRCheckBox(panel, _("Checkbox Choice 3")));
	
	choice_list->AddComponent(_("Choice 1"), new wxSRTextBox(panel, _("TextBox Choice 1")));
	choice_list->AddComponent(_("Choice 1"), new wxSRChoiceList(panel, _("Choice List Choice 1"), m_options));

	choice_list->AddComponent(_("Choice 2"), new wxSRCheckBox(panel, _("Checkbox Choice 2")));
	choice_list->AddComponent(_("Choice 2"), new wxSRTextCtrl(panel, _("TextCtrl Choice 2")));

	choice_list->AddComponent(_("Choice 3"), new wxSRTextList(panel, _("TextList Choice 3"), m_options));
	
	wxSRComponent* tmp2 = new wxSRCheckBox(panel, _("Checkbox Choice 3"));
	choice_list->AddComponent(_("Choice 3"), tmp2);
	
	tmp2->AddComponent(new wxSRCheckBox(panel, _("Checkbox")));
	tmp2->AddComponent(new wxSRTextCtrl(panel, _("TextCtrl Choice 2")));
	
	panel->FitInside();
	panel->Layout();

}


