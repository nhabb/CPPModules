#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
    private:
    std::string name;

    public:
    std::string getName();
    void setName(std::string name);
    void Announce(void);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name); 

#endif