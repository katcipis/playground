#ifndef _WXSRTEXTLIST__
#define _WXSRTEXTLIST__

#include "wx/combo.h"

#define ID_TEXTLIST 10000
#define ID_TEXTCTRL 10001
#define ID_CHOICE 10002

#include "./abstract/wxSROptionsComponent.hpp"

class wxSRTextList: public wxSROptionsComponent {    

public:
  wxSRTextList( wxWindow* parent, const wxString& label = _(""), wxArrayString choice = wxArrayString() );
  
  ~wxSRTextList();

protected:
  void CreateControls();
  
  virtual void RefreshOnGui(){};
    
private:
  wxString m_label;
  wxChoice* m_combo;
  wxFlexGridSizer* m_flexsizer;
};

#endif
    // _WXSRTEXTLIST__
