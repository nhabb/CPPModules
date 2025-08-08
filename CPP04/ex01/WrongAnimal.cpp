#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() 
{
    this->type = "UnknownWrongAnimal";   
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) 
{
    *this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) 
{
    if (this != &obj)
        type = obj.type;
    return *this;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return type;
}
