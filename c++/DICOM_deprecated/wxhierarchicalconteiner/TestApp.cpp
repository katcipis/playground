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
			* frame =new wxFrame( NULL, wxID_ANY,_("teste"), wxDefaultPosition, wxSize(600, 400), wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX|wxRESIZE_BORDER);
	panel = new wxHierarchicalWindows(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, -1);

	CreatCheckBoxes();

	panel->AddCheckBox(m_depth_1, m_depth_1_children);
	panel->AddCheckBox(m_other_depth_1, m_other_depth_1_children);
	panel->AddCheckBox(m_depth2, m_depth2_children);
	panel->AddCheckBox(m_depth3, m_depth3_children);

	frame->Show();

	return true;
}

void TestApp::CreatCheckBoxes() {
	m_depth_1 = new wxCheckBox(panel, wxID_ANY, _("Depth 1"));
	m_other_depth_1 = new wxCheckBox(panel, wxID_ANY, _("Other Depth 1"));

	for (int i = 0; i <= 2; i++) {
		m_depth_1_children.push_back(new wxCheckBox(panel, wxID_ANY, _("Depth 1 Children")));
		m_other_depth_1_children.push_back(new wxCheckBox(panel, wxID_ANY, _("Other Depth 1 Children")));
	}
	
	wxArrayString array = wxArrayString();
	array.Add(_("Option 1"));
	array.Add(_("Option 2"));
	array.Add(_("Option 3"));

	m_depth2 = m_depth_1_children.at(1);

	for (int i = 0; i <= 2; i++)
		m_depth2_children.push_back(new wxCheckBox(panel, wxID_ANY, _("Depth 2 Children")));
	

	m_depth3 = m_depth2_children.at(0);

	
	for (int i = 0; i <= 2; i++)
		m_depth3_children.push_back(new wxCheckBox(panel, wxID_ANY, _("Depth 3 Children")));

}
