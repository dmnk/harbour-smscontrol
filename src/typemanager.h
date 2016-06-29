#ifndef TYPEMANAGER_H
#define TYPEMANAGER_H

#include <QObject>
#include "controllabletype.h"

class TypeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> types READ getTypes NOTIFY typesChanged)
public:
    explicit TypeManager(QObject *parent = 0);

    QList<QObject *> getTypes() const;
signals:
    void typesChanged();
public slots:
private:
    QList<ControllableType *> m_types;

};
#endif // TYPEMANAGER_H
