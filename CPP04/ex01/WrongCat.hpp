#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
    WrongCat();
public:
    virtual ~WrongCat();
    WrongCat(const WrongCat &obj);
    WrongCat &operator=(const WrongCat &obj);
    void makeSound() const;
};

#endif
