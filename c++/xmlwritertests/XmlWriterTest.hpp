#ifndef XMLWRITERTEST_HPP_
#define XMLWRITERTEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <xmlutil/Tag.h>
#include <xmlutil/XmlSearcher.hpp>
#include <xmlutil/XmlWriter.hpp>
#include <xmlutil/tinyxml/tinyxml.h>
#include <queue>
#include <list>

class XmlWriterTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(XmlWriterTest);
CPPUNIT_TEST(GivenAValidPathAndAFatherTagAndAListOfChildrenTagsWillWriteInsideTheFatherTagAllTheTagsInTheList);
CPPUNIT_TEST(IfThePathIsValidAndTheFatherTagDontExistsWillCreateTheFatherTagAndWriteAllTheChilren);
CPPUNIT_TEST(IfThePathIsValidAndTheFatherTagExistsWillOverwirteTheChildrenInTheFileWithTheChildrenInTheList);
CPPUNIT_TEST(IfThePathAndFatherTagIsValidAndTheTagListIsEmptyWillOverwriteTheFatherTagWithNoSonsTags);
CPPUNIT_TEST(IfTheTiXmlDocumentIsEmptyWritesAllTheTagsOnTheEmptyFile);
CPPUNIT_TEST_SUITE_END();

public:
void setUp();
void tearDown();

/*
 * Before running the tests remember to erase the test tags
 * on the test.xml file. If you not erase them the tests
 * will fail. To see the action of one of the tests
 * in the file disable the other tests, some tests
 * may overwrite the data on the file that the other
 * test has written.
 */

void GivenAValidPathAndAFatherTagAndAListOfChildrenTagsWillWriteInsideTheFatherTagAllTheTagsInTheList();
void IfThePathIsValidAndTheFatherTagDontExistsWillCreateTheFatherTagAndWriteAllTheChilren();
void IfThePathIsValidAndTheFatherTagExistsWillOverwirteTheChildrenInTheFileWithTheChildrenInTheList();
void IfThePathAndFatherTagIsValidAndTheTagListIsEmptyWillOverwriteTheFatherTagWithNoSonsTags();
void IfTheTiXmlDocumentIsEmptyWritesAllTheTagsOnTheEmptyFile();

private:

TiXmlDocument m_xml_doc;
TiXmlDocument m_empty_doc;
std::queue<Tag> m_path_tag_institution;

Tag m_sectors_id3_tag;
Tag m_idtest_tag;

Tag m_test_tag;
Tag m_test1_tag;
Tag m_test2_tag;
Tag m_test3_tag;

Tag m_overwrite_tag;
Tag m_overwrite1_tag;
Tag m_overwrite2_tag;
Tag m_overwrite3_tag;

XmlSearcher m_xml_searcher;
XmlWriter m_xml_writer;

};

#endif /*XMLWRITERTEST_HPP_*/
