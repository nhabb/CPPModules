#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->hp = 100;
    this->ep = 50;
    this->attDamage = 20;
    std::cout<<"ScavTrap created"<<std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hp = 100;
    this->ep = 50;
    this->attDamage = 20;
    std::cout<<"ScavTrap "<<name<<" created"<<std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap "<<name<< " destroyed"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    *this = obj;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    if (this != &obj)
    {
        this->attDamage = obj.attDamage;
        this->hp = obj.hp;
        this->ep = obj.ep;
        this->name = obj.name;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<name <<" is in gate keeper mode"<<std::endl;
}