#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    BitcoinExchnage bc;
    if (argc != 2)
    {
        std::cout<<"Incorrect usage"<<std::endl;
        return (1);
    }
    else
    {
        bc.setFileName(argv[1]);
        bc.exchange();
    }
    return (0);
}