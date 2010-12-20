#ifndef TINYXMLSEARCHERDEPTHTEST_HPP_
#define TINYXMLSEARCHERDEPTHTEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <xmlutil/Tag.h>
#include <queue>
#include <xmlutil/XmlSearcher.hpp>

class FindingElementsDepthTest : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(FindingElementsDepthTest);
	CPPUNIT_TEST(GivenThePathToAValidTagMustReturnAListOfTiXmlElementsWithTheSameName);
	CPPUNIT_TEST(IfThePathHasTagsWithPropertiesTheSearchWillBeFilteredByThePropertiesGivenTheLastTagPropertiesWillBeIgnored);
	CPPUNIT_TEST(GivenThePathToATagIfATiXmlElementWithSameNameIsNotFoundReturnAEmptyList);
	CPPUNIT_TEST(IfThePathHasTagsWithPropertiesTheSearchWillBeFilteredByThePropertiesIfThePathIsNotFoundReturnsAEmptyList);
  CPPUNIT_TEST(FindingElementsDepthTest::GivenThePathToAValidTagMustReturnANotEmptyListOfTiXmlElementsWithTheSameName);
  CPPUNIT_TEST(GivenThePathToAValidTagMustReturnAListOfTiXmlElementsWithTheSameOrderOfXMLTree);
	CPPUNIT_TEST_SUITE_END();


public:
  void setUp();
  void tearDown();

protected:
	std::queue<Tag> m_pathToSectorsTag;
	std::queue<Tag> m_path_to_name_in_portal_cyclops;
	std::queue<Tag> m_path_to_wrong_name_in_portal_cyclops;
	std::queue<Tag> m_path_to_name_with_wrong_properties_in_portal_cyclops;
  XmlSearcher m_searcher;
  TiXmlDocument m_xml_doc;
  
  
  Tag m_tag_sector_radiologia;
  Tag m_tag_sector_broncoscopia;
  Tag m_tag_sector_colonoscopia;
  Tag m_tag_sector_radiologiaMN;
 
  Tag m_tag_portal_cyclops_name;
  std::string m_tag_portal_cyclops_text;
  
  //----------------------------------------------------------------//
  // TESTs
  //----------------------------------------------------------------//
  /*
	 * Tests of the method that can return a list of
	 * tags, to get all tags with a name the desired tag must
	 * be passed with the properties map empty, if there is properties
	 * will return only the tags that have those attributes
	 * the value of the atributes will not be considered, only 
	 * if it has the attributes
	 */
	
  
	void GivenThePathToAValidTagMustReturnAListOfTiXmlElementsWithTheSameName();
		
	void IfThePathHasTagsWithPropertiesTheSearchWillBeFilteredByThePropertiesGivenTheLastTagPropertiesWillBeIgnored();
	
  void GivenThePathToAValidTagMustReturnANotEmptyListOfTiXmlElementsWithTheSameName();
  
	void GivenThePathToATagIfATiXmlElementWithSameNameIsNotFoundReturnAEmptyList();
	
	void IfThePathHasTagsWithPropertiesTheSearchWillBeFilteredByThePropertiesIfThePathIsNotFoundReturnsAEmptyList();

  void GivenThePathToAValidTagMustReturnAListOfTiXmlElementsWithTheSameOrderOfXMLTree();

};

#endif /*TINYXMLSEARCHERDEPTHTEST_HPP_*/
