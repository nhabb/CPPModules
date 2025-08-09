#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //Subject tests
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    // My tests
    Animal *animal[10];
    for (int i = 0; i < 5; i++)
    {
        animal[i] = new Dog();
    }
    for (int i = 5; i < 10; i++)
    {
        animal[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        delete animal[i];
    }
    return 0;
}