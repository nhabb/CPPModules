#include "ScalarConverter.hpp"
ScalarCoverter::ScalarCoverter(){}

void ScalarCoverter::convert(std::string str)
{
    std::cout<<str<<std::endl;

    int Integer = stoi(str);
    std::cout<<Integer;
    std::cout<<std::endl;

    std::cout<< stof(str);
    std::cout<<std::endl;

    std::cout<<stod(str);
    std::cout<<std::endl;
}


