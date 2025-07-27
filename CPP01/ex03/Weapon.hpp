#include <iostream>
#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
    private:
    std::string type;

    public:
    void setType(std::string);
    std::string getType();
    Weapon(std::string weapon);
    Weapon();
};

#endif
