#ifndef FSCDOCUMENT_H
#define FSCDOCUMENT_H

#include <QFile>
#include <QTextStream>
#include <QList>
#include <QVariant>
#include <algorithm>

#include "fscobject.h"

class FSCDocument
{


public:
    FSCDocument();
    FSCDocument(const QString &path );

    void AppendObject(FSCObject &object);
    void SaveObjectsToFile();
    QList< FSCObject > *GetObjectsFromFile();
    void ReadFromFile();
    FSCObject *GetObjectByName(const QString &_name);
    void RemoveObjectByName(const QString &_name);
    int CountObjects(){ return objects.count(); }


private:

    QString path = "unnamed.txt";

    QFile *file = nullptr;

    QString documentName;

    QList< FSCObject > objects;


};

#endif // FSCDOCUMENT_H
