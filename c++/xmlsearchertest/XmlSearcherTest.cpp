#include "XmlSearcherTest.hpp"

void XmlSearcherTest::setUp(){
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
    
}


void XmlSearcherTest::tearDown(){
    
    delete m_searcher;
             
}
   

  
//starts node tests
void XmlSearcherTest::IfTheNodeIsFoundReturnsATinyXmlNodePointer(){
     TiXmlNode* node = m_searcher->FindNode(m_xml_doc, m_ok_node_value);
     CPPUNIT_ASSERT(node != NULL);  
     CPPUNIT_ASSERT(strcmp(node->Value(), m_ok_node_value.c_str()) == 0);
}
    
void XmlSearcherTest::IfTheNodeIsNotFoundReturnsNULL(){
     TiXmlNode* node = m_searcher->FindNode(m_xml_doc, m_bad_node_value);
     CPPUNIT_ASSERT(node == NULL); 
}
    
//starts elements tests
void XmlSearcherTest::IfTheElementIsFoundReturnsATinyXmlElementPointer(){
    TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_ok_element_value);
    CPPUNIT_ASSERT(element != NULL); 
    CPPUNIT_ASSERT(strcmp(element->Value(), m_ok_element_value.c_str()) == 0);
}
    
void XmlSearcherTest::IfTheElementIsFoundButItHasMultipleIdsReturnsTheFirstOne(){
    TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_ok_element_with_ids);
    
    CPPUNIT_ASSERT(strcmp(element->Value(), m_ok_element_with_ids.c_str()) == 0);
    CPPUNIT_ASSERT(strcmp(element->Attribute(m_id.c_str()), m_first_element_id.c_str()) == 0);
}
    
void XmlSearcherTest::IfTheElementIsNotFoundReturnsNULL(){
    TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_bad_node_value);
    CPPUNIT_ASSERT(element == NULL); 
}
    
void XmlSearcherTest::IfANodeIsFoundButItsNotAElementReturnsNULL(){
    
    TiXmlNode* node = m_searcher->FindNode(m_xml_doc, m_ok_not_element_value);
    CPPUNIT_ASSERT(node != NULL); 
     
    TiXmlElement* element = m_searcher->FindElement(m_xml_doc, m_ok_not_element_value);
    CPPUNIT_ASSERT(element == NULL); 
    
}

//starts text tests
void XmlSearcherTest::IfTheTextIsFoundReturnsATinyXmlTextPointer(){
    TiXmlText* text = m_searcher->FindText(m_xml_doc, m_ok_text_value);
    CPPUNIT_ASSERT(text != NULL); 
    CPPUNIT_ASSERT(strcmp(text->Value(), m_ok_text_value.c_str()) == 0);
}
    
void XmlSearcherTest::IfTheTextIsNotFoundReturnsNULL(){
    TiXmlText* text = m_searcher->FindText(m_xml_doc, m_bad_node_value);
    CPPUNIT_ASSERT(text == NULL); 
}
    
void XmlSearcherTest::IfANodeIsFoundButItsNotATextReturnsNULL(){
    
    TiXmlNode* node = m_searcher->FindNode(m_xml_doc, m_ok_not_text_value);
    CPPUNIT_ASSERT(node != NULL); 
     
    TiXmlText* text = m_searcher->FindText(m_xml_doc, m_ok_not_text_value);
    CPPUNIT_ASSERT(text == NULL); 
    
}

//starts invalid document tests
void XmlSearcherTest::IfAInvalidTiXmlDocumentIsPassedToFindANodeReturnsNULL(){
    
    TiXmlNode* node = m_searcher->FindNode(m_invalid_xml_doc, m_ok_node_value);
    CPPUNIT_ASSERT(node == NULL); 
      
}

void XmlSearcherTest::IfAInvalidTiXmlDocumentIsPassedToFindAElementReturnsNULL(){
    
    TiXmlElement* element = m_searcher->FindElement(m_invalid_xml_doc, m_ok_element_value);
    CPPUNIT_ASSERT(element == NULL); 
}

