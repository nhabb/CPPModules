#include "easyfind.hpp"

const char *NumberNotFoundException::what() const throw()
{
    return "Number not found";
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    try
    {
        std::cout<<easyfind(v,8);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<< "found at index: "<< easyfind(v,6)<<std::endl;

    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    try
    {
        std::cout<<easyfind(d,8);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<< "found at index: "<< easyfind(d,6)<<std::endl;

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    try
    {
        std::cout<<easyfind(l,8);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<< "found at index: "<< easyfind(l,6)<<std::endl;
}