#ifndef SRCOMPONENTFACTORY_HPP_
#define SRCOMPONENTFACTORY_HPP_

#include <dicReader/Dictionary.hpp>
#include "SRFormBuilder.hpp"
#include <util/StringHandler.hpp>
#include <wxsrcomponents/abstract/wxSRComponent.hpp>

using namespace dictionaryeditor;
using namespace util;

namespace SRBuilderMap{

typedef wxSRComponent* (*Builder)(const std::string& code_value,
		const std::string& meaning, Term* term, wxPanel* frame);

typedef std::map< std::string, Builder > BuilderMap; 

}

class SRComponentFactory {

public:
	static wxSRComponent* BuildComponent(const std::string& code_value, Term* term,
			wxSizer* sizer, wxPanel* frame);
private:
	
  static SRBuilderMap::BuilderMap m_buildermap;
	static void InitializeBuilderMap();
	
	static wxSRComponent* BuildData(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame);
	static wxSRComponent* BuildChoiceList(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame);
	static wxSRComponent* BuildTextCtrl(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame);
	static wxSRComponent* BuildCheckBox(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame);
	static wxSRComponent* BuildTextBox(const std::string& code_value,const std::string& meaning, Term* term, wxPanel* frame);
};

#endif /*SRCOMPONENTFACTORY_HPP_*/
