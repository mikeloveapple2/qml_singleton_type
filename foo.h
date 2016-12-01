#ifndef FOO_H
#define FOO_H

#include <QObject>

class Foo : public QObject
{
    Q_OBJECT
public:
    explicit Foo(QObject *parent = 0);
    ~Foo();

signals:

public slots:

private :
    void init();
};

#endif // FOO_H
