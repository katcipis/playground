#ifndef _WXSRTEXTLIST__
#define _WXSRTEXTLIST__

#include "wx/combo.h"

#define ID_TEXTLIST 10000
#define ID_TEXTCTRL 10001
#define ID_CHOICE 10002

class wxSRTextList: public wxPanel {    

public:
  wxSRTextList( wxWindow* parent, wxArrayString choice, const wxString& label = _("") );
  
  ~wxSRTextList();

protected:
  void CreateControls();
  
  virtual void RefreshOnGui(){};
    
private:
  wxFlexGridSizer* m_flexsizer;
  wxString m_label;
  wxArrayString m_choice;
  wxChoice* m_combo;
  
};

#endif
    // _WXSRTEXTLIST__
