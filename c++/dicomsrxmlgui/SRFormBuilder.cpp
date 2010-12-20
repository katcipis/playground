#include "SRFormBuilder.hpp"
#include <util/StringHandler.hpp>
#include <algorithm>
#include <string>
#include "SRXmlStrings.hpp"

using namespace util;
 
SRFormBuilder::SRFormBuilder(std::string xml_path) {

  SRXmlReader xmlreader;
  xmlreader.ReadFile(xml_path);

  m_frame = NULL;
  m_panel = NULL;

  if (xmlreader.FileIsOpen())
    BuildSRDocumentIOM(xmlreader.GetChildrenReaders());

}
SRFormBuilder::~SRFormBuilder() {
}

void SRFormBuilder::BuildContentSequenceItem(SRXmlReader* content_sequence_item) {
  std::vector<SRXmlReader*>
      content_sequence_item_children = content_sequence_item->GetChildrenReaders();

  SRXmlReader* concept_name = GetSRReader(content_sequence_item_children,
      SRXmlStrings::m_concept_name_code_sequence);

  if (concept_name) {
    Tag concept_tag = concept_name->GetCurrentTag();

    if (concept_tag.HasPropertie(SRXmlStrings::m_code_value)) {
      std::string code_value =concept_tag.properties[SRXmlStrings::m_code_value];

      SRXmlReader* content_sequence = GetSRReader(
          content_sequence_item_children, SRXmlStrings::m_content_sequence);

      if (content_sequence)
        BuildContentSequence(content_sequence, concept_name, code_value);
      else
        BuildConceptNameSeqItem(concept_name);

    }

  }

}

wxSRComponent* SRFormBuilder::BuildComponents(SRXmlReader* content_sequence_item, wxSizer* sizer, std::string code_value, wxSRComponent* father) {

  std::vector<SRXmlReader*>
      content_sequence_item_children = content_sequence_item->GetChildrenReaders();

  SRXmlReader* concept_name_code_sequence = GetSRReader(
      content_sequence_item_children,
      SRXmlStrings::m_concept_name_code_sequence);

  std::vector<SRXmlReader*> content_sequences = GetSRReaders(
      content_sequence_item_children, SRXmlStrings::m_content_sequence);

  wxSRComponent* content_sequence_item_comp = NULL;

  if (concept_name_code_sequence) {

    Tag tmp_tag = concept_name_code_sequence->GetCurrentTag();
    Term* tmp_term;

    if (tmp_tag.HasPropertie(SRXmlStrings::m_code_value)) {
      tmp_term
          = m_name_dictionary->GetTerm(tmp_tag.properties[SRXmlStrings::m_code_value]);

      if (code_value == SRXmlStrings::m_empty)
        code_value = tmp_tag.properties[SRXmlStrings::m_code_value];
    }

    content_sequence_item_comp = SRComponentFactory::BuildComponent(code_value,
        tmp_term, sizer, m_panel);

  }

  for (unsigned int i = 0; i < content_sequences.size(); i++) {
    if (IsComponentWithChildren(code_value))
      if(content_sequence_item_comp)
        BuildContentSequence(content_sequences.at(i), sizer, content_sequence_item_comp);
      else
        BuildContentSequence(content_sequences.at(i), sizer, father);
    else
      BuildContentSequence(content_sequences.at(i), sizer);
  }

  return content_sequence_item_comp;
}

wxSRComponent* SRFormBuilder::BuildComponent(SRXmlReader* concept_name_code_sequence_item, wxSizer* sizer) {

  Tag tmp_tag = concept_name_code_sequence_item->GetCurrentTag();
  std::string code_value;

  Term* tmp_term;

  if (tmp_tag.HasPropertie(SRXmlStrings::m_code_value)) {
    code_value = tmp_tag.properties[SRXmlStrings::m_code_value];
    tmp_term = m_name_dictionary->GetTerm(code_value);
  }

  return SRComponentFactory::BuildComponent(code_value, tmp_term, sizer,
      m_panel);

}

void SRFormBuilder::BuildConceptNameSeqItem(SRXmlReader* concept_name_code_sequence_item) {

  wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
  m_sizer->Add(sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxGROW|wxTAB_TRAVERSAL, 5);
  BuildComponent(concept_name_code_sequence_item, sizer);
  m_sizer->Layout();
  m_panel->FitInside();
}

void SRFormBuilder::BuildContentSequence(SRXmlReader* content_sequence, SRXmlReader* concept_name, std::string code_value) {

  std::vector<SRXmlReader*> content_sequence_items = GetSRReaders(
      content_sequence->GetChildrenReaders(),
      SRXmlStrings::m_content_sequence_item);

  std::string title = GetCodeMeaning(code_value);
  std::string builder_code_value = code_value;

  if (ComponentHasIndependentChildren(code_value))
    builder_code_value = SRXmlStrings::m_empty;

  if (!content_sequence_items.empty()) {

    wxStaticBox* static_box = new wxStaticBox(m_panel, wxID_STATIC, StringHandler::std2wx(title), wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxSizer* static_sizer = new wxStaticBoxSizer(static_box, wxVERTICAL);
    wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    static_sizer->Add(sizer, 1, wxGROW|wxALL|wxGROW|wxTAB_TRAVERSAL, 0);

    m_sizer->Add(static_sizer, 0, wxALIGN_LEFT|wxALIGN_TOP|wxGROW|wxTAB_TRAVERSAL, 5);
    m_sizer->Layout();
    m_panel->FitInside();
    wxSRComponent* concept_name_comp= NULL;
    std::vector<wxSRComponent*> concept_name_comp_child;

    if (IsComponentWithContentSequence(code_value))
      concept_name_comp = BuildComponent(concept_name, sizer);

    for (unsigned int i = 0; i < content_sequence_items.size(); i++) {
      wxSRComponent* aux = BuildComponents(content_sequence_items.at(i), sizer,
          builder_code_value, concept_name_comp);
      if (aux)
        concept_name_comp_child.push_back(aux);
    }

    if (IsComponentWithChildren(code_value) && concept_name_comp)
      concept_name_comp->AddComponents(concept_name_comp_child);

  }

}

void SRFormBuilder::BuildContentSequence(SRXmlReader* content_sequence, wxSizer* sizer, wxSRComponent* father) {
  std::vector<SRXmlReader*> content_sequence_items = GetSRReaders(
      content_sequence->GetChildrenReaders(),
      SRXmlStrings::m_content_sequence_item);

  std::string code_value = SRXmlStrings::m_empty;
  std::vector<wxSRComponent*> children;

  for (unsigned int i = 0; i < content_sequence_items.size(); i++)
    children.push_back(BuildComponents(content_sequence_items.at(i), sizer,
        code_value));

  if (father)
    father->AddComponents(children);
}

void SRFormBuilder::BuildSRDocumentIOM(std::vector<SRXmlReader*> sr_iod_children) {
  SRXmlReader* doc_iom =GetSRReader(sr_iod_children, SRXmlStrings::m_srdoc_iom);
  std::vector<SRXmlReader*> doc_iom_children;

  if (doc_iom) {
    doc_iom_children = doc_iom->GetChildrenReaders();
    SRXmlReader* concept_name = GetSRReader(doc_iom_children,
        SRXmlStrings::m_concept_name_code_sequence);

    if (concept_name) {
      Tag concept_tag = concept_name->GetCurrentTag();
      std::vector<SRXmlReader*> concepts;

      m_sizer = new wxBoxSizer(wxVERTICAL);
      
      m_frame 
          = new wxFrame( NULL, wxID_ANY, StringHandler::std2wx(GetTitle(concept_tag)), wxDefaultPosition, wxSize(350, 600),
              wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxCLOSE_BOX|wxVSCROLL|wxTAB_TRAVERSAL|wxCLIP_CHILDREN);

      m_panel = new wxScrolledWindow(m_frame, wxID_ANY, wxDefaultPosition, wxSize(350, 600), wxNO_BORDER|wxVSCROLL|wxCLIP_CHILDREN );
      m_panel->SetScrollbars(20, 20, 50, 50);

      concepts = GetSRReaders(doc_iom_children,
          SRXmlStrings::m_content_sequence_item);

      for (unsigned int i = 0; i < concepts.size(); i++) 
        BuildContentSequenceItem(concepts.at(i));

      m_panel->SetSizer(m_sizer);
      m_panel->FitInside();

      m_frame->Show(true);
    }

  }

}
