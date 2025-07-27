#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>
#include <string>
class HumanA
{
    private:
    std::string name;
    Weapon *weapon;
    public:
    HumanA(std::string name,Weapon &weapon);
    std::string getName();
    void setName(std::string name);
    std::string getWeapon();
    void setWeapon(Weapon *weapon);
    void attack();
};

#endif