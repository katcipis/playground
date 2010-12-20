#ifndef MINIDICOMXMLWRITER_HPP_
#define MINIDICOMXMLWRITER_HPP_

#include "ExamModelXml.hpp"
#include <util/xmlutil/XmlWriter.hpp>
#include <exammodel/Examination.hpp>

using namespace exammodel;
using namespace util;

class ExamModelXmlWriter : public ExamModelXml {

  public:
    ExamModelXmlWriter();
    virtual ~ExamModelXmlWriter();

    void Write();
    void SetDcmzExaminationRequisition(std::string dcmz_req);
    void SetDcmzExaminationTitle(std::string dcmz_tit);
    void SetPatientName(std::string patient_name);
    void SetPatientBirthdate(std::string patient_birth);
    void SetDoctorRequester(std::string doctor_req);
    void SetDoctorExecutor(std::string doctor_exec);
    void SetImage(std::string image);
    void SetReport(std::string report);
    void SetExamination(Examination* exam);

  private:
    void BuildImages(Examination* exam);
    void BuildDoctor(Examination* exam);
    void BuildPatient(Examination* exam);
    XmlWriter m_writer;

};

#endif /*MINIDICOMXMLWRITER_HPP_*/
