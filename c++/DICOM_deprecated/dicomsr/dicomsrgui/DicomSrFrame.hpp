#ifndef DICOMSRFRAME_HPP_
#define DICOMSRFRAME_HPP_

#include "wxSRChoiceList.hpp"
#include "wxSRTextCtrl.hpp"
#include "wxSRRadioBox.hpp"
#include "wxSRTextBox.hpp"
#include "wxSRTextList.hpp"
#include "wxSRCheckBox.hpp"
#include "wxSRHierarchicalConteiner.hpp"

#include "wx/frame.h"
#include "wx/wxprec.h"
#include <wx/scrolwin.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#define ID_DRFRAME 10000
#define ID_PANEL1 10001
#define ID_PANEL2 10002
#define ID_BUTTON1 10004
#define ID_BUTTON2 10005
#define ID_BUTTON3 10006
#define ID_BUTTON4 10007
#define ID_BUTTON5 10008
#define ID_BUTTON6 10009
#define ID_PANEL3 10003
#define SYMBOL_DRFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_DRFRAME_TITLE _("Dicom SR")
#define SYMBOL_DRFRAME_IDNAME ID_DRFRAME
#define SYMBOL_DRFRAME_SIZE wxSize(400, 300)
#define SYMBOL_DRFRAME_POSITION wxDefaultPosition

class DicomSrFrame: public wxFrame {
  
    DECLARE_EVENT_TABLE()

public:
  DicomSrFrame( wxWindow* parent, wxWindowID id = SYMBOL_DRFRAME_IDNAME, const wxString& caption = SYMBOL_DRFRAME_TITLE, const wxPoint& pos = SYMBOL_DRFRAME_POSITION, const wxSize& size = SYMBOL_DRFRAME_SIZE, long style = SYMBOL_DRFRAME_STYLE );
  virtual ~DicomSrFrame();
  void CreateControls();
  void TextCtrlEvent(wxCommandEvent& event);
  void ComboBoxEvent(wxCommandEvent& event);
  void RadioBoxEvent(wxCommandEvent& event);
  void CheckListBoxEvent(wxCommandEvent& event);
  void TextListEvent(wxCommandEvent& event);
  void TextBoxEvent(wxCommandEvent& event);
  
private:
  wxScrolledWindow* m_scrolledWindow;
  wxBoxSizer* sizer;

};

#endif /*DICOMSRFRAME_HPP_*/
