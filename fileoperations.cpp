#include "fileoperations.h"

FileOperations::FileOperations()
{

}

FileOperations::FileOperations(QString filename)
{
    file = QSharedPointer< QFile >(new QFile(filename));
}

FileOperations::FileOperations(QSharedPointer< QFile > f): file(f)
{

}

FileOperations::~FileOperations()
{

}

bool FileOperations::OpenFile()
{

    return false;
}

bool FileOperations::SaveFile()
{
    if(!file->open(QIODevice::WriteOnly)) return false;

    QTextStream stream(file.data());

    //stream << editor->toPlainText();

    return true;
}

bool FileOperations::SaveFileAs()
{

    return false;
}
