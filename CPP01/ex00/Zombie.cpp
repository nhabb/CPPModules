#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::Announce(void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<this->name<<" has been destroyed."<<std::endl;
}

Zombie* Zombie::newZombie( std::string name )
{
    Zombie *zombie = new Zombie("fooo");
    return (zombie);
}

void Zombie::randomChump( std::string name )
{
    Zombie zombie("hooo");
    zombie.Announce();
}