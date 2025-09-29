#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
    unsigned int size;
    T *data;
    Array()
    {
        size = 0;   
    }

    Array(unsigned int n)
    {
        this->size = n;
        data = new T[n]();
    }

};

#endif