#include "fscdocument.h"

FSCDocument::FSCDocument()
{

}

FSCDocument::FSCDocument(const QString &_path)
{
    path = _path;
}

void FSCDocument::AppendObject(FSCObject &object)
{
    objects.push_back(object);
}

void FSCDocument::SaveObjectsToFile()
{
    file = new QFile(path);

    if(!file->open(QIODevice::WriteOnly)) return;

    QTextStream out(file);

    for(auto &data : objects){
        out<<data.Data();
    }
    file->close();
}

QList<FSCObject>* FSCDocument::GetObjectsFromFile()
{
    QList< FSCObject > list;

    if(list.isEmpty()) return nullptr;

    return &list;
}

void FSCDocument::ReadFromFile()
{
    file = new QFile(path);

    if(!file->open(QIODevice::ReadOnly)) return;

    FSCObject *obj;

    QString line;
    QString value;
    QString type;
    int pipeIndex = 0;

    while(!file->atEnd()){
        line = file->readLine();
        obj = new FSCObject(line.left(line.indexOf('{')));

        while(true){
            line = file->readLine();
            if(line.contains('}', Qt::CaseSensitivity::CaseSensitive))break;

            pipeIndex = line.indexOf('|');
            value = line.mid(line.indexOf(':') + 1, pipeIndex - line.indexOf(':') - 1);
            type = line.mid(pipeIndex+1, line.indexOf('^'));
            //type = line.mid(firstpipe, line.indexOf('|', ))


            obj->CreateValue(line.left(line.indexOf(':')), value);
        }
        objects.push_back(*obj);
        obj->DisplayData();
        delete obj;
    }
}

















