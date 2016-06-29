#include "action.h"

Action::Action(QObject *parent) :
    QObject(parent)
{
}

Action * Action::create(const qlonglong &id, const qlonglong &device_ID, const QString &name, const QString &command, QObject *parent) {
    Action *a = new Action(parent);

    a->m_id = id;
    a->m_devID = device_ID;
    a->m_name = name;
    a->m_command = command;

    return a;
}

qlonglong Action::getID() {
    return m_id;
}

QString Action::getName() const {
    return m_name;
}

QString Action::getCommand() const {
    return m_command;
}

qlonglong Action::getDeviceID() {
    return m_devID;
}
