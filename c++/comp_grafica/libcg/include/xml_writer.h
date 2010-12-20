#ifndef XML_WRITER_H
#define XML_WRITER_H

#include <QString>
#include <QMap>
#include <QDomDocument>
#include <QFile>
#include <QString>
#include <QTextStream>
#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "curve_bspline.h"
#include "curve_hermite.h"
#include "window.h"

/**
 *  Class that defines the xml writer.
 */
class CGSHARED_EXPORT XmlWriter
{
private:
    QFile file;
    QString content;
    QTextStream contentStream;

public:
    /**
     *  \brief Class constructor.
     *  @param fileName - The path to the xml file that will be write.
     */
    XmlWriter(const QString& fileName);

    /**
     *  Add a object to the xml document.
     *  @param name - The name of the object (will be the attribute nome).
     *  @param obj  - The xml object.
     */
    void addObject(const QString& name, const XmlObject* obj);

    /**
     *  Add a object to the xml document.
     *  @param obj  - The xml object.
     */
    void addObject(const XmlObject* obj);

    /**
     *  Save all data to the file, MUST be called ONCE, ONLY once.
     */
    void save();
};

#endif // XML_WRITER_H
