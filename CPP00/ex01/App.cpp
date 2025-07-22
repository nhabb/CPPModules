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
        // std::cin>>str;
        if (!std::getline(std::cin, str)) 
            break ;
        if (str == "EXIT")
        {
            std::cout<<"Exiting program..."<<std::endl;
            // p.quit();
            break ;
        }
        else if (str == "ADD")
        {
            // Contact contact;
            p.ADD();
        }
        else if (str == "SEARCH")
        {
            p.display();
            // int index;
            // std::cout<<"Enter the index you want to search."<<std::endl;
            // std::cin>> index;
            p.SEARCH();
        }
    }
    return (0);
}