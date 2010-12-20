#include "./XmlWriterTest.hpp"

void XmlWriterTest::setUp() {

	this->m_empty_doc = TiXmlDocument("empty.xml");
	this->m_empty_doc.LoadFile();

	this->m_xml_doc = TiXmlDocument("test.xml");
	this->m_xml_doc.LoadFile();

	this->m_path_tag_institution.push(Tag("ApplicationEntities"));
	this->m_path_tag_institution.push(Tag("configuration"));
	this->m_path_tag_institution.push(Tag("institution"));

	this->m_sectors_id3_tag = Tag("sectors");
	this->m_sectors_id3_tag.properties["id"] = "3";

	this->m_test_tag = Tag("test");

	this->m_idtest_tag = Tag("erase_me");
	this->m_idtest_tag.properties["id"] = "just_testing";

	this->m_test1_tag = Tag("test");
	this->m_test2_tag = Tag("test");
	this->m_test3_tag = Tag("test");

	this->m_test1_tag.properties["id"] = "1";
	this->m_test2_tag.properties["id"] = "2";
	this->m_test3_tag.properties["id"] = "3";

	this->m_test1_tag.text = "Delete this tags to run the write tests";
	this->m_test2_tag.text = "Delete this tags to run the write tests";
	this->m_test3_tag.text = "Delete this tags to run the write tests";

	this->m_overwrite_tag = Tag("overwrited");

	this->m_overwrite1_tag = Tag("overwrited");
	this->m_overwrite2_tag = Tag("overwrited");
	this->m_overwrite3_tag = Tag("overwrited");

	this->m_overwrite1_tag.properties["id"] = "1";
	this->m_overwrite2_tag.properties["id"] = "2";
	this->m_overwrite3_tag.properties["id"] = "3";

}

void XmlWriterTest::tearDown() {

}

void XmlWriterTest::GivenAValidPathAndAFatherTagAndAListOfChildrenTagsWillWriteInsideTheFatherTagAllTheTagsInTheList() {

	std::list<Tag> children_to_update;
	children_to_update.push_back(this->m_test1_tag);
	children_to_update.push_back(this->m_test2_tag);
	children_to_update.push_back(this->m_test3_tag);

	std::vector<TiXmlElement *> tags = this->m_xml_searcher.FindElements(
			this->m_xml_doc, this->m_test_tag);

	CPPUNIT_ASSERT(tags.empty());

	this->m_xml_writer.UpdateTag(this->m_xml_doc, this->m_path_tag_institution,
			this->m_sectors_id3_tag, children_to_update);

	tags = this->m_xml_searcher.FindElements(this->m_xml_doc, this->m_test_tag);

	CPPUNIT_ASSERT(!tags.empty());
	CPPUNIT_ASSERT(tags.size() == 3);
}

void XmlWriterTest::IfThePathIsValidAndTheFatherTagDontExistsWillCreateTheFatherTagAndWriteAllTheChilren() {

	std::list<Tag> children_to_update;
	children_to_update.push_back(this->m_test1_tag);
	children_to_update.push_back(this->m_test2_tag);
	children_to_update.push_back(this->m_test3_tag);

	std::vector<TiXmlElement *> tags;

	TiXmlElement * id_test = this->m_xml_searcher.FindElement(this->m_xml_doc,
			this->m_idtest_tag);

	CPPUNIT_ASSERT(id_test == NULL);

	this->m_xml_writer.UpdateTag(this->m_xml_doc, this->m_path_tag_institution,
			this->m_idtest_tag, children_to_update);

	tags = this->m_xml_searcher.FindElements(this->m_xml_doc, this->m_test_tag);
	id_test = this->m_xml_searcher.FindElement(this->m_xml_doc,
			this->m_idtest_tag);

	CPPUNIT_ASSERT(!tags.empty());
	CPPUNIT_ASSERT(tags.size() == 3);
	CPPUNIT_ASSERT(id_test != NULL);

}

void XmlWriterTest::IfThePathIsValidAndTheFatherTagExistsWillOverwirteTheChildrenInTheFileWithTheChildrenInTheList() {

	std::list<Tag> children_to_update;
	children_to_update.push_back(this->m_overwrite1_tag);
	children_to_update.push_back(this->m_overwrite2_tag);
	children_to_update.push_back(this->m_overwrite3_tag);

	std::vector<TiXmlElement *> tags = this->m_xml_searcher.FindElements(
			this->m_xml_doc, this->m_overwrite_tag);

	CPPUNIT_ASSERT(tags.empty());

	this->m_xml_writer.UpdateTag(this->m_xml_doc, this->m_path_tag_institution,
			this->m_sectors_id3_tag, children_to_update);

	tags = this->m_xml_searcher.FindElements(this->m_xml_doc,
			this->m_overwrite_tag);

	CPPUNIT_ASSERT(!tags.empty());
	CPPUNIT_ASSERT(tags.size() == 3);

}

void XmlWriterTest::IfThePathAndFatherTagIsValidAndTheTagListIsEmptyWillOverwriteTheFatherTagWithNoSonsTags() {
	std::list<Tag> children_to_update;

	this->m_xml_writer.UpdateTag(this->m_xml_doc, this->m_path_tag_institution,
			this->m_sectors_id3_tag, children_to_update);

	std::vector<TiXmlElement *> tags = this->m_xml_searcher.FindElements(
			this->m_xml_doc, this->m_sectors_id3_tag);

	CPPUNIT_ASSERT(!tags.empty());

}

void XmlWriterTest::IfTheTiXmlDocumentIsEmptyWritesAllTheTagsOnTheEmptyFile() {
	std::list<Tag> children_to_update;

	this->m_xml_writer.UpdateTag(this->m_empty_doc, this->m_path_tag_institution,
			this->m_sectors_id3_tag, children_to_update);

	this->m_xml_writer.UpdateTag(this->m_empty_doc, this->m_path_tag_institution,
			this->m_overwrite_tag, children_to_update);

	children_to_update.push_back(this->m_overwrite1_tag);
	children_to_update.push_back(this->m_overwrite2_tag);
	children_to_update.push_back(this->m_overwrite3_tag);

	this->m_xml_writer.UpdateTag(this->m_empty_doc, this->m_path_tag_institution,
			this->m_idtest_tag, children_to_update);
}
