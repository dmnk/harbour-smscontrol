#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <QObject>
#include "controllabledevice.h"

class DeviceManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> devices READ getDevices NOTIFY devicesChanged)
public:
    explicit DeviceManager(QObject *parent = 0);

    QList<QObject *> getDevices() const;
    ControllableDevice * getDevice(qlonglong id) const;
signals:
    void devicesChanged();
public slots:
private:
    QList<ControllableDevice *> m_devices;
};

#endif // DEVICEMANAGER_H
