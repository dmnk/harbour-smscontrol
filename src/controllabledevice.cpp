#include "controllabledevice.h"

ControllableDevice::ControllableDevice(QObject *parent) :
    QObject(parent)
{
}

ControllableDevice * ControllableDevice::create(const qlonglong &id, const QString &name, const QString &producer, ControllableType *type, QObject *parent) {
    ControllableDevice *cd = new ControllableDevice(parent);
    cd->m_id = id;
    cd->m_name = name;
    cd->m_type = type;
    cd->m_producer = producer;
    //cd->m_type->setParent(parent);
    return cd;
}

ControllableType* ControllableDevice::getType()    {
    return m_type;
}

qlonglong ControllableDevice::getID() {
    return m_id;
}
QString ControllableDevice::getName() const {
    return m_name;
}

QString ControllableDevice::getProducer() const {
    return m_producer;
}

QString ControllableDevice::getTypeName() const {
    return m_type->getName();
    //return this->m_type->getName();// ->getName();// m_type->getName();
    /*if(m_type != NULL) {
        return m_type->getName();
    } else {*/
        //return QString("");
    //}

}
