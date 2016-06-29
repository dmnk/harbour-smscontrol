#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <QObject>
#include "action.h"

class ActionManager : public QObject
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent = 0);

    QList<Action *> getActions(qlonglong deviceID) const;
signals:

public slots:
private:
    QList<Action *> m_actions;

};

#endif // ACTIONMANAGER_H
