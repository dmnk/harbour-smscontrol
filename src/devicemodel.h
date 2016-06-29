#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QObject>
#include <QtSql/QSqlQueryModel>

class DeviceModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit DeviceModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

public slots:
    void initializeModel();
private:
    void refresh();

};

#endif // DEVICEMODEL_H
