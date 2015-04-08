#include "SenderBase.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtCore/QProcess>
#include <QtCore/qmetaobject.h>


SenderBase::SenderBase()
{
}


SenderBase::~SenderBase(void)
{
}

 QDataStream &operator<<(QDataStream &ds, const SenderBase &obj) {
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i) {
        if(obj.metaObject()->property(i).isStored(&obj)) {
            ds << obj.metaObject()->property(i).read(&obj);
        }
    }
    return ds;
}

 QDataStream &operator>>(QDataStream &ds, SenderBase &obj) {
    QVariant var;
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i) {
        if(obj.metaObject()->property(i).isStored(&obj)) {
            ds >> var;
            obj.metaObject()->property(i).write(&obj, var);
        }
    }
    return ds;
}
