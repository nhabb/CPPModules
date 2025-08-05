#include "Fixed.hpp"

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<<std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout<<"Copy asignment operator called"<<std::endl;
    if (this != &obj)
        value = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (value);
}

void Fixed::setRawBits(int raw)
{
    value = raw;
}