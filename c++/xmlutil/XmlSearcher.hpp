#ifndef TINYXMLNODESEARCHER_
#define TINYXMLNODESEARCHER_

#include <string>
#include <map>
#include <vector>
#include "XmlUtil.hpp"

class XmlSearcher : public virtual XmlUtil {

public:

	XmlSearcher();

	virtual ~XmlSearcher() {
	}
	;

	/* 
	 * returns a TiXmlNode*
	 * if founds a node with a value that
	 * matches with the given string value, 
	 * if not, returns null
	 */
	TiXmlNode* FindNode(TiXmlDocument &doc, const std::string value_str);

	/* 
	 * returns a TiXmlElement*
	 * if founds a node with a value that
	 * matches with the given string value and
	 * this node is a Element, 
	 * if not, returns null
	 */
	TiXmlElement* FindElement(TiXmlDocument &doc, const std::string value_str);

	/* 
	 * returns a TiXmlText*
	 * if founds a node with a value that
	 * matches with the given string value and
	 * this node is a Text, 
	 * if not, returns null
	 */
	TiXmlText* FindText(TiXmlDocument &doc, const std::string value_str);

	/* 
	 * returns a TiXmlElement*
	 * if founds a element with the 
	 * same name given in the struct tag 
	 * and with the same properties.
	 * All the values of the properties must match
	 * if not, returns null
	 */
	TiXmlElement* FindElement(TiXmlDocument &doc, const Tag t);

	/* 
	 * returns a vector of TiXmlElement*
	 with all the elements that have
	 the same name and the same attributes
	 passed and are on the same depth of the first
	 found element, deeper elements will not be considered.
	 it will not consider the values of each
	 attribute, only if has the attribute.
	 if gives only the name of the tag will
	 return all the tags that have that name
	 and ignore possible attributes
	 */
	std::vector<TiXmlElement* > FindElements(TiXmlDocument &doc, const Tag t);

	/* 
	 * returns a vector of Tags
	 with all the Tags that have
	 the same name and the same attributes
	 passed, all the file will be searched.
	 it will not consider the values of each
	 attribute, only if has the attribute.
	 if only the name of the tag name is given will
	 return all the tags that have that name
	 and ignore possible attributes
	 */
	std::vector<Tag> DeepFindElements(TiXmlDocument &doc, const Tag t);

	/*Given a queue of tags that represents
	 * the path in the xml tree to find the desired
	 * tag will return a TiXmlElement if the path
	 * is valid. Queue is a FIFO the root tag is placed 
	 * first. The tag you want will be the last one in
	 * the Queue
	 */

	TiXmlElement* FindElementInDepth(TiXmlDocument &doc, std::queue<Tag> tags);

	/*
	 * Given a queue of tags that represents
	 * the path in the xml tree to find the desired
	 * tag will return a list of TiXmlElement if the path
	 * is valid. The root tag is placed 
	 * first. The tag you want will be the last one in
	 * the Queue.
	 * To get all tags with a name the desired tag must
	 * be passed as the last one in the queue, the content of properties
	 * will be ignored on the last one, all the the tags with the same
	 * name will be returned, in the case of the last tag
	 * of the path (the target tag).If one of the tags along the path has
	 * properties the attributes and the values of the attributes
	 * of the properties will be considered. If the queue is empty
	 * will return an empty list.
	 */

	std::list<TiXmlElement*> FilterElementsInDepth(TiXmlDocument &doc,
			std::queue<Tag> tags);

private:

	TiXmlElement* FindElementInDepth(TiXmlElement* element, std::queue<Tag> tags);

	std::list<TiXmlElement*> FilterElementsInDepth(TiXmlElement* element,
			std::queue<Tag> tags);

};

#endif /*TINYXMLNODESEARCHER_*/
