#include "SRFormBuilder.hpp"
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

  
  builder = new SRFormBuilder("./test.xml");
  
  return true;
}
