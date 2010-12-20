/*
 to run the tests implement a main
 that creates a teste runner and 
 obtain the test suites from
 the TinyXmlSearcherTest
 */

#include <cppunit/ui/text/TestRunner.h>
#include "XmlSearcherTest.hpp"
#include "XmlSearcherTagTest.hpp"
#include "FindingElementDepthTest.hpp"
#include "FindingElementsDepthTest.hpp"
#include <queue>
int main() {

	CPPUNIT_TEST_SUITE_REGISTRATION(XmlSearcherTest);
	CPPUNIT_TEST_SUITE_REGISTRATION(TinyXmlSearcherTagTest);
	CPPUNIT_TEST_SUITE_REGISTRATION(FindingElementDepthTest);
	CPPUNIT_TEST_SUITE_REGISTRATION(FindingElementsDepthTest);

	CppUnit::Test* test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(test);
	runner.run();

	return 0;
}

