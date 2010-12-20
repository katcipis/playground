/////////////////////////////////////////////////////////////////////////////
// Name:        tutorialapp.cpp
// Purpose:     
// Author:      Katcipis
// Modified by: 
// Created:     Mon 03 Mar 2008 14:13:39 BRT
// RCS-ID:      
// Copyright:   Cyclops Group
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "TutorialApp.hpp"
#include "wxSRTextCtrl.hpp"
#include "wxSRChoice.hpp"
#include "wxSRCheckListBox.hpp"

////@begin XPM images

////@end XPM images


/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( TutorialApp )
////@end implement app


/*!
 * TutorialApp type definition
 */

IMPLEMENT_CLASS( TutorialApp, wxApp )

/*!
 * TutorialApp event table definition
 */

BEGIN_EVENT_TABLE( TutorialApp, wxApp )

////@begin TutorialApp event table entries
////@end TutorialApp event table entries

END_EVENT_TABLE()

/*!
 * Constructor for TutorialApp
 */

TutorialApp::TutorialApp()
{
	Init();
}

/*!
 * Member initialisation
 */

void TutorialApp::Init() {
	////@begin TutorialApp member initialisation
	////@end TutorialApp member initialisation
}

/*!
 * Initialisation for TutorialApp
 */

bool TutorialApp::OnInit() {
	////@begin TutorialApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

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
	////@end TutorialApp initialisation

wxFrame* frame = new wxFrame(NULL, wxID_ANY, _("Frame"), wxDefaultPosition, 
		                     wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX|wxRESIZE_BORDER|wxTAB_TRAVERSAL,
		                     _("Frame"));

wxArrayString default_choices;

default_choices.Add(_("Choice 1"));
default_choices.Add(_("Choice 2"));
default_choices.Add(_("Choice 3"));


wxSRTextCtrl* text_control = new wxSRTextCtrl(frame,  _("TextCtrl Label: "));
wxSRChoice* comboBox = new wxSRChoice(frame,  _("ComboBox Label: "), default_choices);
wxSRCheckListBox* checkListBox = new wxSRCheckListBox(frame,  _("CheckListBox Label: "), default_choices);

wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
frame->SetSizer(sizer);
sizer->Add(text_control, 0, wxGROW|wxEXPAND|wxALL);
sizer->Add(comboBox, 0, wxGROW|wxEXPAND|wxALL);
sizer->Add(checkListBox, 0, wxGROW|wxEXPAND|wxALL);
frame->Show();

return true;

}

/*!
 * Cleanup for TutorialApp
 */

int TutorialApp::OnExit() {
	////@begin TutorialApp cleanup
	return wxApp::OnExit();
	////@end TutorialApp cleanup
}

