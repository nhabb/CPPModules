#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
    private:
    Contact contacts[8];
    static int count;
    public:
        void pickMethod(std::string str);
        void ADD();
        void SEARCH();
        void display();
};

#endif