#include "SRComponentHandler.hpp"

SRComponentHandler::SRComponentHandler(){
  InitializeComponentsList();
}

SRComponentHandler::~SRComponentHandler(){
}

bool SRComponentHandler::IsComponentWithContentSequence(std::string code_value) {
  return find(m_components.begin(), m_components.end(), code_value)
      != m_components.end();
}

bool SRComponentHandler::IsComponentWithChildren(std::string code_value){
  return find(m_components_with_children.begin(), m_components_with_children.end(), code_value)
        != m_components_with_children.end();
}

bool SRComponentHandler::ComponentHasIndependentChildren(std::string code_value){
  return find(m_components_with_ichildren.begin(), m_components_with_ichildren.end(), code_value)
         != m_components_with_ichildren.end();
}

void SRComponentHandler::InitializeComponentsList() {
  m_components.push_back("0009");
  m_components.push_back("0049");
  m_components.push_back("0012");
  m_components.push_back("0017");
  m_components.push_back("0019");
  m_components.push_back("0027");
  m_components.push_back("0031");
  m_components.push_back("0032");
  m_components.push_back("0020");
  m_components.push_back("0022");
  m_components.push_back("0037");
  
  m_components_with_children.push_back("0012");
  m_components_with_children.push_back("0049");
  m_components_with_children.push_back("0017");
  m_components_with_children.push_back("0019");
  m_components_with_children.push_back("0027");
  m_components_with_children.push_back("0031");
  m_components_with_children.push_back("0032");
  m_components_with_children.push_back("0020");
  m_components_with_children.push_back("0037");
  
  m_components_with_ichildren.push_back("0012");
}
