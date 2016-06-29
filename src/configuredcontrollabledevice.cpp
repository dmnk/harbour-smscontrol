#include "configuredcontrollabledevice.h"
#include "action.h"
#include "actionmanager.h"
#include "QDebug"

ConfiguredControllableDevice::ConfiguredControllableDevice(QObject *parent) :
    ControllableDevice(parent)
{
}

ConfiguredControllableDevice * ConfiguredControllableDevice::create(const qlonglong &systemID, const QString &systemName, const QString &producerName, const QString &description, ControllableType *type, const QString &phonenumber, const QString &password, QObject *parent) {
    ConfiguredControllableDevice *ccd = new ConfiguredControllableDevice(parent);
    ccd->m_id = systemID;
    ccd->m_name = systemName;
    ccd->m_producer = producerName;
    ccd->m_type = type;
    ccd->m_type->setParent(ccd);

    ccd->m_description = description;
    ccd->m_password = password;
    ccd->m_phonenumber = phonenumber;

    ActionManager am;
    QList<Action *> acts = am.getActions(systemID);

    foreach (Action* a, acts) {
        a->setParent(ccd);
        ccd->m_actions.append(a);
    }

//    qDebug() << "Actions:  " << ccd->m_actions.size();
    return ccd;
}

QString ConfiguredControllableDevice::getPhonenumber() const{
    return m_phonenumber;
}

QString ConfiguredControllableDevice::getPassword() const {
    return m_password;
}

QString ConfiguredControllableDevice::getDescription() const {
    return m_description;
}


QList<QObject *> ConfiguredControllableDevice::getActions() const {
    QList<QObject *> actions;
    foreach (Action *a, m_actions) {
        actions.append(a);
    }

    return actions;
}
