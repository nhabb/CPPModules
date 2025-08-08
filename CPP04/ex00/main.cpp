#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //Animal
    std::cout<<"Animal class tests\n"<<std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout<<"\nWrong animal class tests\n"<<std::endl;

    //WrongAnimal
    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* Wrongcat = new WrongCat();
    std::cout << Wrongcat->getType() << " " << std::endl;
    Wrongcat->makeSound();
    Wrongmeta->makeSound();
    return 0;
}