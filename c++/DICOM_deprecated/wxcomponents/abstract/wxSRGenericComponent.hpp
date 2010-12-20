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

class wxSRGenericComponent : public wxPanel {

public:

	wxSRGenericComponent(wxWindow* parent, wxString label);

	/// Destructor
	virtual ~wxSRGenericComponent();

	/*
	 * Returns all the values that the component holds, like label value,
	 * text that is on the text area and the selected option value. 
	 */
	virtual std::map<std::string, std::string> GetValues();

	/*
	 * Sets all the values that the component holds, like label value,
	 * text that is on the text area and the selected option value.
	 * Invalid values will be ignored. 
	 */
	virtual void SetValues(std::map<std::string, std::string> map) =0;

protected:
	/// Creates the controls and sizers
	virtual void CreateControls() =0;

	std::map<std::string, std::string> m_map;
	wxString m_label;
	wxFlexGridSizer* m_flexsizer;

};

#endif /*WXGENERICCOMPONENT_HPP_*/
