#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarCoverter::convert(argv[1]);
        return (0);
    }
    else
    {
        std::cout<<"Usage: \"./convert input\""<<std::endl;
        return (1);
    }
    return (0);
}