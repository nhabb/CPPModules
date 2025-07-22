#include "Contact.hpp"

Contact::Contact(){}

std::string Contact::getName()
{
    return (this->name);
}

void Contact::setName(std::string name)
{
    this->name = name;
}

std::string Contact::getLast()
{
    return (this->lastName);
}

void Contact::setLast(std::string lastName)
{
    this->lastName = lastName;
}

std::string Contact::getNick()
{
    return (this->nickName);
}

void Contact::setNick(std::string nickName)
{
    this->nickName = nickName;
}

std::string Contact::getSecret()
{
    return (this->secret);
}

void Contact::setSecret(std::string secret)
{
    this->secret = secret;
}

std::string Contact::getPhone()
{
    return (this->phone);
}

void Contact::setPhone(std::string phone)
{
    this->phone = phone;
}