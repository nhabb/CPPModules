#include "Zombie.hpp"

void Zombie::setName(std::string name) 
{
    this->name = name;
}

std::string Zombie::getName()
{
    return this->name;
}

void Zombie::Announce(void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<this->getName()<<" Destroyed."<<std::endl;
}