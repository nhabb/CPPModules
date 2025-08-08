#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("UnknownScavTrap")
{
    this->hp = 100;
    this->ep = 50;
    this->attDamage = 20;
    std::cout<<"ScavTrap created"<<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
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

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    *this = obj;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<name <<" is in gate keeper mode"<<std::endl;
}