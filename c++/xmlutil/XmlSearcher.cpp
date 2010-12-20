#include "XmlSearcher.hpp"
#include <stack>
#include <string.h>
#include <map>
#include <iostream>    
 
XmlSearcher::XmlSearcher() {
}

TiXmlNode* XmlSearcher::FindNode(TiXmlDocument &doc,
		const std::string value_str) {

	if (doc.Error())
		return NULL;

	std::stack<TiXmlNode*> node_stack;
	node_stack.push(doc.RootElement());

	if (doc.RootElement()->NextSibling() != NULL) {
		TiXmlNode* sibling = NULL;
		for (sibling = doc.RootElement()->NextSibling(); sibling; sibling = sibling->NextSibling()) {
			node_stack.push(sibling);
		}
	}

	while (!node_stack.empty()) {

		TiXmlNode* node = node_stack.top();
		node_stack.pop();

		if (strcmp(node->Value(), value_str.c_str() ) == 0) {
			return node;
		}

		if (!node->NoChildren()) {
			TiXmlNode* child;
			for (child = node->LastChild(); child; child = child->PreviousSibling()) {
				node_stack.push(child);
			}
		}
	}

	return NULL;
}

TiXmlElement* XmlSearcher::FindElement(TiXmlDocument &doc,
		const std::string value_str) {

	TiXmlNode* node = FindNode(doc, value_str);

	if (node == NULL)
		return NULL;

	return node->ToElement();

}

TiXmlText* XmlSearcher::FindText(TiXmlDocument &doc,
		const std::string value_str) {

	TiXmlNode* node = FindNode(doc, value_str);

	if (node == NULL)
		return NULL;
	
	return node->ToText();

}

TiXmlElement* XmlSearcher::FindElement(TiXmlDocument &doc, const Tag t) {

	TiXmlElement* element = FindElement(doc, t.name);
	std::map<std::string,std::string> properties = t.properties;

	if (element == NULL)
		return NULL;

	if (this->HasSameAttributesValues(element, properties))
		return element;

	if (element->NextSiblingElement() == NULL)
		return NULL;

	TiXmlNode* sibling = NULL;
	for (sibling = element->NextSibling(); sibling; sibling
			= sibling->NextSibling()) {

		TiXmlElement* sibling_element = sibling->ToElement();

		if (sibling_element != NULL) {
			if (this->HasSameAttributesValues(sibling_element, properties))
				return sibling_element;
		}

	}

	return NULL;
}

std::vector<TiXmlElement* > XmlSearcher::FindElements(TiXmlDocument &doc,
		const Tag t) {

	TiXmlElement* element;
	element = FindElement(doc, t.name);
	std::vector<TiXmlElement* > elements;

	if (element == NULL)
		return elements;

	if (this->HasAttributes(element, t.properties) && strcmp(element->Value(),
			t.name.c_str()) == 0)
		elements.push_back(element);

	if (element->NextSibling() == NULL)
		return elements;

	TiXmlNode* sibling = NULL;
	for (sibling = element->NextSibling(); sibling; sibling
			= sibling->NextSibling()) {

		TiXmlElement* sibling_element = sibling->ToElement();

		if (sibling_element != NULL) {
			if (this->HasAttributes(sibling_element, t.properties) && strcmp(
					sibling_element->Value(), t.name.c_str()) == 0)
				elements.push_back(sibling_element);
		}

	}

	return elements;
}


TiXmlElement* XmlSearcher::FindElementInDepth(TiXmlDocument &doc, std::queue<Tag> tags) {
	
	if(tags.empty())
		return NULL;
	
	TiXmlElement* element = this->FindElement(doc, tags.front());
	
	if(element == NULL)
		return NULL;
	
	tags.pop();
	
	return this->FindElementInDepth(element, tags);
}


//-----------------------------------------------------------------------//
// INTERNAL METHODS 
//-----------------------------------------------------------------------//
TiXmlElement* XmlSearcher::FindElementInDepth(TiXmlElement* element, std::queue<Tag> tags) {
  
  if(element == NULL)
    return NULL;
  
  if(tags.empty())
    return element;
  
  std::queue<TiXmlElement*> children = this->GetElementChildren(element);
  
  while(!children.empty()){
    
    TiXmlElement* temp = children.front();
    children.pop();
    
    if(this->ElementIsEqualTheTag(temp, tags.front())){
      tags.pop();
      return this->FindElementInDepth(temp, tags);
    }
      
  }
  
  return NULL;
}




std::list<TiXmlElement*> XmlSearcher::FilterElementsInDepth(TiXmlDocument &doc, 
std::queue<Tag> tags){
  std::list<TiXmlElement*> returnlist;
  
  if(tags.empty())
    return returnlist;
  
  TiXmlElement* father = this->FindElement(doc, tags.front());
  
  if( father != NULL){
    tags.pop();
    return this->FilterElementsInDepth(father, tags);      
  }
  
  return returnlist;
}

std::list<TiXmlElement*> XmlSearcher::FilterElementsInDepth(TiXmlElement* element, 
std::queue<Tag> tags) 
{    
  std::list<TiXmlElement*> listOfElements;

  if(element == NULL)
    return listOfElements;

  if( tags.empty()) {
    listOfElements = GetSiblingsWithSameValue(element);
    listOfElements.push_front(element);  
  
  } else {    
    Tag front = tags.front();
    std::queue<TiXmlElement*> children;
    children = this->GetElementChildren( element);
   
    while( !children.empty() ) {
      if( ElementIsEqualTheTag(children.front(), front)) {
        tags.pop();        
        return FilterElementsInDepth( children.front(), tags);
      }
      children.pop();
    }
  }
    
  return listOfElements;  
}

std::vector<Tag> XmlSearcher::DeepFindElements(TiXmlDocument &doc, const Tag t){
	return std::vector<Tag>();
}

