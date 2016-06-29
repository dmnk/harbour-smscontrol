#include "typemodel.h"

#include <QtSql/QSqlQueryModel>
//#include "editablesqlmodel.h"

TypeModel::TypeModel(QObject *parent)
: QSqlQueryModel(parent)
{
}

//! [0]
Qt::ItemFlags TypeModel::flags(
const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2) {
        //flags |= !Qt::ItemIsEditable;
    }
    return flags;
}

void TypeModel::refresh()
{
    setQuery("SELECT * FROM tab_type");
    /*setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));*/
}
void TypeModel::initializeModel()
{
    this->setQuery("SELECT * FROM tab_type");
    /*this->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));*/
}
