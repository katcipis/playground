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
			* frame =new wxFrame( NULL, wxID_ANY,_("teste"), wxDefaultPosition, wxSize(800, 600), wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX|wxRESIZE_BORDER|wxVSCROLL|wxTAB_TRAVERSAL);
	conteiner = new wxSRHierarchicalConteiner(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	m_choices.Add(_("Choice 1"));
	m_choices.Add(_("Choice 2"));
	m_choices.Add(_("Choice 3"));
	
	CreatCheckBoxes();

	conteiner->AddComponent(m_checkbox_depth_1, m_checkbox_depth_1_children);
	conteiner->AddComponent(m_other_checkbox_depth_1, m_other_checkbox_depth_1_children);
	
	conteiner->AddComponent(m_checkbox_depth2, m_checkbox_depth2_children);
	conteiner->AddComponent(m_checkbox_depth3, m_checkbox_depth3_children);
	
	frame->Show();

	return true;
}

void TestApp::CreatCheckBoxes() {
	m_checkbox_depth_1 = new wxSRCheckBox(conteiner, _("CheckBox Depth 1"));
	m_other_checkbox_depth_1 = new wxSRCheckBox(conteiner, _("CheckBox Other Depth 1"));

	for (int i = 0; i <= 2; i++) {
		m_checkbox_depth_1_children.push_back(new wxSRCheckBox(conteiner, _("CheckBox Depth 1 Children")));
		m_other_checkbox_depth_1_children.push_back(new wxSRCheckBox(conteiner, _("Other CheckBox Depth 1 Children")));
	}
	
	m_checkbox_depth_1_children.push_back(new wxSRTextCtrl(conteiner, _("TextCtrl Depth 1 Children")));
	
	m_other_checkbox_depth_1_children.push_back(new wxSRTextList(conteiner, _("TextList  Depth 1 Children"), m_choices));
	m_other_checkbox_depth_1_children.push_back(new wxSRRadioBox(conteiner,_("RadioBox Depth 3 Children"), m_choices));
	
	m_checkbox_depth2 = m_checkbox_depth_1_children.at(1);

	m_checkbox_depth2_children.push_back(new wxSRChoiceList(conteiner,_("Choice List Depth 2 Children"), m_choices));
	
	for (int i = 0; i <= 2; i++)
		m_checkbox_depth2_children.push_back(new wxSRCheckBox(conteiner,_("CheckBox Depth 2 Children")));
	
	m_checkbox_depth2_children.push_back(new wxSRTextBox(conteiner,_("TextBox Depth 2 Children")));

	m_checkbox_depth3 = m_checkbox_depth2_children.at(1);
  m_checkbox_depth3_children.push_back(new wxSRCheckBox(conteiner,_("CheckBox Depth 3 Children")));
	m_checkbox_depth3_children.push_back(new wxSRTextCtrl(conteiner,_("TextCtrl Depth 3 Children")));
	

}
