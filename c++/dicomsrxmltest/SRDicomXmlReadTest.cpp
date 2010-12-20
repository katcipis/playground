#include "SRDicomXmlReadTest.hpp"

SRDicomXmlReadTest::SRDicomXmlReadTest() {
  m_sriod_reader.ReadFile("./files/teste.xml");
}
SRDicomXmlReadTest::~SRDicomXmlReadTest() {
}

void SRDicomXmlReadTest::TheTest() {

  std::vector<SRXmlReader*> root = m_sriod_reader.GetChildrenReaders();
  std::queue<SRXmlReader*> file_tags;
  
  for(unsigned int i = 0; i < root.size(); i++)
    file_tags.push(root.at(i));
  
  while(!file_tags.empty()){
    SRXmlReader* tmp = file_tags.front();
    file_tags.pop();
    std::cout << tmp->GetCurrentTag().ToString() << std::endl;
    
    std::vector<SRXmlReader*> aux = tmp->GetChildrenReaders();
    for(unsigned int i = 0; i < aux.size(); i++)
        file_tags.push(aux.at(i));
  }
  
}

