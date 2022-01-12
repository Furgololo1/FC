#include "fscobject.h"


FSCObject::FSCObject()
{

}


FSCObject::FSCObject(const QString &_objectName)
{
    objectName = _objectName;
}


void FSCObject::CreateValue(const QString &key, int val)
{
    intvalues.emplace_back(QPair< QString, int >(key, val));
}


void FSCObject::CreateValue(const QString &key, double val)
{
    doublevalues.emplace_back(QPair< QString, double >(key, val));
}


void FSCObject::CreateValue(const QString &key, QString val)
{
    stringvalues.emplace_back(QPair< QString, QString >(key, val));
}


void FSCObject::CreateValue(const QString &key, bool val)
{
    boolvalues.emplace_back(QPair< QString, bool >( key, val));
}


QString FSCObject::Data()
{
    QString data(objectName + "{\n");


    for(const auto &iv : intvalues)
        data.append(iv.first + ":" + QString::number(iv.second) + ";\n");
    for(const auto &dv : doublevalues)
        data.append(dv.first + ":" + QString::number(dv.second) + ";\n");
    for(const auto &sv : stringvalues)
        data.append(sv.first + ":" + sv.second + ";\n");
    for(const auto &bv : boolvalues)
        data.append(bv.first + ":" + (bv.second == true ? "1" : "0") + ";\n");

    data.append("}\n");

    return data;
}


QVariant FSCObject::GetValue(const QString &key)
{
    for(const auto &iv : intvalues)
        if(iv.first.contains(key, Qt::CaseSensitivity::CaseSensitive)) return iv.second;
    for(const auto &dv : doublevalues)
        if(dv.first.contains(key, Qt::CaseSensitivity::CaseSensitive)) return dv.second;
    for(const auto &sv : stringvalues)
        if(sv.first.contains(key, Qt::CaseSensitivity::CaseSensitive)) return sv.second;
    for(const auto &bv : boolvalues)
        if(bv.first.contains(key, Qt::CaseSensitivity::CaseSensitive)) return bv.second;

    return QVariant("bad key");
}

void FSCObject::DisplayData()
{
    qDebug()<<"Object name: "<<objectName;

    for(const auto &iv : intvalues)
        qDebug()<<"key: "<<iv.first<<" value: "<<iv.second;
    for(const auto &dv : doublevalues)
        qDebug()<<"key: "<<dv.first<<" value: "<<dv.second;
    for(const auto &sv : stringvalues)
        qDebug()<<"key: "<<sv.first<<" value: "<<sv.second;
    for(const auto &bv : boolvalues)
        qDebug()<<"key: "<<bv.first<<" value: "<<bv.second;
}







