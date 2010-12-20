#ifndef TINYXMLSEARCHERTEST_HPP_
#define TINYXMLSEARCHERTEST_HPP_


#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include <vector>
#include <xmlutil/XmlSearcher.hpp>
#include <xmlutil/Tag.h>


using namespace std;

#endif /*TINYXMLSEARCHERTEST_HPP_*/

 
class XmlSearcherTest : public CppUnit::TestFixture{
    
	  CPPUNIT_TEST_SUITE( XmlSearcherTest );
	   CPPUNIT_TEST( IfTheNodeIsFoundReturnsATinyXmlNodePointer );
	   CPPUNIT_TEST( IfTheNodeIsNotFoundReturnsNULL );
	   CPPUNIT_TEST( IfTheElementIsFoundReturnsATinyXmlElementPointer );
	   CPPUNIT_TEST( IfTheElementIsFoundButItHasMultipleIdsReturnsTheFirstOne );
	   CPPUNIT_TEST( IfTheElementIsNotFoundReturnsNULL );
	   CPPUNIT_TEST( IfANodeIsFoundButItsNotAElementReturnsNULL );
	   CPPUNIT_TEST( IfTheTextIsFoundReturnsATinyXmlTextPointer );
	   CPPUNIT_TEST( IfTheTextIsNotFoundReturnsNULL );
	   CPPUNIT_TEST( IfANodeIsFoundButItsNotATextReturnsNULL );
	   CPPUNIT_TEST( IfAInvalidTiXmlDocumentIsPassedToFindANodeReturnsNULL );
	   CPPUNIT_TEST( IfAInvalidTiXmlDocumentIsPassedToFindAElementReturnsNULL );
	  CPPUNIT_TEST_SUITE_END();
	
    XmlSearcher* m_searcher;
    TiXmlDocument m_xml_doc;
    TiXmlDocument m_invalid_xml_doc;
    string m_ok_node_value;
    string m_bad_node_value;
    string m_ok_element_value;
    string m_ok_not_element_value;
    string m_ok_text_value;
    string m_ok_not_text_value;
    string m_ok_element_with_ids;
    string m_ok_element_id;
    string m_first_element_id;
    string m_id;
    string m_value;
    string m_cpp;
    
    public:
    XmlSearcherTest(){}
    virtual ~XmlSearcherTest(){}
    void setUp();
    void tearDown();
   
    //starts node tests
    void IfTheNodeIsFoundReturnsATinyXmlNodePointer();
    
    void IfTheNodeIsNotFoundReturnsNULL();
    
    /*starts elements tests
     * elements tests uses the <demoVersion> version </demoVersion>
     * to make any changes its only necessary to 
     * change the variables associated with these values 
     */ 
    void IfTheElementIsFoundReturnsATinyXmlElementPointer();
    
    void IfTheElementIsFoundButItHasMultipleIdsReturnsTheFirstOne();
    
    void IfTheElementIsNotFoundReturnsNULL();
    
    void IfANodeIsFoundButItsNotAElementReturnsNULL();
    
    //starts text tests
    void IfTheTextIsFoundReturnsATinyXmlTextPointer();
    
    void IfTheTextIsNotFoundReturnsNULL();
    
    void IfANodeIsFoundButItsNotATextReturnsNULL();
    
    //invalid document test
    void IfAInvalidTiXmlDocumentIsPassedToFindANodeReturnsNULL();
    
    void IfAInvalidTiXmlDocumentIsPassedToFindAElementReturnsNULL();
    
  
 };
