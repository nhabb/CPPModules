#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    this->type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) 
{
    *this = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
 {
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meows" << std::endl;
}
