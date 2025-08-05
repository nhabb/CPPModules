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
    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;
    Fixed operator+(const Fixed &obj);
    Fixed operator-(const Fixed &obj);
    Fixed operator/(const Fixed &obj);
    Fixed operator*(const Fixed &obj);
    Fixed operator++(int);
    Fixed &operator++();
    Fixed operator--(int);
    Fixed &operator--();
    int getRawBits(void);
    void setRawBits(int const raw);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a,const Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif