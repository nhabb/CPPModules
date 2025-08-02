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
        value = obj.value;
    return *this;
}

int Fixed::getRawBits(void)
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (value);
}

void Fixed::setRawBits(int raw)
{
    value = raw;
}

Fixed::Fixed(const int raw)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->value = raw * 256;
}

Fixed::Fixed(const float raw)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->value = roundf(raw * 256);
}

float Fixed::toFloat(void) const
{
    return (float)(value)/(256);
}

int Fixed::toInt(void) const
{
    return (value / 256);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out<< fixed.toFloat();
    return out;
}