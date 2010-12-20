#ifndef MINIDICOMXML_HPP_
#define MINIDICOMXML_HPP_

#include <util/xmlutil/Tag.h>
#include <util/FileHandler.hpp>
#include <util/xmlutil/XmlSearcher.hpp>

class ExamModelXml {
public:
	ExamModelXml();
	virtual ~ExamModelXml();

	virtual void ReadFile(std::string path);

	virtual bool FileIsLoaded();

protected:
	Tag m_dcmz_examination;
	Tag m_patient;
	Tag m_patient_name;
	Tag m_birthdate;
	Tag m_doctors;
	Tag m_requester;
	Tag m_executor;
	std::vector<Tag> m_images;
	Tag m_image;
	Tag m_images_tag;
	Tag m_report;

	std::string m_requisition_str;
	std::string m_title;
	std::string m_default;
	std::string m_nro;
	
	TiXmlDocument m_document;
	XmlSearcher m_searcher;

};

#endif /*MINIDICOMXML_HPP_*/
