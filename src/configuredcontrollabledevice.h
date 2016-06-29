#ifndef CONFIGUREDCONTROLLABLEDEVICE_H
#define CONFIGUREDCONTROLLABLEDEVICE_H
#include "controllabledevice.h"
#include "action.h"

class ConfiguredControllableDevice : public ControllableDevice
{
    Q_OBJECT

    Q_PROPERTY(QString phonenumber READ getPhonenumber() CONSTANT)
    Q_PROPERTY(QString password READ getPassword() CONSTANT)
    Q_PROPERTY(QString description READ getDescription() CONSTANT)

    Q_PROPERTY(QList<QObject *> actions READ getActions CONSTANT)
public:
    explicit ConfiguredControllableDevice(QObject *parent = 0);
    static ConfiguredControllableDevice * create(const qlonglong &systemID, const QString &systemName, const QString &producerName, const QString &description, ControllableType *type, const QString &phonenumber, const QString &password, QObject *parent =0);
   // qlonglong getID();
    QString getPhonenumber() const;
    QString getPassword() const;
    QString getDescription() const;

    QList<QObject *> getActions() const;
signals:

public slots:

private:

    QString m_phonenumber;
    QString m_password;
    QString m_description;

    QList<Action *> m_actions;
};

#endif // CONFIGUREDCONTROLLABLEDEVICE_H
