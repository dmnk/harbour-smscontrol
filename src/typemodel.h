#ifndef TYPEMODEL_H
#define TYPEMODEL_H

#include <QObject>
#include <QtSql/QSqlQueryModel>

class TypeModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit TypeModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

public slots:
    void initializeModel();
private:
    void refresh();

};

#endif // TYPEMODEL_H
