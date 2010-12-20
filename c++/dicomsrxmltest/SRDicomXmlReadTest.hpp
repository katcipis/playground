#ifndef SRDOCUMENTCONTENTIOM_HPP_
#define SRDOCUMENTCONTENTIOM_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <dicomsrxml/SRXmlReader.hpp>

class SRDicomXmlReadTest : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(SRDicomXmlReadTest);
    CPPUNIT_TEST(TheTest);
  CPPUNIT_TEST_SUITE_END();

public:

  SRDicomXmlReadTest();
  virtual ~SRDicomXmlReadTest();

  void TheTest();
  
private:  
  SRXmlReader m_sriod_reader;
     
};

#endif /*SRDOCUMENTCONTENTIOM_HPP_*/
