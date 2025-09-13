#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook p;
    while (1)
    {
        std::string str;
        std::cout<< "1) ADD"<<std::endl
                 <<  "2) Search"<<std::endl
                 <<  "3) Exit"<<std::endl
                 <<  "choice: ";
        if (!std::getline(std::cin, str)) 
            break ;
        if (str == "EXIT")
        {
            std::cout<<"Exiting program..."<<std::endl;
            break ;
        }
        else if (str == "ADD")
        {
            p.ADD();
        }
        else if (str == "SEARCH")
        {
            p.display();
            p.SEARCH();
        }
    }
    return (0);
}