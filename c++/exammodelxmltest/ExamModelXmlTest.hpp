#ifndef EXAMMODELXMLREADERTEST_HPP_
#define EXAMMODELXMLREADERTEST_HPP_

#include <exammodelxml/ExamModelXmlReader.hpp>
#include <exammodelxml/ExamModelXmlWriter.hpp>

class ExamModelXmlTest {
  
  public:
    ExamModelXmlTest();
    ~ExamModelXmlTest();
    
    void RunTest();
  
  private:
    ExamModelXmlReader m_reader;
    ExamModelXmlWriter m_writer;
    ExamModelXmlWriter m_writer_two;
  
};

#endif /*EXAMMODELXMLREADERTEST_HPP_*/
