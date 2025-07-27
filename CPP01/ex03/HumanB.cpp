#include "HumanB.hpp"

HumanB::HumanB(){}

std::string HumanB::getName()
{
    return this->name;
}

Weapon HumanB::getWeapon()
{
    return this->weapon->getType();
}

void HumanB::setName(std::string name) 
{
    this->name = name;
}

void HumanB::setWeapon(Weapon &weapon) 
{
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
}
void HumanB::attack()
{
    std::cout<<this->getName()<<" attacks with their "<<this->weapon->getType()<<std::endl;;
}