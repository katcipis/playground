#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wxSRTextList.hpp"


wxSRTextList::wxSRTextList( wxWindow* parent, wxArrayString choice,const wxString& label) :
wxPanel(parent){
  wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize);  
  m_label = label;
  m_choice = choice; 
  CreateControls();
  
  if (GetSizer()) {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
}

wxSRTextList::~wxSRTextList() {}

void wxSRTextList::CreateControls() {
  m_flexsizer = new wxFlexGridSizer(1,3,0,0);

  m_flexsizer->AddGrowableCol(1, 1);
  m_flexsizer->AddGrowableCol(2, 1);
  
  SetSizer(m_flexsizer);
  
  wxStaticText* staticText = new wxStaticText( this, -1, m_label, wxDefaultPosition, wxDefaultSize, 0 );
  m_flexsizer->Add(staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxTextCtrl* textCtrl = new wxTextCtrl( this, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
  m_flexsizer->Add(textCtrl, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);
  
  m_combo = new wxChoice( this, ID_CHOICE, wxDefaultPosition, wxDefaultSize,  m_choice, 0 );
  m_flexsizer->Add(m_combo, 0, wxALIGN_CENTER|wxGROW|wxALL, 5);
}
