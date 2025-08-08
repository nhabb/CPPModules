#include "Animal.hpp"

Animal::Animal()
{
    this->type ="UnknownAnimal";
    std::cout << "Animal created" << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(const Animal &obj) 
{
    *this = obj;
}

Animal &Animal::operator=(const Animal &obj)
 {
    if (this != &obj)
        type = obj.type;
    return *this;
}

void Animal::makeSound() const 
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const 
{
    return type;
}
