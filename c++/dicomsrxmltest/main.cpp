#include <cppunit/ui/text/TestRunner.h>
#include "SRDicomXmlReadTest.hpp"

int main() {

  CPPUNIT_TEST_SUITE_REGISTRATION(SRDicomXmlReadTest);

  CppUnit::Test* test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  CppUnit::TextUi::TestRunner runner;
  runner.addTest(test);
  runner.run();

  return 0;
}
