#ifndef XML_OBJECT_H
#define XML_OBJECT_H

#include "cg_global.h"
#include <QDomDocument>

/**
 *  Class that defines a xml object abstraction.
 */
class CGSHARED_EXPORT XmlObject
{
public:
    /**
     *  \brief Class constructor.
     *  Default constructor of the xmlobject abstraction.
     */
    XmlObject();

    /**
     *  Gets the string that represents the entire xml representation.
     *  @return A string, eg: <xmlObject name=hi>.
     */
    virtual QString toXML() const = 0;

    /**
     *  Returns the tag name of this element. For an XML element like this:
     *  <img src="myimg.png">
     *  the tagname would return "img".
     *  @return The tag name.
     */
    virtual QString getTagName() const = 0;

    /**
     *  Get tha tabulation to use when building the document.
     *  The tabulation.
     */
    const QString& getTab() const;
};
#endif // XML_OBJECT_H
