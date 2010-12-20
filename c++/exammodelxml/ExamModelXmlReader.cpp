#include "ExamModelXmlReader.hpp"
#include <util/StringHandler.hpp>

ExamModelXmlReader::ExamModelXmlReader() {

}

ExamModelXmlReader::~ExamModelXmlReader() {

}

void ExamModelXmlReader::Read() {

  if (FileIsLoaded()) {

    m_patient_name = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document, m_patient_name.name));

    m_birthdate = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document, m_birthdate.name));

    m_requester = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document, m_requester.name));

    m_executor = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document, m_executor.name));

    m_report = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document, m_report.name));

    m_dcmz_examination = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document,
        m_dcmz_examination.name));

    m_images = m_searcher.DeepFindElements(m_document, m_image);

    m_images_tag = m_searcher
    .FromElementToTag(m_searcher.FindElement(m_document, m_images_tag.name));
  }

}

std::string ExamModelXmlReader::GetDcmzExaminationRequisition() {
  if (m_dcmz_examination.HasPropertie(m_requisition_str))
    return m_dcmz_examination.properties[m_requisition_str];

  return m_default;
}

std::string ExamModelXmlReader::GetDcmzExaminationTitle() {
  if (m_dcmz_examination.HasPropertie(m_title))
    return m_dcmz_examination.properties[m_title];

  return m_default;
}

std::string ExamModelXmlReader::GetPatientName() {
  return m_patient_name.text;
}

std::string ExamModelXmlReader::GetPatientBirthdate() {
  return m_birthdate.text;
}

std::string ExamModelXmlReader::GetDoctorRequester() {
  return m_requester.text;
}

std::string ExamModelXmlReader::GetDoctorExecutor() {
  return m_executor.text;
}

std::vector<std::string> ExamModelXmlReader::GetImages() {
  std::vector<std::string> images;

  for (unsigned int i = 0; i < m_images.size(); i++) {
    images.push_back(m_images.at(i).text);
  }

  return images;
}

std::string ExamModelXmlReader::GetReport() {
  return m_report.text;
}

int ExamModelXmlReader::GetImagesNro() {
  int i = 0;

  if (m_images_tag.HasPropertie(m_nro))
    i = util::StringHandler::IntValue(m_images_tag.properties[m_nro]);

  return i;
}

Examination* ExamModelXmlReader::GetExamination() {
  Examination* exam = new Examination();
  
  BuildImages(exam);
  BuildDoctor(exam);
  BuildPatient(exam);
 
  exam->SetTitle(GetDcmzExaminationTitle());
  exam->SetId(GetDcmzExaminationRequisition());
  
  return exam;
}

void ExamModelXmlReader::BuildPatient(Examination* exam){
  Patient* tmp = new Patient(GetPatientName());
  DateTime* birth = new DateTime(GetPatientBirthdate());
  tmp->SetBirthdate(*birth);
  
  exam->SetPatient(*tmp);
}

void ExamModelXmlReader::BuildDoctor(Examination* exam) {
  Doctor* doc_requester = new Doctor(GetDoctorRequester());
  Doctor* doc_executor = new Doctor(GetDoctorExecutor());
  doc_requester->AddRole(dr_request_doctor);
  doc_executor->AddRole(dr_perform_doctor);
  
  exam->SetDoctor(*doc_requester, dr_request_doctor);
  exam->SetDoctor(*doc_executor, dr_perform_doctor);
}

void ExamModelXmlReader::BuildImages(Examination* exam){
  std::list<ExamData*> images;
  
  for(unsigned int i = 0; i < m_images.size(); i++){
    std::string path = m_images.at(i).text;
    ExamData* data = new ExamData(path);
    data->SetFormat(ExamData::FORMAT_IMAGE);
    images.push_back(data);
  }
  
  exam->SetExamData(images);
  
}
