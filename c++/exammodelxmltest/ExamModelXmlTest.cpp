#include "ExamModelXmlTest.hpp"

ExamModelXmlTest::ExamModelXmlTest(){
  m_reader.ReadFile("./test.xml");
  m_writer.ReadFile("./writetest.xml");
  m_writer_two.ReadFile("./writetest2.xml");
  m_reader.Read();
}

ExamModelXmlTest::~ExamModelXmlTest(){
  
}

void ExamModelXmlTest::RunTest(){
  
  m_writer.SetDcmzExaminationRequisition(m_reader.GetDcmzExaminationRequisition());
  m_writer.SetDcmzExaminationTitle(m_reader.GetDcmzExaminationTitle());
  m_writer.SetPatientName(m_reader.GetPatientName());
  m_writer.SetPatientBirthdate(m_reader.GetPatientBirthdate());
  m_writer.SetDoctorRequester(m_reader.GetDoctorRequester());
  m_writer.SetDoctorExecutor(m_reader.GetDoctorExecutor());
  m_writer.SetReport(m_reader.GetReport());
  
  std::vector<std::string> images = m_reader.GetImages();
  
  for(unsigned int i = 0; i < images.size(); i++)
    m_writer.SetImage(images.at(i));
  
  m_writer.Write();
  Examination* exam = m_reader.GetExamination();
  m_writer_two.SetExamination(exam);
  m_writer_two.Write();
  std::cout << exam->ToString() << std::endl;
  
  std::cout << "End of Test";
}
