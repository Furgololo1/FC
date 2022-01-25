#ifndef FSCOBJECT_H
#define FSCOBJECT_H

#include <QString>
#include <QVariant>
#include <QVector>
#include <QPair>

class FSCObject
{
public:
    FSCObject();
    FSCObject(const QString &_objectName);

    void CreateValue(const QString &key, int val);
    void CreateValue(const QString &key, double val);
    void CreateValue(const QString &key, QString val);
    void CreateValue(const QString &key, bool val);

    void ChangeValue(const QString &key, int val);
    void ChangeValue(const QString &key, double val);
    void ChangeValue(const QString &key, QString val);
    void ChangeValue(const QString &key, bool val);

    QString GetObjectName(){return objectName;}
    QString *Data();
    QVariant GetValue(const QString &key);
    void SetObjectName(const QString &_objectName){    objectName = _objectName;    }
    void DisplayData();

    bool operator ==(const FSCObject& obj) const{
        return objectName == obj.objectName;
    }

    friend QDebug operator <<(QDebug dbg, const FSCObject &obj) {
        return dbg << obj.objectName;
    }


private:
     QString objectName;

     QVector< QPair< QString, int> > intvalues;
     QVector< QPair< QString, double> > doublevalues;
     QVector< QPair< QString, QString> > stringvalues;
     QVector< QPair< QString, bool> > boolvalues;


};

#endif // FSCOBJECT_H
