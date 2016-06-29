#ifndef CONTROLLABLETYPE_H
#define CONTROLLABLETYPE_H

#include <QObject>

class ControllableType : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qlonglong id READ getID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
public:
    explicit ControllableType(QObject *parent = 0);
    static ControllableType * create(const qlonglong &id, const QString &name, QObject *parent = 0);

    qlonglong getID() const;
    QString getName() const;
signals:

public slots:

private:
    qlonglong m_id;
    QString m_name;
};

#endif // CONTROLLABLETYPE_H
