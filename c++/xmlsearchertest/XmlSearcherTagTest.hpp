#ifndef TINYXMLSEARCHERTAGTEST_HPP_
#define TINYXMLSEARCHERTAGTEST_HPP_

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


 
class TinyXmlSearcherTagTest : public CppUnit::TestFixture{
    
  CPPUNIT_TEST_SUITE( TinyXmlSearcherTagTest );
   CPPUNIT_TEST( GivenATagIfAElementWithTheSameNameAndPropertiesValuesIsFoundReturnsATinyXmlElementPointer );
   CPPUNIT_TEST( GivenATagIfAElementWithTheSameNameIsFoundButCantFindWithTheSamePropertiesValuesReturnNULL );
   CPPUNIT_TEST( GivenATagIfAElementWithTheSameNameIsNotFoundReturnNULL );
   CPPUNIT_TEST( GivenATagIfTheTagHasNoNameReturnNULL );
   CPPUNIT_TEST( GivenATagIfTheTagHasNameButNoPropertiesReturnTheFirstElementWithTheGivenName );
   CPPUNIT_TEST( IfATagHasMoreThenOnePropertiesWillReturnTheFirstElementThatMatchesWithAllTheProperties ); 
   CPPUNIT_TEST( GivenATagThatHaveMultiplePropertiesReturnsAllTheElementsThatHaveTheSameNameAndAllTheProperties );
   CPPUNIT_TEST( GivenATagReturnsAEmptyVectorIfNoElementHasThisName );
   CPPUNIT_TEST( GivenATagReturnsAEmptyVectorIfNoElementHasThisProperties );
   CPPUNIT_TEST( GivenATagWithNoPropertiesWillReturnAllTheElementsWithTheSameNameOfTheTag );
  CPPUNIT_TEST_SUITE_END();

protected:
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
  Tag m_full_tag;
  Tag m_tag_without_properties;
  Tag m_tag_with_invalid_properties_value;
  Tag m_tag_with_invalid_name;
  Tag m_tag_without_name;
  Tag m_full_tag_prop;
  Tag m_test_tag;
  Tag m_tag_with_invalid_properties;
  Tag m_test_tag_without_properties;
  
public:
  TinyXmlSearcherTagTest(){}
  virtual ~TinyXmlSearcherTagTest(){}
  void setUp();
  void tearDown();
 
  
  /*starts finding elements using tag struct tests
   * the tags tests uses the sectors part of the teste.xml
   * <sectors default="BCP">
              <sector id="RDL">Radiologia</sector>
              <sector id="BCP">Broncoscopia</sector>
              <sector id="CLP">Colonoscopia</sector>
      </sectors>
      to make any changes its only necessary to 
      change the variables associated with these values
   */
  void GivenATagIfAElementWithTheSameNameAndPropertiesValuesIsFoundReturnsATinyXmlElementPointer();
  
  void GivenATagIfAElementWithTheSameNameIsFoundButCantFindWithTheSamePropertiesValuesReturnNULL();
  
  void GivenATagIfAElementWithTheSameNameIsNotFoundReturnNULL();
  
  void GivenATagIfTheTagHasNoNameReturnNULL();
  
  void GivenATagIfTheTagHasNameButNoPropertiesReturnTheFirstElementWithTheGivenName();
  
  void IfATagHasMoreThenOnePropertiesWillReturnTheFirstElementThatMatchesWithAllTheProperties();
  
  /*starts finding list of elements using tag struct 
  /<sector id="BCP" default="MN" etc="CLP">Radiologia</sector>
  /this tag has been added to test tags with multiple properties
  */
  
  
  /*
   * this tag test uses the sectors part of the teste.xml
   * <sectors default="BCP">
              <sector id="RDL">Radiologia</sector>
              <sector id="BCP">Broncoscopia</sector>
              <sector id="CLP">Colonoscopia</sector>
      </sectors>
      to make any changes its only necessary to 
      change the variables associated with these values
  */
  
  /*
   * this tags tests uses the test part of the teste.xml
   *      
   *      <test id="RZ" value="X2dDL" cpp="b23ea">Radiologia</test>
          <test id="BC" value="R23D" cpp="bee3x">Broncoscopia</test>
          <test id="CL" value="D3dL" cpp="bsdfal">Colonoscopia</test>
          
          <test value="XdfeL" cpp="asd">Radiologia</test>
          <test id="Rsfe"  cpp="dfsdf">Radiologia</test>
          <test id="sfaD" value="fdsfe">Radiologia</test>
          
      to make any changes its only necessary to 
      change the variables associated with these values
   */
  
  void GivenATagThatHaveMultiplePropertiesReturnsAllTheElementsThatHaveTheSameNameAndAllTheProperties();
  
  void GivenATagReturnsAEmptyVectorIfNoElementHasThisName();
  
  void GivenATagReturnsAEmptyVectorIfNoElementHasThisProperties();
  
  void GivenATagWithNoPropertiesWillReturnAllTheElementsWithTheSameNameOfTheTag();
 
  
 };

#endif /*TINYXMLSEARCHERTAGTEST_HPP_*/
