#ifndef MINIDICOMXMLREADER_HPP_
#define MINIDICOMXMLREADER_HPP_

#include "ExamModelXml.hpp"
#include <exammodel/Examination.hpp>

using namespace exammodel;
using namespace util;

class ExamModelXmlReader : public ExamModelXml {

  public:
    ExamModelXmlReader();
    virtual ~ExamModelXmlReader();

    void Read();
    std::string GetDcmzExaminationRequisition();
    std::string GetDcmzExaminationTitle();
    std::string GetPatientName();
    std::string GetPatientBirthdate();
    std::string GetDoctorRequester();
    std::string GetDoctorExecutor();
    std::vector<std::string> GetImages();
    int GetImagesNro();
    std::string GetReport();
    Examination* GetExamination();
    
  private:
    
    void BuildDoctor(Examination* exam);
    void BuildPatient(Examination* exam);
    void BuildImages(Examination* exam);
};

#endif /*MINIDICOMXMLREADER_HPP_*/
