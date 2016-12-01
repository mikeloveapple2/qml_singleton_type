#include "foo.h"
#include "manager.h"

Foo::Foo(QObject *parent) : QObject(parent)
{
    init();
}

Foo::~Foo()
{

}

void Foo::init()
{
    Manager* target = Manager::getInstance();

    qDebug("tmp : %x, target: %x \n", 0xfe, target);
    qDebug("old  %s, %d \n", qPrintable(target->getName()), target->getNumber());
    target->setName("ele1000");
    target->setNumber(11);
    qDebug("new  %s, %d \n", qPrintable(target->getName()), target->getNumber());
}
