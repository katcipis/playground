#include "xml_object.h"

static QString tab("    ");

XmlObject::XmlObject()
{
}

const QString& XmlObject::getTab() const
{
    return tab;
}
