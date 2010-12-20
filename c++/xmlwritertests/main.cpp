#include <cppunit/ui/text/TestRunner.h>
#include "XmlWriterTest.hpp"

int main() {

	CPPUNIT_TEST_SUITE_REGISTRATION(XmlWriterTest);

	CppUnit::Test* test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(test);
	runner.run();

}
