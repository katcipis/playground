#ifndef TEXTBOX_
#define TEXTBOX_

#include "./abstract/wxSRComponent.hpp"

class wxSRTextBox: public wxSRComponent
{    
  
public:
  wxSRTextBox(wxWindow* parent, wxString label);

  virtual ~wxSRTextBox();
  
  virtual void SetCheckValue(bool state){};

  virtual void RefreshState(wxCommandEvent& event, bool state);

protected:
  virtual void CreateControls();

  virtual void RefreshOnGui(){};
  
  virtual void AddOnSizer(wxSizer* children_sizer);
    
private:
  wxString m_text_Box_label;
  wxStaticText* m_label_static_text;
  wxTextCtrl* m_textBox;
  wxFlexGridSizer* m_flexsizer;
};

#endif /*TEXTBOX_*/
