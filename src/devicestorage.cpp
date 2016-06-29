#include "devicestorage.h"
//all neeeded?

#include <QtCore/QCoreApplication>
#include <QtCore/QStandardPaths>
#include <QtCore/QDir>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QFile>
#include <QtCore/QDebug>
//#include <QLocale>

#include "configuredcontrollabledevice.h"
#include "devicemanager.h"
#include "controllabledevice.h"
// end all


static const char *SYSTEMID = "ID";
static const char *DESCRIPTION = "description";
static const char *PHONENUMBER = "phonenumber";
static const char *PASSWORD = "password";
//static const char *PROPERTIES = "properties";

DeviceStorage::DeviceStorage(QObject *parent) :
    QObject(parent)
{
    QFile file (configFilePath());
    //file.remove(); //clean old wrong-formatted config
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll());
    file.close();


    QJsonArray jsonArray = jsonDocument.array();

    DeviceManager *dm = new DeviceManager(this);

    foreach (QJsonValue value, jsonArray) {
        QJsonObject jsonSecsys = value.toObject();
        qlonglong id = jsonSecsys.value(SYSTEMID).toString().toLongLong();
        QString description = jsonSecsys.value(DESCRIPTION).toString();
        QString phone = jsonSecsys.value(PHONENUMBER).toString();
        QString pass = jsonSecsys.value(PASSWORD).toString();


//        qDebug() << "trying to load: " << description;
//        qDebug() << "id: " << id;
//        qDebug() << "phone: " << phone;
//        qDebug() << "pass: " << pass;

        //ConfiguredControllableDevice *ccdev = ConfiguredControllableDevice::create(id, description, new ControllableType(), phone, pass, this);
        //TODO: ConfiguredControllableDevice *ccdev = ConfiguredControllableDevice::create( ...);
        //ConfiguredControllableDevice *ccdev = new ConfiguredControllableDevice();

        ControllableDevice *dev = dm->getDevice(id);

        if(dev == NULL) { ; } else {
            //qWarning() << "Adding a device";
            ConfiguredControllableDevice *ccd = ConfiguredControllableDevice::create(id, dev->getName(), dev->getProducer(), description, dev->getType(), phone, pass, this);
            //ConfiguredControllableDevice *secsys = ConfiguredControllableDevice::create(identifier, name, type, phonenumber, password,  this);
            //ConfiguredControllableDevice *secsys = new ConfiguredControllableDevice();
            m_securitySystems.append(ccd);

//            qDebug() << "added " << dev->getName();

            //m_securitySystems.append(ccdev);
            m_securitySystemsMap.insert(ccd->getPhonenumber(), ccd);
        }
    }
}

QList<QObject *> DeviceStorage::getControllableDevices() const
{
    QList<QObject *> secSysObjects;
    foreach (ConfiguredControllableDevice *secsys, m_securitySystems) {
        secSysObjects.append(secsys);
    }

    return secSysObjects;
}

/*QVariantMap DeviceManager::properties(int identifier)
{
    return m_securitySystemsMap.value(identifier)->getProperties();
}*/

/*void DeviceStorage::addControllableDevice(const QString &identifier, const QString &name, const QString &phonenumber,
                          const QString &password, ControllableType *type)
{
    //qWarning() << "Adding a device";
    ConfiguredControllableDevice *ccd = ConfiguredControllableDevice::create(identifier.toLongLong(), name, type, phonenumber, password, this);
    //ConfiguredControllableDevice *secsys = ConfiguredControllableDevice::create(identifier, name, type, phonenumber, password,  this);
    //ConfiguredControllableDevice *secsys = new ConfiguredControllableDevice();
    m_securitySystems.append(ccd);
    m_securitySystemsMap.insert(identifier, ccd);
    emit controllableDevicesChanged();


    //qWarning() << "Added: " << identifier;
    save();
}*/


void DeviceStorage::addControllableDevice(const QString &identifier, const QString &description, const QString &phonenumber,
                          const QString &password)
{
    DeviceManager *dm = new DeviceManager(this);
    ControllableDevice *dev = dm->getDevice(identifier.toLongLong());

    if(dev == NULL) { ; } else {
        //qWarning() << "Adding a device";
        ConfiguredControllableDevice *ccd = ConfiguredControllableDevice::create(identifier.toLongLong(), dev->getName(), dev->getProducer(), description, dev->getType(), phonenumber, password, this);
        //ConfiguredControllableDevice *secsys = ConfiguredControllableDevice::create(identifier, name, type, phonenumber, password,  this);
        //ConfiguredControllableDevice *secsys = new ConfiguredControllableDevice();
        m_securitySystems.append(ccd);
        m_securitySystemsMap.insert(ccd->getPhonenumber(), ccd);
        emit controllableDevicesChanged();

//        qWarning() << "Loaded:  " << dev->getName();
        save();
    }
}

void DeviceStorage::removeControllableDevice(const QString &phonenumber)
{
    ConfiguredControllableDevice *secsys = m_securitySystemsMap.value(phonenumber);
    if (!secsys) {
        return;
    }

    m_securitySystemsMap.remove(phonenumber);
    m_securitySystems.removeAll(secsys);
    secsys->deleteLater();
    emit controllableDevicesChanged();

    save();
}

/*void CityManager::addProperties(const QString &identifier, const QVariantMap &properties)
//{
//    if (!m_citiesMap.contains(identifier)) {
//        return;
//    }

//    m_citiesMap.value(identifier)->setProperties(properties);
//    save();
//}*/

/*void CityManager::clearProperties(const QString &identifier)
//{
//    if (!m_citiesMap.contains(identifier)) {
//        return;
//    }

//    m_citiesMap.value(identifier)->setProperties(QVariantMap());
//    save();
//}*/

QString DeviceStorage::configFilePath()
{
    //QDir dir ("$XDG_CONFIG_HOME");
    QDir dir (QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
    //if (!dir.mkpath(QString("%1/%2").arg(qApp->organizationName(), qApp->applicationName()))) {
//    if (!dir.mkpath(QString("%1/%2").arg("dmnk.org", "SMS-Control"))) {
//        return QString();
//    }
    if(!dir.exists("harbour-smscontrol")) {
        dir.mkdir("harbour-smscontrol");
    }
    dir.cd("harbour-smscontrol");

//    if (!dir.mkpath(QString("%1").arg("harbour-smscontrol"))) {
//        return QString();
//    }
//    if (!dir.cd("dmnk.org")) {
//    //if (!dir.cd(qApp->organizationName())) {
//        return QString();
//    }
//    //if (!dir.cd(qApp->applicationName())) {
//    if (!dir.cd("SMS-Control")) {
//        return QString();
//    }

    return dir.absoluteFilePath("config.json");
}

void DeviceStorage::save()
{
    QJsonArray jsonArray;
    foreach (ConfiguredControllableDevice *secsysEntry, m_securitySystems) {
        QJsonObject jsonSecsys;
        //QLocale loc();

        //QString id = loc.toString(secsysEntry->getID());
        //QString id = ""+secsysEntry->getID(); //wrap qlonglong as string, json doesn't like qlonglong

        //QString id = QString(secsysEntry->getID());
        QString id = tr("%1").arg(secsysEntry->getID());

        jsonSecsys.insert(SYSTEMID, id);//secsysEntry->getID());
        jsonSecsys.insert(DESCRIPTION, secsysEntry->getDescription());
        jsonSecsys.insert(PHONENUMBER, secsysEntry->getPhonenumber());
        jsonSecsys.insert(PASSWORD, secsysEntry->getPassword());


        /*if (!secsysEntry->getProperties().isEmpty()) {
            QJsonObject jsonSecsysProperties;
            foreach (QString key, secsysEntry->getProperties().keys()) {
                jsonSecsysProperties.insert(key,
                                          QJsonValue::fromVariant(secsysEntry->getProperties().value(key)));
            }
            jsonSecsys.insert(PROPERTIES, jsonSecsysProperties);
        }*/
        jsonArray.append(jsonSecsys);
    }

    QJsonDocument jsonDocument (jsonArray);
    QFile file (configFilePath());
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    file.write(jsonDocument.toJson(QJsonDocument::Compact));
    file.close();
}
