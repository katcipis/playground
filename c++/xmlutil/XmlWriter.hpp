#ifndef XMLWRITER_HPP_
#define XMLWRITER_HPP_

#include "XmlSearcher.hpp"
#include "XmlUtil.hpp"

class XmlWriter : public virtual XmlUtil{

public:
	
	XmlWriter(){};
	
	virtual ~XmlWriter(){};
	
  /**
	 * \brief If the father tag exist, it is updated. Otherwise, it is created 
	 * and writed. The path is given by a queue that must start by the root node
	 * and goes on to where the father tag must be. If the file is blank
	 * it will write the entire path on the file before writing the father tag.
	 * Any tag in the path that is not found will be created and writed on the file.If 
	 * the given path is empty it is considered that you are updating the root node. 
	 * If the children to update is empty will write the father empty on the file 
	 * (removing any children), all the children on the file are erased and replaced by
	 * the children on the children to update list.
	 */
	void UpdateTag(TiXmlDocument& doc, std::queue<Tag> tag_path,
			Tag father_to_update, std::list<Tag> children_to_update);

private:

	XmlSearcher m_xml_searcher;

	/**
	 * \brief removes the father child element with same values of the child tag
	 */
	void RemoveChildTag(TiXmlElement* father, Tag child_to_remove);

	

	void UpdateRootTag(TiXmlDocument& doc, Tag father_to_update,
			std::list<Tag> children_to_update);

	/**
	 * \brief recursive method to verify if the path is valid and write it
	 * if the elem does not have the next tag in the path
	 */
	TiXmlElement* WritePath(TiXmlElement* elem, std::queue<Tag> tag_path);

	

};

#endif /*XMLWRITER_HPP_*/
