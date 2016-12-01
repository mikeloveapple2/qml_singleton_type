#include "manager.h"


Manager* Manager::m_instance = NULL;
Manager::Manager(QObject *parent) : QObject(parent)
{
    init();
}

Manager::~Manager()
{

}

void Manager::init()
{
    m_instance = this;
}

int Manager::getNumber() const
{
    return m_number;
}

void Manager::setNumber(int number)
{
    if(m_number != number){
        m_number = number;
        emit numberChanged(number);
    }
}

Manager *Manager::getInstance()
{
    return m_instance;
}

QString Manager::getName() const
{
    return m_name;
}

void Manager::setName(const QString &name)
{
    if(m_name != name){
        m_name = name;
        emit nameChanged(name);
    }
}
