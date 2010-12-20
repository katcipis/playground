#include "XmlUtil.hpp"

bool XmlUtil::ElementIsEqualTheTag(TiXmlElement* element, Tag t) {

	if (strcmp(element->Value(), t.name.c_str()) != 0)
		return false;

	return this->HasSameAttributesValues(element, t.properties);
}

bool XmlUtil::HasAttributes(const TiXmlElement* element,
		const std::map<std::string,std::string> properties) {

	if (element == NULL)
		return false;

	if (properties.empty())
		return true;

	std::map<std::string, std::string>::const_iterator iter = properties.begin();

	while (iter != properties.end()) {
		if (element->Attribute(iter->first.c_str()) == NULL)
			return false;
		iter++;
	}

	return true;
}

bool XmlUtil::HasSameAttributesValues(const TiXmlElement* element,
		const std::map<std::string,std::string> properties) {

	if (element == NULL)
		return false;

	if (properties.empty())
		return true;

	if (!this->HasAttributes(element, properties))
		return false;

	std::map<std::string, std::string>::const_iterator iter;

	for (iter = properties.begin(); iter != properties.end(); iter++) {

		if (strcmp(element->Attribute(iter->first.c_str()) , iter->second.c_str())
				!= 0)
			return false;

	}

	return true;
}

std::queue<TiXmlElement*> XmlUtil::GetElementChildren(TiXmlElement* element) {
	TiXmlNode* firstChild;
	std::queue<TiXmlElement*> elements;

	for (firstChild = element->FirstChild(); firstChild; firstChild
			= firstChild->NextSibling()) {
		TiXmlElement* temp = firstChild->ToElement();
		if (temp != NULL)
			elements.push(temp);
	}

	return elements;
}

std::list<TiXmlElement*> XmlUtil::GetSiblingsWithSameValue(TiXmlElement* element) {
	std::list<TiXmlElement*> listOfSiblings;

	for (TiXmlNode* sibling = element->NextSibling() ; sibling; sibling
			= sibling->NextSibling() ) {

		TiXmlElement* sibling_element = sibling->ToElement();

		if (sibling_element != NULL) {
			if (strcmp(sibling_element->Value(), element->Value()) == 0)
				listOfSiblings.push_back(sibling_element);
		}
	}
	return listOfSiblings;
}

TiXmlElement* XmlUtil::GetChild(TiXmlElement* father, Tag child_tag) {

	if (father == NULL)
		return father;

	TiXmlNode* node_child;

	for (node_child = father->FirstChild(); node_child; node_child
			= node_child->NextSibling())
		if (node_child->ToElement() != NULL)
			if (this->ElementIsEqualTheTag(node_child->ToElement(), child_tag))
				return node_child->ToElement();

	return NULL;
}

TiXmlElement* XmlUtil::FromTagToElement(Tag tag_to_be_converted) {

	TiXmlElement* converted_elem = new TiXmlElement(tag_to_be_converted.name.c_str());

	std::map<std::string, std::string>::iterator iter;

	for (iter = tag_to_be_converted.properties.begin(); iter
			!= tag_to_be_converted.properties.end(); iter++)
		converted_elem->SetAttribute((*iter).first.c_str(), (*iter).second.c_str());

	return converted_elem;

}

Tag FromElementToTag(TiXmlElement* elem_to_be_converted) {
	Tag converted_tag;

	if (elem_to_be_converted) {

		converted_tag.name = elem_to_be_converted->Value();
		const char* text = elem_to_be_converted->GetText();

		if (text)
			converted_tag.text = text;

		const TiXmlAttribute * first_attribute =
				elem_to_be_converted->FirstAttribute();

		while (first_attribute) {
			if (first_attribute->Name() && first_attribute->Value())
				converted_tag.properties[first_attribute->Name()] = first_attribute->Value();

			first_attribute = first_attribute->Next();
		}

	}

	return converted_tag;
}

bool XmlUtil::HasChild(TiXmlElement* father, Tag child) {
	if (father == NULL)
		return false;

	if (father->NoChildren())
		return false;

	TiXmlNode* node_child;

	for (node_child = father->FirstChild(); node_child; node_child
			= node_child->NextSibling())
		if (node_child->ToElement() != NULL)
			if (this->ElementIsEqualTheTag(node_child->ToElement(), child))
				return true;

	return false;

}
