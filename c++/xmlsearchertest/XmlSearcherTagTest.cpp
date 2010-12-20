#include "XmlSearcherTagTest.hpp"

void TinyXmlSearcherTagTest::setUp(){
  m_searcher = new XmlSearcher();
  
  m_xml_doc.LoadFile("test.xml");
  m_invalid_xml_doc.LoadFile("invalid.xml");
  
  m_ok_node_value = "demoVersion";
  m_bad_node_value = "badNode";
  m_ok_element_value = "demoVersion";
  m_ok_not_element_value = "true";
  m_ok_text_value = "false";
  m_ok_not_text_value = "demoVersion";
  m_ok_element_with_ids = "sector";
  m_id = "id";
  m_value = "value";
  m_cpp = "cpp";
  m_ok_element_id = "BCP";
  m_first_element_id = "RDL";
  
  m_full_tag.name = m_ok_element_with_ids;
  m_full_tag.properties[m_id] = m_ok_element_id;
  
  m_tag_without_properties.name = m_ok_element_with_ids;
  
  m_tag_with_invalid_properties_value = m_ok_element_with_ids;
  m_tag_with_invalid_properties_value.properties[m_id] = "invalid_atribute";
  
  m_tag_with_invalid_name.name = "invalid_name";
  
  m_tag_without_name.properties[m_id] = m_ok_element_id;
  
  m_full_tag_prop.name = m_ok_element_with_ids;
  m_full_tag_prop.properties[m_id] = "BCP";
  m_full_tag_prop.properties["default"] = "MN";
  m_full_tag_prop.properties["etc"] = "CLP";
  
  m_test_tag.name = "test";
  m_test_tag.properties[m_id] = "etc";
  m_test_tag.properties[m_value] = "etc";
  m_test_tag.properties[m_cpp] = "etc";
  
  m_test_tag_without_properties.name = "test";
  
  m_tag_with_invalid_properties.name = "test";
  m_tag_with_invalid_properties.properties["invalid"] = "test";
}


void TinyXmlSearcherTagTest::tearDown(){
  delete m_searcher;
}
   

// starts tag tests
void TinyXmlSearcherTagTest::GivenATagIfAElementWithTheSameNameAndPropertiesValuesIsFoundReturnsATinyXmlElementPointer(){
	TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_full_tag);
	CPPUNIT_ASSERT(element != NULL);
  CPPUNIT_ASSERT(strcmp(element->Value(), m_full_tag.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(element->Attribute(m_id.c_str()), m_full_tag.properties[m_id].c_str()) == 0); 
}

void TinyXmlSearcherTagTest::GivenATagIfAElementWithTheSameNameIsFoundButCantFindWithTheSamePropertiesValuesReturnNULL(){
  TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_tag_with_invalid_properties_value);
  CPPUNIT_ASSERT(element == NULL);
}

void TinyXmlSearcherTagTest::GivenATagIfAElementWithTheSameNameIsNotFoundReturnNULL(){
  TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_tag_with_invalid_name);
  CPPUNIT_ASSERT(element == NULL);
}

void TinyXmlSearcherTagTest::GivenATagIfTheTagHasNoNameReturnNULL(){
  TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_tag_without_name);
  CPPUNIT_ASSERT(element == NULL);
}

void TinyXmlSearcherTagTest::GivenATagIfTheTagHasNameButNoPropertiesReturnTheFirstElementWithTheGivenName(){
  TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_tag_without_properties);
  CPPUNIT_ASSERT(element != NULL);
  CPPUNIT_ASSERT(strcmp(element->Value(), m_tag_without_properties.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(element->Attribute(m_id.c_str()), m_first_element_id.c_str()) == 0); 
}

void TinyXmlSearcherTagTest::IfATagHasMoreThenOnePropertiesWillReturnTheFirstElementThatMatchesWithAllTheProperties(){
  TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_full_tag_prop);
  CPPUNIT_ASSERT(element != NULL);
  CPPUNIT_ASSERT(strcmp(element->Value(), m_full_tag_prop.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(element->Attribute(m_id.c_str()), m_full_tag_prop.properties[m_id].c_str()) == 0);
}


void TinyXmlSearcherTagTest::GivenATagThatHaveMultiplePropertiesReturnsAllTheElementsThatHaveTheSameNameAndAllTheProperties(){
  std::vector<TiXmlElement*> elements = m_searcher->FindElements(m_xml_doc, m_test_tag);
  
  CPPUNIT_ASSERT(3 == elements.size());
  
  CPPUNIT_ASSERT(strcmp(elements[0]->Value(), m_test_tag.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[1]->Value(), m_test_tag.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[2]->Value(), m_test_tag.name.c_str()) == 0);
  
  CPPUNIT_ASSERT(elements[0]->Attribute(m_id.c_str()) != NULL);
  CPPUNIT_ASSERT(elements[1]->Attribute(m_id.c_str()) != NULL);
  CPPUNIT_ASSERT(elements[2]->Attribute(m_id.c_str()) != NULL);
  
  CPPUNIT_ASSERT(elements[0]->Attribute(m_value.c_str()) != NULL);
  CPPUNIT_ASSERT(elements[1]->Attribute(m_value.c_str()) != NULL);
  CPPUNIT_ASSERT(elements[2]->Attribute(m_value.c_str()) != NULL);
  
  CPPUNIT_ASSERT(elements[0]->Attribute(m_cpp.c_str()) != NULL);
  CPPUNIT_ASSERT(elements[1]->Attribute(m_cpp.c_str()) != NULL);
  CPPUNIT_ASSERT(elements[2]->Attribute(m_cpp.c_str()) != NULL);
}

void TinyXmlSearcherTagTest::GivenATagReturnsAEmptyVectorIfNoElementHasThisName(){
  std::vector<TiXmlElement*> elements = m_searcher->FindElements(m_xml_doc, m_tag_with_invalid_name);
  CPPUNIT_ASSERT(elements.empty());
}

void TinyXmlSearcherTagTest::GivenATagReturnsAEmptyVectorIfNoElementHasThisProperties(){
  std::vector<TiXmlElement*> elements = m_searcher->FindElements(m_xml_doc, m_tag_with_invalid_properties);
  CPPUNIT_ASSERT(elements.empty());
}
    
void TinyXmlSearcherTagTest::GivenATagWithNoPropertiesWillReturnAllTheElementsWithTheSameNameOfTheTag(){
  std::vector<TiXmlElement*> elements = m_searcher->FindElements(m_xml_doc, m_test_tag_without_properties);
  
  CPPUNIT_ASSERT(6 == elements.size());
 
  CPPUNIT_ASSERT(strcmp(elements[0]->Value(), m_test_tag_without_properties.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[1]->Value(), m_test_tag_without_properties.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[2]->Value(), m_test_tag_without_properties.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[3]->Value(), m_test_tag_without_properties.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[4]->Value(), m_test_tag_without_properties.name.c_str()) == 0);
  CPPUNIT_ASSERT(strcmp(elements[5]->Value(), m_test_tag_without_properties.name.c_str()) == 0);
}


