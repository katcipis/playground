#ifndef WXSROPTIONSCOMPONENT_HPP_
#define WXSROPTIONSCOMPONENT_HPP_

#include "./wxSRComponent.hpp"

class wxSROptionsComponent : public wxSRComponent {

public:

	wxSROptionsComponent(wxWindow* parent, wxString label = _(""), wxArrayString choices = wxArrayString());

	/// Destructor
	virtual ~wxSROptionsComponent();

	virtual wxArrayString GetOptions();

  /*
   *The default behaviour of this method does nothing,
   *components who have options cant have children that
   *have no attachment to an option.
   */
	virtual void AddComponent(wxSRComponent* child);

 /*
  *Add a component and atach it to a specific option
  *when this option is chosed the children atached to it
  *will be inserted on the sizer and showed. If the option
  *is not found does nothing.
  *\param option, the option that the child will be atached
  *\param child, the child to be added and atached to the option
  */
	virtual void AddComponent(wxString option, wxSRComponent* child);

 /*
  *The default behaviour of this method does nothing,
  *components who have options cant have children that
  *have no attachment to an option.
  */
	virtual void AddComponents(std::vector<wxSRComponent*> children);

 /*
  *Add a vector of components and atach it to a specific option
  *when this option is chosed the children atached to it
  *will be inserted on the sizer and showed. If the option
  *is not found does nothing.
  *\param option, the option that the child will be atached
  *\param children, the children to be added and atached to the option
  */
	virtual void AddComponents(wxString option, std::vector<wxSRComponent*> children);

 /*
  *\returns true if the option exists
  *\param option to search on the component
  */
	virtual bool HasOption(wxString option);

 /*
  *Default behaviour does nothing, components with
  *options are not checkable.
  */
	virtual void SetCheckValue(bool state);

 /*
  *Default behaviour is hide all his children.
  */
	virtual void RefreshState(wxCommandEvent& event, bool state = false);
	
	virtual void InsertDefaultOption();

protected:

	virtual void ShowOptionChildren(wxString option);

	virtual bool HasChildren(wxString parent);

	wxArrayString m_choices;
	std::map<wxString, std::vector<wxSRComponent*> > m_options_children;

};

#endif /*WXSROPTIONSCOMPONENT_HPP_*/
