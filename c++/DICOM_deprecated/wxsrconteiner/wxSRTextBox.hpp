#ifndef TEXTBOX_
#define TEXTBOX_

#define ID_TEXTBOX 10001
#include "./abstract/wxSRComponent.hpp"

class wxSRTextBox: public wxSRComponent
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
  wxFlexGridSizer* m_flexsizer;
};

#endif /*TEXTBOX_*/
