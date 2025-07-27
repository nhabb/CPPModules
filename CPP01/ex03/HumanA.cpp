#include "HumanA.hpp"
#include "Weapon.hpp"
std::string HumanA::getName()
{
    return this->name;
}


void HumanA::setName(std::string name) 
{
    this->name = name;
}


HumanA::HumanA(std::string name,Weapon &weapon )
{
    this->name = name;
    this->weapon = &weapon;
}

void HumanA::attack()
{
    std::cout<<this->getName()<<" attacks with their "<<this->weapon->getType()<<std::endl;
}
