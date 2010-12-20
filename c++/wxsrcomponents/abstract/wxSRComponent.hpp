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

#include <vector>

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

	/**
	 * Add a wxSRComponent
	 * \param wxSRComponent to be added
	 * The inserted component will appear
	 * bellow this component when he is told 
	 * to show his children.
	 */
	virtual void AddComponent(wxSRComponent* child);

	/**
	 * Add a vector of wxSRComponent
	 * \param vector of wxSRComponent to be added
	 * Behaves exactaly like AddComponent, but adds
	 * an entire vector.
	 */
	virtual void AddComponents(std::vector<wxSRComponent*> children);

	/**
	 * \return true if the child is inside this component
	 * \param child component
	 */
	virtual bool FindChild(wxSRComponent* child);

	/**
	 * \return true if the component is checked.
	 * Default behaviour is always false, this method
	 * exists only as an abstract layer for checkbox 
	 * like components that may want to have behaviour 
	 * based on if it is checked or not. Such classes must 
	 * override this method and implement the behaviour 
	 * and how it will be checked.
	 */
	virtual bool IsChecked();

	/**
	 * \param the new check state of the component.
	 * this method exists to create an abstract layer
	 * for checkable components, so it is not needed
	 * to specify the kind of checkable component to check it
	 * almost all components simply does nothing on this method.
	 * But if it is a checkable component it must check the component
	 * accordingly to the given state.
	 */
	virtual void SetCheckValue(bool state)=0;

	wxSizer* GetChildrenSizer();

	/**
	 * \param an event that has ocurred component.
	 * this method exists to create an abstract layer
	 * ,so it is not needed to specify the behaviour
	 * almost all components simply does nothing on this method.
	 * But if it is a component that must refresh something when 
	 * an event occurs the event must be treated here.
	 */
	virtual void RefreshState(wxCommandEvent& event, bool state = false) =0;

	virtual std::vector<wxSRComponent*> GetChildren();

	/**
	 * \param the new sizer to the children components.
	 * All the children of the component will be inserted 
	 * on this new sizer, and the new sizer will be set
	 * as the default children sizer.
	 */
	virtual void SetChildrenSizer(wxSizer* sizer);

protected:
  virtual void RefreshSizers();
  
	/// Creates the controls and sizers
	virtual void CreateControls() =0;

	/**
	 * This method is called after SetValues, it must
	 * refresh the component on the gui with the new values
	 * that have been set.
	 */
	virtual void RefreshOnGui() =0;

	/**
	 * This method is called when it is needed to add
	 * the children sizer on the component sizer, it will happen 
	 * when the component is the root of the componet tree.
	 * Components may have diferent kinds of sizers so this method
	 * is virtual and must be implemented.
	 */
	virtual void AddOnSizer(wxSizer* children_sizer) = 0;

	std::vector<wxSRComponent*> m_children;
	std::map<std::string, wxString> m_values;

	wxString m_label;
	wxWindow* m_parent;
	wxSizer* m_children_sizer;

private:

	void InsertComponent(wxSRComponent* child);
	bool IsRootComponent();

};

#endif /*WXGENERICCOMPONENT_HPP_*/
