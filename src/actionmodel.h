#ifndef ACTIONMODEL_H
#define ACTIONMODEL_H

#include <QObject>
#include <QtSql/QSqlQueryModel>

class ActionModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit ActionModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

public slots:
    void initializeModel();

private:
    void refresh();

};

#endif // ACTIONMODEL_H
