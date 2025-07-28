#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;
    if (argc != 2)
    {
        std::cout<<"usage: ./harlFilter LEVEL"<<std::endl;
        return (1);
    }
    // std::string input;
    // std::cout<<"Enter the level you want: ";
    // if (!std::getline(std::cin,input))
    //     return 1;
    h.complain(argv[1]);
}