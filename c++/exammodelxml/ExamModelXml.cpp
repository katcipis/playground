#include "ExamModelXml.hpp"

ExamModelXml::ExamModelXml() {
	m_dcmz_examination = Tag("dcmz-examination");
	m_patient = Tag("patient");
	m_patient_name = Tag("name");
	m_birthdate = Tag("birthdate");
	m_doctors = Tag("doctors");
	m_requester = Tag("requester");
	m_executor = Tag("executor");
	m_image = Tag("image");
	m_report = Tag("report");
	m_images_tag = Tag("images");
	
	m_requisition_str = "requisition";
	m_title = "title";
	m_default = "";
	m_nro = "nro";
}

ExamModelXml::~ExamModelXml() {

}

bool ExamModelXml::FileIsLoaded(){
	return m_searcher.DocumentIsOk(m_document);
}

void ExamModelXml::ReadFile(std::string path) {
	
	m_document = TiXmlDocument(path.c_str());
	m_document.LoadFile();
	
	if (!FileIsLoaded()) {
		util::FileHandler handler = util::FileHandler();

		if (handler.Create(path))
			m_document.LoadFile(path.c_str());
		
	}
	
}
