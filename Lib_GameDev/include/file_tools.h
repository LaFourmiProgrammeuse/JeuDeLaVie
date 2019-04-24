#ifndef FILE_TOOLS_H
#define FILE_TOOLS_H

#include <QDebug>
#include <QFile>
#include <QTextStream>

#include "lib_gamedev_global.h"

class LIB_GAMEDEVSHARED_EXPORT File_Tools
{
public:
    File_Tools();
    File_Tools(QString path_file);
    ~File_Tools();

    QString getValueFromAttribute(QString attribute);
    void setValueFromAttribute(QString attribute_to_found, QString value_to_set);

    void setFile(QString path_file);

private:
    QFile *file;

};

#endif // FILE_TOOLS_H
