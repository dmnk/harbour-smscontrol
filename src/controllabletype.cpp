#include "controllabletype.h"

ControllableType::ControllableType(QObject *parent) :
    QObject(parent)
{
}
ControllableType * ControllableType::create(const qlonglong &id, const QString &name, QObject *parent) {
    ControllableType *cd = new ControllableType(parent);

    cd->m_id = id;
    cd->m_name = name;

    return cd;
}

qlonglong ControllableType::getID() const {
    return m_id;
}

QString ControllableType::getName() const {
    return m_name;
}
