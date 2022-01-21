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

    if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    QTextStream out(file);

    for(auto &data : objects){
        out<<data.Data();
    }
    file->close();
}

QList<FSCObject>* FSCDocument::GetObjectsFromFile()
{
    if(objects.isEmpty()) return nullptr;

    return &objects;
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
            type = line.mid(pipeIndex+1, line.indexOf('^')-2 - pipeIndex+1);

            if(type == "int")
                obj->CreateValue(line.left(line.indexOf(':')), value.toInt());
            else if(type == "double")
                obj->CreateValue(line.left(line.indexOf(':')), value.toDouble());
            else if(type == "bool")
                obj->CreateValue(line.left(line.indexOf(':')), value == "1" ? true : false);
            else
                obj->CreateValue(line.left(line.indexOf(':')), value);


        }
        objects.push_back(*obj);
//        obj->DisplayData();
//        delete obj;
    }
}

FSCObject *FSCDocument::GetObjectByName(const QString &_name)
{
    for(auto &obj : objects)
        if(obj.GetObjectName() == _name)
            return &obj;

    return nullptr;
}

















