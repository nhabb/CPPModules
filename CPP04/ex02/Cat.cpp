#include "Cat.hpp"

Cat::Cat() 
{
    brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &obj) 
{
    this->brain = new Brain(*obj.brain);
    *this = obj;
}

Cat &Cat::operator=(const Cat &obj)
 {
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}
