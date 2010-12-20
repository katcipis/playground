#include "FindingElementsDepthTest.hpp"
using namespace std;

void FindingElementsDepthTest::setUp() {
	Tag applicationEntities("ApplicationEntities");
	Tag configuration("configuration");

	Tag portals("portals");

	Tag institution("institution");
	Tag sectors("sectors");
	Tag sector("sector");

	Tag tag_portal_cyclops("portal");
	tag_portal_cyclops.properties["id"] = "cyclops";
	tag_portal_cyclops.properties["test"] = "test";

	Tag tag_portal_cyclops_with_wrong_properties("portal");
	tag_portal_cyclops_with_wrong_properties.properties["id"] = "cyclops2";
	tag_portal_cyclops_with_wrong_properties.properties["test"] = "test2";

	m_tag_portal_cyclops_name = Tag("name");
	m_tag_portal_cyclops_text = "Cyclops";

	m_pathToSectorsTag.push(applicationEntities);
	m_pathToSectorsTag.push(configuration);
	m_pathToSectorsTag.push(institution);
	m_pathToSectorsTag.push(sectors);
	m_pathToSectorsTag.push(sector);

	m_path_to_name_in_portal_cyclops.push(applicationEntities);
	m_path_to_name_in_portal_cyclops.push(configuration);
	m_path_to_name_in_portal_cyclops.push(portals);
	m_path_to_name_in_portal_cyclops.push(tag_portal_cyclops);
	m_path_to_name_in_portal_cyclops.push(m_tag_portal_cyclops_name);

	m_path_to_wrong_name_in_portal_cyclops.push(applicationEntities);
	m_path_to_wrong_name_in_portal_cyclops.push(configuration);
	m_path_to_wrong_name_in_portal_cyclops.push(portals);
	m_path_to_wrong_name_in_portal_cyclops.push(tag_portal_cyclops);
	m_path_to_wrong_name_in_portal_cyclops.push(Tag("WrongName"));

	m_path_to_name_with_wrong_properties_in_portal_cyclops.push(applicationEntities);
	m_path_to_name_with_wrong_properties_in_portal_cyclops.push(configuration);
	m_path_to_name_with_wrong_properties_in_portal_cyclops.push(portals);
	m_path_to_name_with_wrong_properties_in_portal_cyclops.push(tag_portal_cyclops_with_wrong_properties);
	m_path_to_name_with_wrong_properties_in_portal_cyclops.push(m_tag_portal_cyclops_name);

	m_searcher = XmlSearcher();

	m_xml_doc.LoadFile("test.xml");

	// tag -------------------------------------------------------------------//
	m_tag_sector_radiologia = Tag("sector");
	m_tag_sector_radiologia.properties["id"] = "RDL";

	m_tag_sector_broncoscopia = Tag("sector");
	m_tag_sector_broncoscopia.properties["id"] = "BCP";

	m_tag_sector_colonoscopia = Tag("sector");
	m_tag_sector_colonoscopia.properties["id"] = "CLP";

	m_tag_sector_radiologiaMN = Tag("sector");
	m_tag_sector_radiologiaMN.properties["id"] = "BCP";
	m_tag_sector_radiologiaMN.properties["default"] = "MN";
	m_tag_sector_radiologiaMN.properties["etc"] = "CLP";

}

void FindingElementsDepthTest::tearDown() {
}

void FindingElementsDepthTest::GivenThePathToAValidTagMustReturnAListOfTiXmlElementsWithTheSameName() {
	std::list<TiXmlElement*> testList;
	testList = m_searcher.FilterElementsInDepth(m_xml_doc, m_pathToSectorsTag);

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_radiologia.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_radiologia.properties["id"].c_str())== 0);
	testList.pop_front();

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_broncoscopia.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_broncoscopia.properties["id"].c_str())
			== 0);
	testList.pop_front();

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_colonoscopia.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_colonoscopia.properties["id"].c_str())
			== 0);
	testList.pop_front();

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_radiologiaMN.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_radiologiaMN.properties["id"].c_str())
			== 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("default"),
			m_tag_sector_radiologiaMN.properties["default"].c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("etc"), m_tag_sector_radiologiaMN.properties["etc"].c_str())
			== 0);
}

void FindingElementsDepthTest::GivenThePathToAValidTagMustReturnANotEmptyListOfTiXmlElementsWithTheSameName() {
	std::list<TiXmlElement*> testList;
	testList = m_searcher.FilterElementsInDepth(m_xml_doc, m_pathToSectorsTag);

	CPPUNIT_ASSERT( !testList.empty());
}

void FindingElementsDepthTest::GivenThePathToAValidTagMustReturnAListOfTiXmlElementsWithTheSameOrderOfXMLTree() {
	std::list<TiXmlElement*> testList;
	testList = m_searcher.FilterElementsInDepth(m_xml_doc, m_pathToSectorsTag);

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_radiologia.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_radiologia.properties["id"].c_str())== 0);
	testList.pop_front();

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_broncoscopia.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_broncoscopia.properties["id"].c_str())
			== 0);
	testList.pop_front();

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_colonoscopia.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_colonoscopia.properties["id"].c_str())
			== 0);
	testList.pop_front();

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_sector_radiologiaMN.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("id"), m_tag_sector_radiologiaMN.properties["id"].c_str())
			== 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("default"),
			m_tag_sector_radiologiaMN.properties["default"].c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->Attribute("etc"), m_tag_sector_radiologiaMN.properties["etc"].c_str())
			== 0);
}

void FindingElementsDepthTest::IfThePathHasTagsWithPropertiesTheSearchWillBeFilteredByThePropertiesGivenTheLastTagPropertiesWillBeIgnored() {
	std::list<TiXmlElement*> testList;
	testList = m_searcher.FilterElementsInDepth(m_xml_doc,
			m_path_to_name_in_portal_cyclops);

	CPPUNIT_ASSERT(testList.size() == 1);

	CPPUNIT_ASSERT(strcmp(testList.front()->Value(), m_tag_portal_cyclops_name.name.c_str()) == 0);
	CPPUNIT_ASSERT(strcmp(testList.front()->GetText(), m_tag_portal_cyclops_text.c_str()) == 0);
	testList.pop_front();

}

void FindingElementsDepthTest::GivenThePathToATagIfATiXmlElementWithSameNameIsNotFoundReturnAEmptyList() {

	std::list<TiXmlElement*> testList;
	testList = m_searcher.FilterElementsInDepth(m_xml_doc,
			m_path_to_wrong_name_in_portal_cyclops);

	CPPUNIT_ASSERT(testList.empty());
}

void FindingElementsDepthTest::IfThePathHasTagsWithPropertiesTheSearchWillBeFilteredByThePropertiesIfThePathIsNotFoundReturnsAEmptyList() {

	std::list<TiXmlElement*> testList;
	testList = m_searcher.FilterElementsInDepth(m_xml_doc,
			m_path_to_name_with_wrong_properties_in_portal_cyclops);

}
