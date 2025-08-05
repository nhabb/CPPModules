#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->hp = 10;
    this->ep = 10;
    this->attDamage = 0;
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->hp = 10;
    this->ep = 10;
    this->attDamage = 0;
    std::cout << "ClapTrap " << name << " created" << std::endl;
    this->name = name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        this->hp = obj.hp;
        this->attDamage = obj.attDamage;
    }
    return *this;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp == 0)
    {
        std::cout << "ClapTrap " << name << " is already at 0 HP!" << std::endl;
        return;
    }

    if (amount >= hp)
        hp = 0;
    else
        hp -= amount;

    std::cout << "ClapTrap " << name << " takes " << amount << " damage! HP left: " << hp << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hp == 0 || ep == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack. No HP or energy left." << std::endl;
        return;
    }
    ep--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp == 0 || ep == 0)
    {
        std::cout << "ClapTrap " << name << " can't repair. No HP or energy left." << std::endl;
        return;
    }
    hp += amount;
    ep--;
    std::cout << "ClapTrap " << name << " repairs itself, gaining "
              << amount << " hit points!" << std::endl;
}
