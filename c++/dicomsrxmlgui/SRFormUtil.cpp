#include "SRFormUtil.hpp"
#include "SRXmlStrings.hpp"

SRFormUtil::SRFormUtil() {
  std::string nameDic = "name_dictionary.dic";
  std::string unitDic = "unit_dictionary.dic";

  m_name_dictionary = new Dictionary(nameDic , dt_name_dictionary);
  m_unit_dictionary = new Dictionary(unitDic , dt_unit_dictionary);
}

SRFormUtil::~SRFormUtil() {
}

std::string SRFormUtil::GetTitle(Tag tag) {
  std::string coding_sch;

  if (tag.HasPropertie(SRXmlStrings::m_coding_scheme_des))
    coding_sch = tag.properties[SRXmlStrings::m_coding_scheme_des];

  std::string coding_mean;
  if (tag.HasPropertie(SRXmlStrings::m_coding_meaning))
    coding_mean = tag.properties[SRXmlStrings::m_coding_meaning];

  return coding_sch + " - "+ coding_mean;

}

std::string SRFormUtil::GetCodeMeaning(const std::string& code_value) {

  std::string meaning = "No meaning found";

  Term* term = m_name_dictionary->GetTerm(code_value);
  if (term)
    meaning = term->GetMeaning();

  return meaning;
}

SRXmlReader* SRFormUtil::GetSRReader(std::vector<SRXmlReader*> children, std::string xml_reader_name) {
  for (unsigned int i = 0; i < children.size(); i++)
    if (children.at(i)->GetCurrentTag().name == xml_reader_name)
      return children.at(i);

  return NULL;
}

std::vector<SRXmlReader*> SRFormUtil::GetSRReaders(std::vector<SRXmlReader*> children, std::string xml_reader_name) {
  std::vector<SRXmlReader*> found_children;

  for (unsigned int i = 0; i < children.size(); i++)
    if (children.at(i)->GetCurrentTag().name == xml_reader_name)
      found_children.push_back(children.at(i));

  return found_children;
}
