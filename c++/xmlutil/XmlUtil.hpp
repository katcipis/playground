#ifndef XMLUTIL_HPP_
#define XMLUTIL_HPP_

#include "tinyxml/tinyxml.h"
#include "Tag.h"
#include <queue>
#include <list>

/**
 * \class XmlUtil, this class holds abstract data to help
 * the building of XmlIo classes 
 */

class XmlUtil {

public:
	XmlUtil() {
	}
	;

	virtual ~XmlUtil() {
	}
	;

protected:
	/*
	 * returns true if the element has the same name of the tag
	 * and has the same attributes and attributes values
	 */
	bool ElementIsEqualTheTag(TiXmlElement* element, Tag t);

	/*returns true if the given element
	 * has all the atributes  of the given properties
	 * despites the attributes values
	 */
	bool HasAttributes(const TiXmlElement* element,
			const std::map<std::string,std::string> properties);

	/*returns true if the given element
	 * has all the same attributes and the atributes 
	 * has the same values given on the properties 
	 */
	bool HasSameAttributesValues(const TiXmlElement* element,
			const std::map<std::string,std::string> properties);

	/* returns all the children of the given element
	 * if has no one returns a empty queue
	 */
	std::queue<TiXmlElement*> GetElementChildren(TiXmlElement* element);

	/* returns all the siblings of the given element 
	 * that have the same Value of the element
	 */
	std::list<TiXmlElement*> GetSiblingsWithSameValue(TiXmlElement* element);

	/**
	 * \brief returns the child element if the father elem has
	 *  a elem child with the same information holded by the child tag.
	 */
	TiXmlElement* GetChild(TiXmlElement* father, Tag child_tag);

	/**
	 * \brief gets all the information inside the tag and
	 * converts to a valid equivalent TiXmlElement* object
	 */
	TiXmlElement* FromTagToElement(Tag tag_to_be_converted);

	/**
	 * \brief gets all the information inside the TiXmlElement and
	 * converts to a valid equivalent Tag object
	 */
	Tag FromElementToTag(TiXmlElement* elem_to_be_converted);

	/**
	 * \brief returns true if the father elem has a elem child with the same
	 * information holded by the child tag.
	 */
	bool HasChild(TiXmlElement* father, Tag child);

};
#endif /*XMLUTIL_HPP_*/
