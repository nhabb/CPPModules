#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("UnknownFragTrap")
{
    this->hp = 100;
    this->ep = 100;
    this->attDamage = 30;
    std::cout<<"FragTrap created"<<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    this->hp = 100;
    this->ep = 100;
    this->attDamage = 30;
    std::cout<<"FragTrap "<<name<<" created"<<std::endl;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap "<<name<< " destroyed"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    *this = obj;
}
FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout<<"FragTrap "<<name<<" is feeling cheerful and wants to high five you"<<std::endl;
}