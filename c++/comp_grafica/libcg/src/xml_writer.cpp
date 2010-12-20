#include "xml_writer.h"
#include "cg_exception.h"
#include <iostream>

static const QString header("<?xml version=\"1.0\" ?>");

XmlWriter::XmlWriter(const QString& fileName) : file(fileName), contentStream(&content)
{
    if (!this->file.open(QIODevice::WriteOnly)) {
        throw new CGException(QString("Error opening file: ") + fileName + QString(" for writing !"));
    }

    this->contentStream << header;
    this->contentStream << "\n\n<formas>";
}

void XmlWriter::addObject(const QString& name, const XmlObject* obj)
{
    this->contentStream << "\n" << obj->getTab() << "<" << obj->getTagName() << " nome=\"" << name << "\"" << obj->toXML();
}

void XmlWriter::addObject(const XmlObject* obj)
{
    this->contentStream << obj->toXML();
}

void XmlWriter::save()
{
    if (!this->file.isOpen()) {
        throw new CGException(QString("Trying to save a xml file multiple times !!"));
    }
    this->contentStream << "</formas>";
    this->file.write(this->content.toLatin1());
    this->file.close();
}
