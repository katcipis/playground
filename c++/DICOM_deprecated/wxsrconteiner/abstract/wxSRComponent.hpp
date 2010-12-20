#ifndef WXGENERICCOMPONENT_HPP_
#define WXGENERICCOMPONENT_HPP_

#include "wx/wxprec.h"
#include <map>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class wxSRComponent : public wxPanel {

public:

	wxSRComponent(wxWindow* parent, wxString label);

	/// Destructor
	virtual ~wxSRComponent();

	/*
	 * Returns all the values that the component holds, like label value,
	 * text that is on the text area and the selected option value. 
	 */
	virtual std::map<std::string, wxString> GetValues();

	/*
	 * Sets all the values that the component holds, like label value,
	 * text on the text area and the selected option value.
	 * Invalid Keys will be ignored. The key is the type of the component
	 * and the value is the new value to the component.
	 */
	virtual void SetValues(std::map<std::string, wxString> values);

	virtual bool IsChecked();

	virtual void SetCheckValue(bool state);

protected:
	/// Creates the controls and sizers
	virtual void CreateControls() =0;

	virtual void RefreshOnGui() =0;

	std::map<std::string, wxString> m_values;
	wxString m_label;
	wxWindow* m_parent;

};

#endif /*WXGENERICCOMPONENT_HPP_*/
