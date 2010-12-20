#ifndef TAG_HPP 
#define TAG_HPP
/**
 * \class Tag
 */

#include<map>
#include<string>

struct Tag {

public:

	/**
	 * \brief The text of the tag
	 * ex: <tag id="1">"hi"</tag>
	 * text will be "hi"
	 */
	std::string text;

	/**
	 * \brief The name of the tag
	 * ex: <tag id="1">
	 * name will be "tag"
	 */
	std::string name;

	/**
	 * \brief map between the attribute name and the attribute value
	 * ex: <tag id="1">
	 * the key is "id" 
	 * the value mapped by "id"
	 * will be "1"
	 */
	std::map<std::string, std::string> properties;

	Tag(std::string name) {
		this->name = name;
		this->text = "";
	}
	;

	Tag() {
		this->name = "no_name_specified";
		this->text = "";
	}
	;

	/**
	 * \brief Two tags are equal when they have the sema name, the
	 * same text and the same properties.
	 */
	bool operator==(const Tag& other) const {
		bool same_text = (this->text == other.text);
		bool same_name = (this->name == other.name);
		bool same_properties = (this->properties == other.properties);
		return (same_text && same_name && same_properties);

	}
	;

};
#endif // !defined(TAG_HPP)
