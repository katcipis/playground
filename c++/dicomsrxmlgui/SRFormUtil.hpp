#ifndef SRFORMUTIL_H_
#define SRFORMUTIL_H_

#include <string>
#include <vector>
#include <dicomsrxml/SRXmlReader.hpp>
#include <dicReader/Dictionary.hpp>

using namespace dictionaryeditor;

class SRFormUtil {
  
  public:
    SRFormUtil();
    virtual ~SRFormUtil();

  protected:
    
    std::vector<SRXmlReader*>
        GetSRReaders(std::vector<SRXmlReader*> children, std::string xml_reader_name);

    std::string GetCodeMeaning(const std::string& code_value);
    std::string GetTitle(Tag tag);
    SRXmlReader
        * GetSRReader(std::vector<SRXmlReader*> sr_iod_children, std::string xml_reader_name);

    dictionaryeditor::Dictionary* m_name_dictionary;
    dictionaryeditor::Dictionary* m_unit_dictionary;
};

#endif /*SRFORMUTIL_H_*/
