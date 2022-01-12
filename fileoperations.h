#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <QObject>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QFile>
#include <QSharedPointer>

#include <memory>

class FileOperations
{

    QSharedPointer< QFile > file;


public:
    FileOperations();
    FileOperations(QString filename);
    FileOperations(QSharedPointer< QFile > f);
    ~FileOperations();

public:

    bool OpenFile();
    bool SaveFile();
    bool SaveFileAs();


private:



};

#endif // FILEOPERATIONS_H
