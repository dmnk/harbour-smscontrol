#include "typemodel.h"
#include "typemanager.h"
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

#include <QDebug>

TypeManager::TypeManager(QObject *parent) :
    QObject(parent)
{
    TypeModel model;
    model.initializeModel();

    for (int i = 0; i < model.rowCount(); i++) {
       // QSqlRecord rec = model.record(i);
        int pk = model.record(i).value("t_id").toInt();
        QString name = model.record(i).value("t_name").toString();
        //qDebug() << pk + " - "+name;

        ControllableType *ct = ControllableType::create(pk, name, this);

        m_types.append(ct);
    }
}

QList<QObject *> TypeManager::getTypes() const {
    QList<QObject *> types;
    foreach (ControllableType *type, m_types) {
        types.append(type);
    }

    return types;
}
