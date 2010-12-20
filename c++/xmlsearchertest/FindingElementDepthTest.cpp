#include "FindingElementDepthTest.hpp"

void FindingElementDepthTest::setUp() {
	m_tag_father = Tag("portals");
	m_tag_son = Tag("localDatabase");
	m_tag_son_of_son = Tag("name");

	m_invalid_tag_father = Tag("modalities");
	m_invalid_tag_son = Tag("modality");
	m_invalid_tag_son_of_son = Tag("password");

	m_tag_son_value = "localDatabase";
	m_tag_son_of_son_value = "name";
	m_tag_son_of_son_text = "Dicomizer Local Database";

	m_tag_son_with_attributes = Tag("portal");
	m_tag_son_with_attributes.properties["id"] = "hu";

	m_invalid_tag_son_with_attributes = Tag("portal");
	m_invalid_tag_son_with_attributes.properties["id"] = "wrongid";

	m_tag_son_of_son_with_attributes = Tag("databaseName");

	m_tag_son_of_son_with_attributes_value = "databaseName";
	m_tag_son_of_son_with_attributes_text = "telemedicina2";

	m_first_tag_son_of_son_with_attributes_value
			= m_tag_son_of_son_with_attributes_value;
	m_first_tag_son_of_son_with_attributes_text
			= m_tag_son_of_son_with_attributes_text;

	m_tag_son_without_attributes = Tag("portal");

	m_searcher = XmlSearcher();

	m_doc = TiXmlDocument();
	m_doc.LoadFile("test.xml");
}

void FindingElementDepthTest::tearDown() {

}

void FindingElementDepthTest::GivenTheFatherAndTheSonTagReturnATiXmlElement() {

	std::queue<Tag> tags;
	tags.push(m_tag_father);
	tags.push(m_tag_son);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, tags);
	CPPUNIT_ASSERT(element != NULL);
	CPPUNIT_ASSERT(strcmp(element->Value(), m_tag_son_value.c_str()) == 0);

}

void FindingElementDepthTest::GivenThePathToATagReturnATiXmlElement() {

	std::queue<Tag> tags;
	tags.push(m_tag_father);
	tags.push(m_tag_son);
	tags.push(m_tag_son_of_son);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, tags);

	CPPUNIT_ASSERT(element != NULL);
	CPPUNIT_ASSERT(strcmp(element->GetText(), m_tag_son_of_son_text.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(element->Value(), m_tag_son_of_son_value.c_str()) == 0);
}

void FindingElementDepthTest::GivenTheFatherAndTheSonTagIfSomeOfTheTagsAreInvalidReturnsNull() {

	std::queue<Tag> invalid_tags_1;
	std::queue<Tag> invalid_tags_2;

	invalid_tags_1.push(m_invalid_tag_father);
	invalid_tags_1.push(m_tag_son);

	invalid_tags_2.push(m_tag_father);
	invalid_tags_2.push(m_invalid_tag_son);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, invalid_tags_1);
	CPPUNIT_ASSERT(element == NULL);

	element = m_searcher.FindElementInDepth(m_doc, invalid_tags_2);
	CPPUNIT_ASSERT(element == NULL);

}

void FindingElementDepthTest::GivenThePathToATagIfSomeOfTheTagsAreInvalidReturnsNull() {

	std::queue<Tag> invalid_tags_1;
	std::queue<Tag> invalid_tags_2;
	std::queue<Tag> invalid_tags_3;

	invalid_tags_1.push(m_invalid_tag_father);
	invalid_tags_1.push(m_tag_son);
	invalid_tags_1.push(m_tag_son_of_son);

	invalid_tags_2.push(m_tag_father);
	invalid_tags_2.push(m_invalid_tag_son);
	invalid_tags_2.push(m_tag_son_of_son);

	invalid_tags_3.push(m_tag_father);
	invalid_tags_3.push(m_tag_son);
	invalid_tags_3.push(m_invalid_tag_son_of_son);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, invalid_tags_1);
	CPPUNIT_ASSERT(element == NULL);

	element = m_searcher.FindElementInDepth(m_doc, invalid_tags_2);
	CPPUNIT_ASSERT(element == NULL);

	element = m_searcher.FindElementInDepth(m_doc, invalid_tags_3);
	CPPUNIT_ASSERT(element == NULL);
}

void FindingElementDepthTest::GivenThePathToATagWithAttributesReturnATiXmlElementThatHasTheSameAttributesValues() {
	std::queue<Tag> tags;
	tags.push(m_tag_father);
	tags.push(m_tag_son_with_attributes);
	tags.push(m_tag_son_of_son_with_attributes);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, tags);

	CPPUNIT_ASSERT(element != NULL);
	CPPUNIT_ASSERT(strcmp(element->Value(),
			m_tag_son_of_son_with_attributes_value.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(element->GetText(),
			m_tag_son_of_son_with_attributes_text.c_str()) == 0);

}

void FindingElementDepthTest::GivenThePathToATagWithAttributesIfAElementHasTheAttributesWithDiferentValuesReturnsNull() {
	std::queue<Tag> tags;
	tags.push(m_tag_father);
	tags.push(m_invalid_tag_son_with_attributes);
	tags.push(m_tag_son_of_son_with_attributes);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, tags);

	CPPUNIT_ASSERT(element == NULL);
}

void FindingElementDepthTest::IfInTheGivenPathExistsMultipleTagsWithTheSameValueAndTheAttributesHaveNotBeenInformedReturnsTheFirstOne() {
	std::queue<Tag> tags;
	tags.push(m_tag_father);
	tags.push(m_tag_son_without_attributes);
	tags.push(m_tag_son_of_son_with_attributes);

	TiXmlElement * element = m_searcher.FindElementInDepth(m_doc, tags);

	CPPUNIT_ASSERT(element != NULL);
	CPPUNIT_ASSERT(strcmp(element->Value(),
			m_first_tag_son_of_son_with_attributes_value.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(element->GetText(),
			m_first_tag_son_of_son_with_attributes_text.c_str()) == 0);
}
