#include "actionmanager.h"
#include "actionmodel.h"

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

//#include <QDebug>

ActionManager::ActionManager(QObject *parent) :
    QObject(parent)
{
    ActionModel model;
    model.initializeModel();


    //qDebug() << "Actions found: "+model.rowCount();

    for (int i = 0; i < model.rowCount(); i++) {
        //QSqlRecord rec = model.record(i);
        //qDebug() << model.record(i).value("d_id");
        // dev.id d_id, act.a_id a_id, act.a_name a_name, da.da_command da_command
        qlonglong d_id = model.record(i).value("d_id").toLongLong();
        qlonglong a_id = model.record(i).value("a_id").toLongLong();
        QString a_name = model.record(i).value("a_name").toString();
        QString da_command = model.record(i).value("da_command").toString();

        Action *a = Action::create(a_id, d_id, a_name, da_command, this);

        m_actions.append(a);
    }
}


QList<Action *> ActionManager::getActions(qlonglong deviceID) const {
    QList<Action *> actions;
    foreach (Action *a, m_actions) {
        if(a->getDeviceID() == deviceID) {
            actions.append(a);
        }
    }

    return actions;
}
