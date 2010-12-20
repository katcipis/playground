#include "./XmlWriter.hpp"
#include <iostream>

void XmlWriter::UpdateTag(TiXmlDocument& doc, std::queue<Tag> tag_path,
		Tag father_to_update, std::list<Tag> children_to_update) {

	if (tag_path.empty()) {

		this->UpdateRootTag(doc, father_to_update, children_to_update);

	} else {

		TiXmlElement * root_elem = this->m_xml_searcher.FindElement(doc,
				tag_path.front());

		if (root_elem == NULL) {
			root_elem = this->FromTagToElement(tag_path.front());
			doc.LinkEndChild(root_elem);
		}

		tag_path.pop();

		TiXmlElement* end_of_path = this->WritePath(root_elem, tag_path);
		this->RemoveChildTag(end_of_path, father_to_update);

		TiXmlElement* father_elem = this->FromTagToElement(father_to_update);

		std::list<Tag>::iterator iter;
		for (iter = children_to_update.begin(); iter != children_to_update.end(); iter++) {

			Tag temp = *iter;

			TiXmlNode& node = *this->FromTagToElement(temp);
			TiXmlText* text = new TiXmlText(temp.text.c_str());
			TiXmlNode& node_text = *text;

			node.InsertEndChild(node_text);

			father_elem->InsertEndChild(node);
		}

		end_of_path->InsertEndChild(*father_elem);
		doc.SaveFile();
		doc.LoadFile();
	}
}

void XmlWriter::RemoveChildTag(TiXmlElement* father, Tag child_to_remove) {

	TiXmlElement* child;

	for (child = father->FirstChildElement(); child; child
			= child->NextSiblingElement())
		if (this->ElementIsEqualTheTag(child, child_to_remove))
			father->RemoveChild(child);

}

void XmlWriter::UpdateRootTag(TiXmlDocument& doc, Tag father_to_update,
		std::list<Tag> children_to_update) {

	TiXmlElement * root_elem = this->m_xml_searcher.FindElement(doc,
			father_to_update);

	if (root_elem == NULL) {
		root_elem = this->FromTagToElement(father_to_update);
		doc.LinkEndChild(root_elem);
	}

	std::list<Tag>::iterator iter;
	for (iter = children_to_update.begin(); iter != children_to_update.end(); iter++) {

		Tag temp = *iter;
		this->RemoveChildTag(root_elem, temp);

		TiXmlNode& node = *this->FromTagToElement(temp);
		TiXmlText* text = new TiXmlText(temp.text.c_str());
		TiXmlNode& node_text = *text;

		node.InsertEndChild(node_text);

		root_elem->InsertEndChild(node);
	}

	doc.SaveFile();
	doc.LoadFile();
}

TiXmlElement* XmlWriter::WritePath(TiXmlElement* elem, std::queue<Tag> tag_path) {

	if (tag_path.empty() || elem == NULL)
		return elem;

	TiXmlElement* child;

	if (this->HasChild(elem, tag_path.front())) {

		child = this->GetChild(elem, tag_path.front());

	} else {

		child = this->FromTagToElement(tag_path.front());
		elem->LinkEndChild(child);

	}

	tag_path.pop();

	return this->WritePath(child, tag_path);
}

