#ifndef TEXTBOX_
#define TEXTBOX_

#define ID_TEXTBOX 10001
#include "./abstract/wxSRGenericComponent.hpp"

class wxSRTextBox: public wxSRGenericComponent
{    
  
public:
  wxSRTextBox(wxWindow* parent, wxString label);

  ~wxSRTextBox();

protected:
  virtual void CreateControls();

  virtual void RefreshOnGui(){};
    
private:
  wxString m_text_Box_label;
  wxStaticText* m_label_static_text;
  wxTextCtrl* m_textBox;

};

#endif /*TEXTBOX_*/
