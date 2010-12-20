#include "SRComponentFactory.hpp"
#include <wxsrcomponents/wxSRCheckBox.hpp>
#include <wxsrcomponents/wxSRTextBox.hpp>
#include <wxsrcomponents/wxSRData.hpp>
#include <wxsrcomponents/wxSRTextCtrl.hpp>
#include <wxsrcomponents/wxSRChoiceList.hpp>
#include <dicReader/Dictionary.hpp>

SRBuilderMap::BuilderMap SRComponentFactory::m_buildermap;

wxSRComponent* SRComponentFactory::BuildComponent(const std::string& code_value,
		Term* term, wxSizer* sizer, wxPanel* frame) {

  if(m_buildermap.empty())
    InitializeBuilderMap();
	
	std::string meaning = "Missing Coding Meaning";
	wxSRComponent* component = NULL;

	if (term)
		meaning = term->GetMeaning();
	
	if (m_buildermap.find(code_value) != m_buildermap.end())
	  component = m_buildermap[code_value](code_value, meaning, term, frame);
	
	
	if (component) {
		sizer->Add(component, 0, wxALIGN_LEFT|wxALIGN_TOP|wxGROW|wxTAB_TRAVERSAL, 5);
		sizer->Layout();
	}
	
	return component;

}

void SRComponentFactory::InitializeBuilderMap() {

	m_buildermap["0022"] = &SRComponentFactory::BuildTextBox;
	
	m_buildermap["0008"] = &SRComponentFactory::BuildTextCtrl;
	m_buildermap["0014"] = &SRComponentFactory::BuildTextCtrl;
	m_buildermap["0013"] = &SRComponentFactory::BuildTextCtrl;
	m_buildermap["0036"] = &SRComponentFactory::BuildTextCtrl;

	m_buildermap["0046"] = &SRComponentFactory::BuildChoiceList;
	m_buildermap["0005"] = &SRComponentFactory::BuildChoiceList;
	m_buildermap["0009"] = &SRComponentFactory::BuildChoiceList;
	m_buildermap["0055"] = &SRComponentFactory::BuildChoiceList;
	m_buildermap["0003"] = &SRComponentFactory::BuildChoiceList;
	
	m_buildermap["0049"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0016"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0015"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0017"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0018"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0027"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0057"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0058"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0059"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0033"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0034"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0035"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0032"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0056"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0020"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0055"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0012"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0019"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0031"] = &SRComponentFactory::BuildCheckBox;
	m_buildermap["0037"] = &SRComponentFactory::BuildCheckBox;
	
	m_buildermap["0054"] = &SRComponentFactory::BuildData;
	m_buildermap["0006"] = &SRComponentFactory::BuildData;
	m_buildermap["0007"] = &SRComponentFactory::BuildData;
	m_buildermap["0002"] = &SRComponentFactory::BuildData;
	m_buildermap["0054"] = &SRComponentFactory::BuildData;
	
}

wxSRComponent* SRComponentFactory::BuildData(const std::string& code_value,
		const std::string& meaning, Term* term, wxPanel* frame) {

	return new wxSRData(frame, StringHandler::std2wx(meaning));

}
wxSRComponent* SRComponentFactory::BuildTextCtrl(const std::string& code_value,
    const std::string& meaning, Term* term, wxPanel* frame) {

  return new wxSRTextCtrl(frame, StringHandler::std2wx(meaning));

}

wxSRComponent* SRComponentFactory::BuildChoiceList(const std::string& code_value, 
		const std::string& meaning, Term* term,wxPanel* frame) {
	
	std::string st = "unit_dictionary.dic";
	dictionaryeditor::Dictionary* m_unit_dictionary = new Dictionary(st , dt_unit_dictionary);
	std::list<std::string> unitsList = term->GetUnits();
	wxArrayString units = wxArrayString();
	std::list<std::string>::iterator iter;
  for(iter = unitsList.begin(); iter != unitsList.end(); iter++){
  	std::string code = *iter;
  	Term* tmp =  m_unit_dictionary->GetTerm(code);
  	std::string meaning = tmp->GetMeaning();
  	wxString aux = StringHandler::std2wx(meaning);
  	units.Add(aux);
  }
	return new wxSRChoiceList(frame, StringHandler::std2wx(meaning), units);
}

wxSRComponent* SRComponentFactory::BuildCheckBox(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame){
  return new wxSRCheckBox(frame, StringHandler::std2wx(meaning));
}

wxSRComponent* SRComponentFactory::BuildTextBox(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame){
  return new wxSRTextBox(frame, StringHandler::std2wx(meaning));
}
