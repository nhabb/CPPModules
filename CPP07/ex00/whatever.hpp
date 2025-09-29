#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>


template <typename T>
void swap(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T &a, T &b)
{
    T res;
    if (a < b)
    {
        res = a;
        return res;
    }
    else
    {
        res = b;
        return res;
    }
    if (a == b)
    {
        res = b;
        return res;
    }
}

template <typename T>
T max(T &a, T &b)
{
    T res;
    if (a > b)
    {
        res = a;
        return res;
    }
    else
    {
        res = b;
        return res;
    }
    if (a == b)
    {
        res = b;
        return res;
    }
}

#endif