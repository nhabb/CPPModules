#include "Harl.hpp"

int main()
{
    Harl h;
    std::string input;
    std::cout<<"Enter the level you want: ";
    if (!std::getline(std::cin,input))
        return 1;
    h.complain(input);
}