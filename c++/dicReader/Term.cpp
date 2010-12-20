  /**
 * \file Term.cpp
 *
 * Implementation for the Term class.
 *
 * $Rev: $
 * $Date: $
 * $Author: $
 */

#include <wx/tokenzr.h>
#include "Term.hpp" 
#include <util/StringHandler.hpp>

using namespace std;
using namespace dictionaryeditor;

  std::map<CodingType, std::string> dictionaryeditor::Term::m_mapvaluestring;
  std::map<std::string, dictionaryeditor::CodingType> dictionaryeditor::Term::m_mapstringvalue;  

Term::Term (string code, string meaning, string designator, string version, string description, CodingType coding) {
  m_code = code;
  m_meaning = meaning;
  m_designator = designator;
  m_version = version;
  m_description = description;
  m_codingtype = coding;  
} 

Term::Term (string code, string meaning, string designator, string version, string description, string codeList) {
  m_code = code;
  m_meaning = meaning;
  m_designator = designator;
  m_version = version;
  m_description = description;
  m_codingtype = ct_text_box;
  string aux = "";

  if(codeList.length() != 0){
  	wxStringTokenizer tkz(util::StringHandler::std2wx(codeList), wxT("|")); 
  	while ( tkz.HasMoreTokens() ){
  	    wxString token = tkz.GetNextToken();
  	    if(token.Length() != 0)
  	    	m_codeList.push_back(util::StringHandler::wx2std(token));
  	}
  }
}

Term::Term(){
  m_code = "";
  m_meaning = "";
  m_designator = "";
  m_version = "";
  m_description = "";   
  m_codingtype = ct_text_box;    
}

Term::~Term(){
      
}

void Term::SetCode(string aCode){
  m_code = aCode;
}

void Term::SetMeaning(string aMeaning){
  m_meaning = aMeaning;
}

void Term::SetDesignator(string aDesignator){
  m_designator = aDesignator;
}

void Term::SetVersion(string aVersion){
  m_version = aVersion;
}

void Term::SetDescription(string aDescription){
  m_description = aDescription;
}

void Term::SetCodingType(CodingType coding){
  m_codingtype = coding;
} 

string Term::GetCode(){
  return m_code;      
}

string Term::GetMeaning(){
  return m_meaning;      
}

string Term::GetDesignator(){
  return m_designator;      
}

string Term::GetVersion(){
  return m_version;
}

string Term::GetDescription(){
  return m_description;
}

CodingType Term::GetCodingType(){
  return m_codingtype;
}

std::list<std::string> Term::GetUnits(){
	return m_codeList;
}

string Term::ToString(){
  string temp = "";
  temp += m_code + "\t";
  temp += m_designator + "\t";
  temp += m_version + "\t";
  temp += m_meaning + "\t";
  temp += m_description + "\t";
  temp += Term::ToString(m_codingtype) + "\n";
  return temp;
}

//
//TiXmlElement* Term::AsXml(){
//  TiXmlElement* term = new TiXmlElement("ConceptNameCodeSequenceItem");
//  term->SetAttribute("codeValue", m_code.c_str());
//  term->SetAttribute("codingSchemeDesignator", m_designator.c_str());
//  term->SetAttribute("codingMeaning", m_meaning.c_str());
//  term->SetAttribute("codingSchemeVersion", m_version.c_str());
//  term->SetAttribute("description", m_description.c_str());
//  term->SetAttribute("codingType", (Term::ToString(m_codingtype)).c_str());
//  return term;
//}
