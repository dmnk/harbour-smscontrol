#ifndef CONTROLLABLEDEVICE_H
#define CONTROLLABLEDEVICE_H

#include <QObject>
#include "controllabletype.h"

class ControllableDevice : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qlonglong id READ getID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QString typeName READ getTypeName CONSTANT)
    Q_PROPERTY(ControllableType* type READ getType CONSTANT)
    Q_PROPERTY(QString producer READ getProducer CONSTANT)

public:
    explicit ControllableDevice(QObject *parent = 0);
    static ControllableDevice * create(const qlonglong &id, const QString &name, const QString &producer, ControllableType *type, QObject *parent = 0);

    qlonglong getID();
    QString getName() const;
    QString getTypeName() const;
    ControllableType* getType();
    QString getProducer() const;
signals:

public slots:

//private:
protected:
    qlonglong m_id;
    QString m_name;
    QString m_producer;
    ControllableType *m_type;
};
#endif // CONTROLLABLEDEVICE_H
