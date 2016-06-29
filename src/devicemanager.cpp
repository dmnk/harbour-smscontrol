#include "devicemanager.h"
#include "devicemodel.h"
#include "controllabletype.h"
#include "typemanager.h"

#include "QtSql/QSqlRecord"
#include <QtSql/QSqlRecord>
#include "QtSql/QSqlField"
#include <QtSql/QSqlField>

#include <QDebug>

DeviceManager::DeviceManager(QObject *parent) :
    QObject(parent)
{
    DeviceModel model;
    model.initializeModel();
    TypeManager tm;

    QList<QObject *> types = tm.getTypes();
    QList<ControllableType *> thisTypes;

    foreach(QObject *o, types) {
        ControllableType *ct = dynamic_cast<ControllableType*>(o);
        thisTypes.append(ct);
    }

    //QList<Action *> actions = ActionManager::getActions();

    //qDebug() << "Devices found: "+model.rowCount();

    for (int i = 0; i < model.rowCount(); i++) {
        //QSqlRecord rec = model.record(i);
        //qDebug() << model.record(i).value("d_id");
        qlonglong pk = model.record(i).value("d_id").toLongLong();
        QString name = model.record(i).value("d_name").toString();
        QString producer = model.record(i).value("d_producer").toString();
        qlonglong fk_type = model.record(i).value("d_typeID").toLongLong();
        ControllableType *t;
        //qDebug() << pk + "__"+name+"__"+fk_type;
        foreach(ControllableType* conType, thisTypes ) {
            //qDebug() << conType->getName();
            if(conType->getID() == fk_type) {
                //qDebug() << "ID MATCH";
                t = conType;
                break;
            }
            //qDebug() << "No match" << conType->getID() << ".." <<fk_type;
        }

        ControllableDevice *cd = ControllableDevice::create(pk, name, producer, t, this);
        t->setParent(this);

        //Person *p = Person::create(QString(pk), fname, lname, this);// (pk, fname, lname);
        m_devices.append(cd);
        //m_persons.append(p);
        //personList.append(&p);
    }
}

QList<QObject *> DeviceManager::getDevices() const {
    QList<QObject *> devices;
    foreach (ControllableDevice *dev, m_devices) {
        devices.append(dev);
    }

    return devices;
}

ControllableDevice * DeviceManager::getDevice(qlonglong id) const {
//    qDebug() << "Searching: " << id;
    foreach(ControllableDevice *dev, m_devices) {
//        qDebug() << "Current: " << dev->getID() << " ::: " << dev->getName();

        if(dev->getID() == id) {
            return dev;
        }
    }
    return NULL;
}
