#include "Search.hpp"

int main(int argc, char **argv)
{
    Search s;
    if (argc != 4)
    {
        std::cout<<"Usage: <file name> <s1> <s2>"<<std::endl;
        return (1);
    }
    s.setFileName(argv[1]);
    s.setS1(argv[2]);
    s.setS2(argv[3]);
    s.replace();
}