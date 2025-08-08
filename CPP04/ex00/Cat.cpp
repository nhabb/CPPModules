#include "Cat.hpp"

Cat::Cat() 
{
    this->type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &obj) 
{
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
