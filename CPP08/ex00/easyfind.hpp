#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <list>

class NumberNotFoundException : public std::exception
{
    virtual const char * what() const throw();
};

template <typename T>
int easyfind(const T &v, int num)
{
    typename T::const_iterator it = v.begin();
    typename T::const_iterator end = v.end();
    int index = 0;

    while (it != end)
    {
        if (*it == num)
            return index;
        ++it;
        ++index;
    }
    throw NumberNotFoundException();
}


#endif
