#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int value;
    static const  int bits = 8;
    public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    float toFloat(void) const;
    int toInt(void) const;
    ~Fixed();
    Fixed(const Fixed &obj);
    Fixed &operator=(const Fixed &obj);
    int getRawBits(void);
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif