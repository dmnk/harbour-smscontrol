#include <QtSql/QSqlQueryModel>
#include "actionmodel.h"
//#include <QDebug>

ActionModel::ActionModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

Qt::ItemFlags ActionModel::flags(
        const QModelIndex &index) const {
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2)
        flags |= Qt::ItemIsEditable;
    return flags;
}

void ActionModel::refresh()
{
    //setQuery("SELECT dev.d_id AS d_id, act.a_id AS a_id, act.a_name AS a_name, da.da_command AS da_command FROM tab_devices dev, tab_actions act, tab_devicesactions da WHERE dev.d_id = da.da_deviceID AND da.da_actionID = act.a_id ORDER BY d_typeID, d_producer, d_name");
    setQuery("SELECT tab_devices.d_id AS d_id, tab_actions.a_id AS a_id, tab_actions.a_name AS a_name, tab_devicesactions.da_command AS da_command FROM tab_devices, tab_actions, tab_devicesactions WHERE tab_devices.d_id = tab_devicesactions.da_deviceID AND tab_devicesactions.da_actionID = tab_actions.a_id"); //ORDER BY d_typeID, d_producer, d_name");
    setHeaderData(0, Qt::Horizontal, QObject::tr("dID"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("aID"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("aName"));
    setHeaderData(3, Qt::Horizontal, QObject::tr("daCommand"));
}

void ActionModel::initializeModel()
{
    //this->setQuery("SELECT dev.d_id AS d_id, act.a_id AS a_id, act.a_name AS a_name, da.da_command AS da_command FROM tab_devices dev, tab_actions act, tab_devicesactions da WHERE dev.d_id = da.da_deviceID AND da.da_actionID = act.a_id ORDER BY d_typeID, d_producer, d_name");
    setQuery("SELECT tab_devices.d_id AS d_id, tab_actions.a_id AS a_id, tab_actions.a_name AS a_name, tab_devicesactions.da_command AS da_command FROM tab_devices, tab_actions, tab_devicesactions WHERE tab_devices.d_id = tab_devicesactions.da_deviceID AND tab_devicesactions.da_actionID = tab_actions.a_id"); //
    //qDebug() << "Error: " << this->lastError();
}
