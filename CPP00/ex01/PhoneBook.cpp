#include "PhoneBook.hpp"

int PhoneBook::count = -1;

void PhoneBook::ADD()
{
    Contact contact;
    std::string first, last, nick, secret, phone;
    count++;
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, first)) 
        return;
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, last)) 
        return;
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nick)) 
        return;
    std::cout << "Enter secret: ";
    if (!std::getline(std::cin, secret)) 
        return;
    while (true)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, phone))
            return;

        bool valid = true;
        for (int i = 0; i < (int)phone.size(); i++)
        {
            if (!isdigit(phone[i]))
            {
                valid = false;
                break;
            }
        }
        if (valid)
            break;
        else
            std::cout << "Invalid phone number. Only digits are allowed.\n";
    }
    contact.setName(first);
    contact.setLast(last);
    contact.setNick(nick);
    contact.setSecret(secret);
    contact.setPhone(phone);
    int index = count % 8;
    contacts[index] = contact;
}


void PhoneBook::SEARCH()
{
    if (count == -1)
    {
        std::cout<<"Phonebook is empty"<<std::endl;
        return ;
    }
    int index;
    std::cout<<"Enter the index you want to search: ";
    std::cin>> index;
    if (index > 8)
    {
        std::cout<<"Out of phonebook";
        return ;
    }
    std::cout<<contacts[index].getName()<<std::endl;
    std::cout<<contacts[index].getLast()<<std::endl;
    std::cout<<contacts[index].getNick()<<std::endl;
    std::cout<<contacts[index].getPhone()<<std::endl;
    std::cout<<contacts[index].getSecret()<<std::endl;
}


std::string formatField(const std::string& str) 
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::display() 
{
    if (count == -1)
        return ;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|\n";

    for (int i = 0; i <= count; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << formatField(contacts[i].getName()) << "|"
                  << formatField(contacts[i].getLast()) << "|"
                  << formatField(contacts[i].getNick()) << "|\n";
    }
}