#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        std::cout << "=== Test 1: Using addRange with vector ===" << std::endl;
        std::vector<int> numbers;
        std::srand(std::time(NULL));
        
        for (int i = 0; i < 10000; ++i)
            numbers.push_back(std::rand() % 10000);
        
        Span sp(10000);
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n=== Test 2: Using individual addNumber calls ===" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n=== Test 3: Exceeding capacity with addRange ===" << std::endl;
        std::vector<int> numbers;
        for (int i = 0; i < 15; ++i)
            numbers.push_back(i);
        
        Span sp(10);
        sp.addRange(numbers.begin(), numbers.end());
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
