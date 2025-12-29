#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include <exception>

class NumberNotFoundException : public std::exception
{
    public:
        virtual const char * what() const throw();
};

template <typename T>
int easyfind(const T &v, int num)
{
    typename T::const_iterator it = std::find(v.begin(), v.end(), num);
    if (it == v.end())
        throw NumberNotFoundException();
    return (std::distance(v.begin(), it));
}

#endif
