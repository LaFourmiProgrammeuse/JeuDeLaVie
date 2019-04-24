#ifndef XML_TOOLS_H
#define XML_TOOLS_H

#include <QDebug>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

#include "lib_gamedev_global.h"

class LIB_GAMEDEVSHARED_EXPORT Xml_Tools
{
public:
    Xml_Tools();
    Xml_Tools(QString path_file);

    void setFile(QString path_file);

    QString getValueFromXmlFile(QString attribute);
    bool setValueFromXmlFile(QString attribute, QString value);

private:
    QFile *xml_file;

    QDomDocument xml_document;
    QDomElement document_element;

};

#endif // XML_TOOLS_H
