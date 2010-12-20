#ifndef FINDINGELEMENTDEPTHTEST_HPP_
#define FINDINGELEMENTDEPTHTEST_HPP_
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <xmlutil/Tag.h>
#include <queue>
#include <xmlutil/XmlSearcher.hpp>

class FindingElementDepthTest : public CppUnit::TestFixture{

	CPPUNIT_TEST_SUITE(FindingElementDepthTest);
		CPPUNIT_TEST(GivenTheFatherAndTheSonTagReturnATiXmlElement);
		CPPUNIT_TEST(GivenThePathToATagReturnATiXmlElement);
		CPPUNIT_TEST(GivenTheFatherAndTheSonTagIfSomeOfTheTagsAreInvalidReturnsNull);
		CPPUNIT_TEST(GivenThePathToATagIfSomeOfTheTagsAreInvalidReturnsNull);
		CPPUNIT_TEST(GivenThePathToATagWithAttributesReturnATiXmlElementThatHasTheSameAttributesValues);
		CPPUNIT_TEST(GivenThePathToATagWithAttributesIfAElementHasTheAttributesWithDiferentValuesReturnsNull);
		CPPUNIT_TEST(IfInTheGivenPathExistsMultipleTagsWithTheSameValueAndTheAttributesHaveNotBeenInformedReturnsTheFirstOne);
	CPPUNIT_TEST_SUITE_END();
	
private:

	Tag m_tag_father;
	Tag m_tag_son;
	Tag m_tag_son_of_son;
	Tag m_tag_son_with_attributes;
	Tag m_first_tag_son_with_attributes;
	Tag m_tag_son_of_son_with_attributes;

	Tag m_invalid_tag_father;
	Tag m_invalid_tag_son;
	Tag m_invalid_tag_son_of_son;
	Tag m_invalid_tag_son_with_attributes;
	Tag m_tag_son_without_attributes;

	std::string m_tag_son_value;
	std::string m_tag_son_of_son_value;
	std::string m_tag_son_of_son_text;
	std::string m_tag_son_of_son_with_attributes_value;
	std::string m_tag_son_of_son_with_attributes_text;
	std::string m_first_tag_son_of_son_with_attributes_value;
	std::string m_first_tag_son_of_son_with_attributes_text;

	XmlSearcher m_searcher;

	TiXmlDocument m_doc;

public:

	void setUp();
	void tearDown();
	

	/*The Tags must be placed in the Queue in the order of deepness
	 The deepest Tag must be the last one inserted in the Queue
	 */
	void GivenTheFatherAndTheSonTagReturnATiXmlElement();
	
	void GivenTheFatherAndTheSonTagIfSomeOfTheTagsAreInvalidReturnsNull();
	
	void GivenThePathToATagReturnATiXmlElement();
	
	void GivenThePathToATagIfSomeOfTheTagsAreInvalidReturnsNull();

	//Tests for tags with attributes
	void
			GivenThePathToATagWithAttributesReturnATiXmlElementThatHasTheSameAttributesValues();
	void
			GivenThePathToATagWithAttributesIfAElementHasTheAttributesWithDiferentValuesReturnsNull();
	void
			IfInTheGivenPathExistsMultipleTagsWithTheSameValueAndTheAttributesHaveNotBeenInformedReturnsTheFirstOne();
	

};
#endif /*FINDINGELEMENTDEPTHTEST_HPP_*/
