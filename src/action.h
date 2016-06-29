#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qlonglong id READ getID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QString command READ getCommand CONSTANT)

public:
    explicit Action(QObject *parent = 0);
    static Action * create(const qlonglong &d_id, const qlonglong &device_ID, const QString &name, const QString &command, QObject *parent = 0);

    qlonglong getID();
    qlonglong getDeviceID();
    QString getName() const;
    QString getCommand() const;
signals:

public slots:

private:
    qlonglong m_id;
    qlonglong m_devID;
    QString m_name;
    QString m_command;
};

#endif // ACTION_H
