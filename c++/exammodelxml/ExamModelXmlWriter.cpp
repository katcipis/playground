#include "ExamModelXmlWriter.hpp"
#include <util/StringHandler.hpp>

ExamModelXmlWriter::ExamModelXmlWriter() {
}

ExamModelXmlWriter::~ExamModelXmlWriter() {
}

void ExamModelXmlWriter::Write() {

  std::queue<Tag> root;
  std::list<Tag> children;

  m_writer.UpdateTag(m_document, root, m_dcmz_examination);
  root.push(m_dcmz_examination);

  children.push_back(m_patient_name);
  children.push_back(m_birthdate);
  m_writer.UpdateTag(m_document, root, m_patient, children);
  children.clear();

  children.push_back(m_requester);
  children.push_back(m_executor);
  m_writer.UpdateTag(m_document, root, m_doctors, children);
  children.clear();

  for (unsigned int i = 0; i < m_images.size(); i++)
    children.push_back(m_images.at(i));

  m_images_tag.properties[m_nro]
      = util::StringHandler::IntToString(m_images.size());
  m_writer.UpdateTag(m_document, root, m_images_tag, children);
  children.clear();

}

void ExamModelXmlWriter::SetDcmzExaminationRequisition(std::string dcmz_req) {
  m_dcmz_examination.properties[m_requisition_str] = dcmz_req;
}

void ExamModelXmlWriter::SetDcmzExaminationTitle(std::string dcmz_tit) {
  m_dcmz_examination.properties[m_title] = dcmz_tit;
}

void ExamModelXmlWriter::SetPatientName(std::string patient_name) {
  m_patient_name.text = patient_name;
}

void ExamModelXmlWriter::SetPatientBirthdate(std::string patient_birth) {
  m_birthdate.text = patient_birth;
}

void ExamModelXmlWriter::SetDoctorRequester(std::string doctor_req) {
  m_requester.text = doctor_req;
}

void ExamModelXmlWriter::SetDoctorExecutor(std::string doctor_exec) {
  m_executor.text = doctor_exec;
}

void ExamModelXmlWriter::SetImage(std::string image) {
  Tag tmp = Tag(m_image.name);
  tmp.text = image;
  m_images.push_back(tmp);
}

void ExamModelXmlWriter::SetReport(std::string report) {
  m_report.text = report;
}

void ExamModelXmlWriter::SetExamination(Examination* exam) {
  
  BuildImages(exam);
  BuildDoctor(exam);
  BuildPatient(exam);

  SetDcmzExaminationTitle(exam->GetTitle());
  SetDcmzExaminationRequisition(exam->GetId());
  
}

void ExamModelXmlWriter::BuildImages(Examination* exam) {
  std::list<ExamData*> exams = exam->GetExamData();
  std::list<ExamData*>::iterator iter;
  for(iter = exams.begin(); iter != exams.end(); iter++){
    ExamData* tmp = *iter;
    if(tmp->GetFormat() == ExamData::FORMAT_IMAGE)
      SetImage(tmp->GetPath());
  }
}

void ExamModelXmlWriter::BuildDoctor(Examination* exam) {
  Doctor* requester = exam->GetDoctor(dr_request_doctor);
  Doctor* executor = exam->GetDoctor(dr_perform_doctor);

  if (requester)
    SetDoctorRequester(requester->GetName());

  if (executor)
    SetDoctorExecutor(executor->GetName());

}

void ExamModelXmlWriter::BuildPatient(Examination* exam) {
  Patient* patient = exam->GetPatient();

  if (patient) {
    SetPatientName(patient->GetName());

    DateTime* date = patient->GetBirthdate();
    int month = date->GetMonth();

    std::string date_str = StringHandler::IntToString(date->GetDay())
        + util::c_default_date_separator +StringHandler::IntToString(month)
        + util::c_default_date_separator
        +StringHandler::IntToString(date->GetYear());

    SetPatientBirthdate(date_str);
  }

}
