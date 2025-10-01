#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>
#include <exception>

template<typename T>
class Array 
{
private:
    int Arrsize;
    T* data;
public:
    Array()
    {
        Arrsize = 0;
        data = NULL;
    }
    Array(unsigned int n)
    {
        Arrsize = n;
        data = new T[n];
    }
    Array(const Array& obj)
    {
        Arrsize = obj.Arrsize;
        data = new T[obj.Arrsize];
        for (int i = 0; i < Arrsize; i++) 
        {
            data[i] = obj.data[i];
        }
    }
    Array& operator=(const Array& obj)
    {
        if (this != &obj) {
            delete[] data;
            Arrsize = obj.Arrsize;
            data = new T[Arrsize];
            for (int i = 0; i < Arrsize; i++) 
            {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }

    ~Array() 
    {
        delete[] data;
    }

    T& operator[](int index) 
    {
        if (index < 0 || index >= Arrsize) 
            throw OutOfBoundsException();
        return data[index];
    }

    const T& operator[](unsigned int index) const 
    {
       if (index < 0 || index >= Arrsize) 
            throw OutOfBoundsException();
        return data[index];;
    }

    int size() const 
    {
        return Arrsize;
    }

    class OutOfBoundsException : public std::exception 
    {
        const char* what() const throw() 
        {
            return "Index out of bounds";
        }
    };
};

#endif
