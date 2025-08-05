#include "Fixed.hpp"

Fixed::~Fixed()
{
}

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;    
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
        value = obj.value;
    return *this;
}

int Fixed::getRawBits(void)
{
    return (value);
}

void Fixed::setRawBits(int raw)
{
    value = raw;
}

Fixed::Fixed(const int raw)
{
    this->value = raw * 256;
}

Fixed::Fixed(const float raw)
{
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

bool Fixed::operator>(const Fixed &obj) const
{
    return this->value > obj.value;
}

bool Fixed::operator<(const Fixed &obj) const
{
    return this->value < obj.value;
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return this->value >= obj.value;
}
bool Fixed::operator<=(const Fixed &obj) const
{
    return this->value <= obj.value;
}

bool Fixed::operator==(const Fixed &obj) const
{
    return this->value == obj.value;
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return this->value != obj.value;
}

Fixed Fixed::operator+(const Fixed &obj) 
{
    Fixed result;
    result.setRawBits(this->getRawBits() + obj.value/256);
    return result;
}

Fixed Fixed::operator-(const Fixed &obj) 
{
    Fixed result;
    result.setRawBits(this->getRawBits() - obj.value/256);
    return result;
}

Fixed Fixed::operator/(const Fixed &obj)
{
    Fixed result;
    result.setRawBits((this->getRawBits()/256) / obj.value/256);
    return result;
}

Fixed Fixed::operator*(const Fixed &obj)
{
    Fixed result;
    result.setRawBits(this->getRawBits() * obj.value/256);
    return result;
}


Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.value >= b.value)
        return a;
    return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.value >= b.value)
        return a;
    return b;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.value <= b.value)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a,const Fixed &b)
{
    if (a.value <= b.value)
        return a;
    return b;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    value++;
    return temp;
}


Fixed &Fixed::operator++()
{
    ++value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    value--;
    return *this;

}

Fixed &Fixed::operator--()
{
    --value;
    return *this;
}