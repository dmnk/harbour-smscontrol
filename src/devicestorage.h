#ifndef DEVICESTORAGE_H
#define DEVICESTORAGE_H

#include <QObject>
#include <QVariantMap>
#include "controllabledevice.h"
#include "configuredcontrollabledevice.h"
//#include <powersocket.h>

class DeviceStorage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> controllableDevices READ getControllableDevices NOTIFY controllableDevicesChanged)
    //Q_PROPERTY(QList<QObject *> powerSockets READ getPowerSockets NOTIFY powerSocketsChanged)
public:
    explicit DeviceStorage(QObject *parent = 0);
    QList<QObject *> getControllableDevices() const;
    //QList<QObject *> getPowerSockets() const;
    //Q_INVOKABLE QVariantMap properties(const QString &identifier);

signals:
    void controllableDevicesChanged();
    //void powerSocketsChanged();
public slots:
    void addControllableDevice(const QString &systemID, const QString &description, const QString &phonenumber,
                           const QString &password);
    /*void addControllableDevice(const QString &systemID, const QString &name, const QString &phonenumber,
                           const QString &password, ControllableType *type);*/
    /*void addPowerSocket(int &systemID, const QString &name, const QString &phonenumber,
                        const QString &password, QObject *parent = 0);*/
    void removeControllableDevice(const QString &phonenumber);
    //void removePowerSocket(int &systemID);

private:
    static QString configFilePath();
    void save();
    QList<ConfiguredControllableDevice *> m_securitySystems;
    QMap<QString, ConfiguredControllableDevice *> m_securitySystemsMap;
    //QList<PowerSocket *> m_powerSockets;
    //QMap<QString, PowerSocket *> m_powerSocketsMap;


};

#endif // DEVICESTORAGE_H
