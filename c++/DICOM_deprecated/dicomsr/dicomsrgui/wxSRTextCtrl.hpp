#ifndef TEXTCTRL_
#define TEXTCTRL_

#define ID_TEXTCTRL 10001
#include "./abstract/wxSRGenericComponent.hpp"

class wxSRTextCtrl: public wxSRGenericComponent
{    
  

public:
    /// Constructors
	wxSRTextCtrl( wxWindow* parent, wxString label);

    /// Destructor
    ~wxSRTextCtrl();

protected:
    
    /// Creates the controls and sizers
    virtual void CreateControls();
    
    virtual void RefreshOnGui(){};
    
private:
	
	wxString m_text_ctrl_label;
	wxStaticText* m_label_static_text;
	wxTextCtrl* m_text_ctrl;

};

#endif /*TEXTCTRL_*/
