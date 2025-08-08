#include "Dog.hpp"

Dog::Dog() 
{
    brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog &obj) 
{
    *this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "Dog barks" << std::endl;
}
