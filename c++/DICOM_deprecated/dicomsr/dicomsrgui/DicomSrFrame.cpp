#include "DicomSrFrame.hpp"

#include <iostream>

BEGIN_EVENT_TABLE( DicomSrFrame, wxFrame )
  EVT_BUTTON ( ID_BUTTON1 , DicomSrFrame::TextCtrlEvent     )
  EVT_BUTTON ( ID_BUTTON2 , DicomSrFrame::TextBoxEvent      )
  EVT_BUTTON ( ID_BUTTON3 , DicomSrFrame::ComboBoxEvent     )
  EVT_BUTTON ( ID_BUTTON4 , DicomSrFrame::TextListEvent     )
  EVT_BUTTON ( ID_BUTTON5 , DicomSrFrame::CheckListBoxEvent )
  EVT_BUTTON ( ID_BUTTON6 , DicomSrFrame::RadioBoxEvent     )
END_EVENT_TABLE()

DicomSrFrame::DicomSrFrame(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style):
wxFrame(parent, id, caption, pos, size, style) {
  
  CreateControls();
  Centre();
}


DicomSrFrame::~DicomSrFrame() {
}

void DicomSrFrame::CreateControls() {
  DicomSrFrame* itemFrame1 = this;

  wxPanel* itemPanel2 = new wxPanel( itemFrame1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );

  wxFlexGridSizer* itemFlexGridSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
  itemFlexGridSizer3->AddGrowableRow(0);
  itemFlexGridSizer3->AddGrowableCol(1);
  itemPanel2->SetSizer(itemFlexGridSizer3);

  wxPanel* itemPanel4 = new wxPanel( itemPanel2, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
  itemFlexGridSizer3->Add(itemPanel4, 1, wxGROW|wxGROW|wxALL, 5);

  wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
  itemPanel4->SetSizer(itemBoxSizer5);

  wxButton* itemButton6 = new wxButton( itemPanel4, ID_BUTTON1, _("wxSRTextCtrl"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemButton6, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);

  wxButton* itemButton7 = new wxButton( itemPanel4, ID_BUTTON2, _("wxSRTextBox"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemButton7, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);

  wxButton* itemButton8 = new wxButton( itemPanel4, ID_BUTTON3, _("wxSRChoice"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemButton8, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);

  wxButton* itemButton9 = new wxButton( itemPanel4, ID_BUTTON4, _("wxSRTextList"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemButton9, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);
  
  wxButton* itemButton10 = new wxButton( itemPanel4, ID_BUTTON5, _("wxSRCheckListBox"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemButton10, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);
  
  wxButton* itemButton11 = new wxButton( itemPanel4, ID_BUTTON6, _("wxSRRadioBox"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer5->Add(itemButton11, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);
  
  m_scrolledWindow = new wxScrolledWindow( itemPanel2, ID_PANEL3, wxDefaultPosition, wxSize(100, 100), wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL|wxTAB_TRAVERSAL );
  itemFlexGridSizer3->Add(m_scrolledWindow, 1, wxGROW|wxALL, 5);
  m_scrolledWindow->SetScrollbars(1, 1, 0, 0);
  
  sizer = new wxBoxSizer(wxVERTICAL);
  m_scrolledWindow->SetSizer(sizer);
  
}

void DicomSrFrame::TextCtrlEvent(wxCommandEvent& event){
  wxSRTextCtrl* teste = new wxSRTextCtrl(m_scrolledWindow, _("teste"));
  sizer->Add(teste, 0, wxGROW|wxEXPAND|wxALL);
  m_scrolledWindow->Layout();
  m_scrolledWindow->Show();
  m_scrolledWindow->FitInside();
}

void DicomSrFrame::TextBoxEvent(wxCommandEvent& event){
  wxSRTextBox* text_box = new wxSRTextBox(m_scrolledWindow, _("Text Box: "));
  sizer->Add(text_box, 0 , wxGROW|wxEXPAND|wxALL);
  m_scrolledWindow->Layout();
  m_scrolledWindow->Show();
  m_scrolledWindow->FitInside();
}

void DicomSrFrame::ComboBoxEvent(wxCommandEvent& event){
  wxArrayString default_choices;

  default_choices.Add(_("Choice 1"));
  default_choices.Add(_("Choice 2"));
  default_choices.Add(_("Choice 3"));

  wxSRChoiceList* teste = new wxSRChoiceList(m_scrolledWindow, _("teste"), default_choices);
  sizer->Add(teste, 0, wxGROW|wxEXPAND|wxALL);
  m_scrolledWindow->Layout();
  m_scrolledWindow->Show();
  m_scrolledWindow->FitInside();
}

void DicomSrFrame::TextListEvent(wxCommandEvent& event){
  wxArrayString default_choices;

  default_choices.Add(_("Choice 1"));
  default_choices.Add(_("Choice 2"));
  default_choices.Add(_("Choice 3"));

  wxSRTextList* teste = new wxSRTextList(m_scrolledWindow, default_choices, _("teste") );
  sizer->Add(teste, 0, wxGROW|wxEXPAND|wxALL);
  m_scrolledWindow->Layout();
  m_scrolledWindow->Show();
  m_scrolledWindow->FitInside();
}

void DicomSrFrame::CheckListBoxEvent(wxCommandEvent& event){
  wxArrayString default_choices;
  wxSRHierarchicalConteiner* conteiner = new wxSRHierarchicalConteiner(m_scrolledWindow, wxID_ANY, wxDefaultPosition,
  																																			wxDefaultSize, 0);
  wxSRGenericComponent* child1 = new wxSRCheckBox(conteiner, _("Child 1"));
  wxSRGenericComponent* child2 = new wxSRCheckBox(conteiner, _("Child 2"));
  wxSRGenericComponent* child3 = new wxSRCheckBox(conteiner, _("Child 3"));
  
  wxSRGenericComponent* parent = new wxSRCheckBox(conteiner, _("Parent"));
  
  std::vector<wxSRGenericComponent*> children;
  children.push_back(child1);
  children.push_back(child2);
  children.push_back(child3);

  conteiner->AddComponent(parent, children);

  sizer->Add(conteiner, 0, wxGROW|wxALL);
  m_scrolledWindow->Layout();
  m_scrolledWindow->Show();
  m_scrolledWindow->FitInside();
}

void DicomSrFrame::RadioBoxEvent(wxCommandEvent& event){
  wxArrayString default_choices;

  default_choices.Add(_("Choice 1"));
  default_choices.Add(_("Choice 2"));
  default_choices.Add(_("Choice 3"));

  wxSRRadioBox* teste = new wxSRRadioBox(m_scrolledWindow ,_("teste") , default_choices);
  sizer->Add(teste, 0, wxGROW|wxEXPAND|wxALL);
  m_scrolledWindow->Layout();
  m_scrolledWindow->Show();
  m_scrolledWindow->FitInside();
}
