#ifndef SRXMLREADER_HPP_
#define SRXMLREADER_HPP_

#include <util/xmlutil/XmlSearcher.hpp>
#include <util/xmlutil/Tag.h>

class SRXmlReader {

  public:
    /* 
     * The default constructor only serves 
     * for reading the root node <SRIOD>
     */
    SRXmlReader();

    virtual ~SRXmlReader();

    void ReadFile(std::string file_path);

    //returns true if a file has been loaded sucessfully
    bool FileIsOpen();

    std::vector<SRXmlReader*> GetChildrenReaders();

    Tag GetCurrentTag();

  private:
    XmlSearcher m_xml_reader;
    static TiXmlDocument m_doc;
    TiXmlElement* m_current_element;

    SRXmlReader(TiXmlElement* current_elem);

};

#endif /*SRXMLREADER_HPP_*/
