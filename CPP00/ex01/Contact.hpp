#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include<iostream>

class Contact
{
    private:
    std::string name;
    std::string lastName;
    std::string nickName;
    std::string phone;
    std::string secret;

    public:
        Contact();
        std::string getName();
        void setName(std::string name);
        std::string getLast();
        void setLast(std::string lastName);
        std::string getNick();
        void setNick(std::string nickName);
        std::string getSecret();
        void setSecret(std::string secret);
        std::string getPhone();
        void setPhone(std::string phone);
};

#endif