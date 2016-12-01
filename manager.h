#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = 0);
    ~Manager();

    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

    QString getName() const;
    void setName(const QString &getName);

    int getNumber() const;
    void setNumber(int getNumber);

    static Manager* getInstance();

    static Manager* m_instance;

signals:
    void numberChanged(int);
    void nameChanged(QString);

public slots:

private :
    void init();
    int m_number;
    QString m_name;
};

#endif // MANAGER_H
