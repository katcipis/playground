#include "DicomSrApp.hpp"

IMPLEMENT_APP( DicomSrApp )
IMPLEMENT_CLASS( DicomSrApp, wxApp )

DicomSrApp::DicomSrApp(){
    Init();
}

void DicomSrApp::Init(){
}

bool DicomSrApp::OnInit(){
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
    
  DicomSrFrame* frame = new DicomSrFrame( NULL, wxID_ANY, _("Dicom SR"), wxDefaultPosition, wxSize(800, 600), wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX|wxRESIZE_BORDER) ;
  frame->Show();
  //DrFrame* sizer = new wxBoxSizer(wxVERTICAL);
  //frame->SetSizer(sizer);
  //sizer->Add(text_control, 0, wxGROW|wxEXPAND|wxALL);
  //sizer->Add(comboBox, 0, wxGROW|wxEXPAND|wxALL);
  //sizer->Add(checkListBox, 0, wxGROW|wxEXPAND|wxALL);
  //frame->Show();

  return true;
}

int DicomSrApp::OnExit(){ 
    return wxApp::OnExit();
}
