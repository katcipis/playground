#ifndef SRFORMBUILDER_HPP_
#define SRFORMBUILDER_HPP_

#include "wx/image.h"
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/scrolwin.h>

#include "SRComponentFactory.hpp"
#include "SRComponentHandler.hpp"
#include "SRFormUtil.hpp"
#include <wxsrcomponents/abstract/wxSRComponent.hpp>

using namespace dictionaryeditor;
using namespace std;

class SRFormBuilder : public SRComponentHandler, SRFormUtil{

  public:
    SRFormBuilder(std::string xml_path);
    virtual ~SRFormBuilder();
    
  private:
    
  	wxSRComponent* BuildComponents(SRXmlReader* xml_reader, wxSizer* sizer, std::string code_value,  wxSRComponent* father = NULL);
  	wxSRComponent* BuildComponent(SRXmlReader* xml_reader, wxSizer* sizer);
    
  	void BuildContentSequenceItem(SRXmlReader* reader);
    void BuildConceptNameSeqItem(SRXmlReader* concept_name_code_sequence_item);
    
    void BuildContentSequence(SRXmlReader* content_sequence, SRXmlReader* concept_name, std::string code_value);
    void BuildContentSequence(SRXmlReader* content_sequence, wxSizer* sizer, wxSRComponent* father = NULL);
    void BuildSRDocumentIOM(std::vector<SRXmlReader*> sr_iod_children);
    
    wxScrolledWindow* m_panel;
    wxFrame* m_frame;
    wxSizer* m_sizer;    
};

#endif /*SRFORMBUILDER_HPP_*/
