#include <QtSql/QSqlQueryModel>
#include "devicemodel.h"

DeviceModel::DeviceModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

//! [0]
Qt::ItemFlags DeviceModel::flags(
const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2)
    flags |= Qt::ItemIsEditable;
    return flags;
}
//! [0]
void DeviceModel::refresh()
{
    setQuery("SELECT * FROM tab_devices ORDER BY d_typeID, d_producer, d_name");
    setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
}/*
bool DeviceModel::setLastName(int personId, const QString &lastName)
{
    QSqlQuery query;
    query.prepare("update person set lastname = ? where id = ?");
    query.addBindValue(lastName);
    query.addBindValue(personId);
    return query.exec();
}*/

void DeviceModel::initializeModel()
{
    this->setQuery("SELECT * FROM tab_devices ORDER BY d_typeID, d_producer, d_name");
    /*this->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));*/
}
