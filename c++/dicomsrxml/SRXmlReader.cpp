#include "SRXmlReader.hpp"
#include <util/FileHandler.hpp>
#include <algorithm>

TiXmlDocument SRXmlReader::m_doc;

SRXmlReader::SRXmlReader() {
  m_current_element = NULL;
}

SRXmlReader::SRXmlReader(TiXmlElement* current_elem) {
  m_current_element = current_elem;
}

SRXmlReader::~SRXmlReader() {
}

void SRXmlReader::ReadFile(std::string file_path) {
  util::FileHandler file_handler;

  if (file_handler.FileExists(file_path) && !FileIsOpen()) {
    m_doc.LoadFile(file_path.c_str());
    if (m_current_element == NULL)
      m_current_element = m_doc.RootElement();
  }

}

bool SRXmlReader::FileIsOpen() {
  return m_xml_reader.DocumentIsOk(m_doc);
}

Tag SRXmlReader::GetCurrentTag() {
  return m_xml_reader.FromElementToTag(m_current_element);
}

std::vector<SRXmlReader*> SRXmlReader::GetChildrenReaders() {
  
  std::vector<SRXmlReader*> children_readers;

  if (FileIsOpen()) {

    std::queue<TiXmlElement*> children = m_xml_reader.GetElementChildren(m_current_element);

    while (!children.empty()) {
      children_readers.push_back(new SRXmlReader(children.front()));
      children.pop();
    }

  }

  return children_readers;
}

