#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    // Test valid bureaucrat
    try
    {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        // Test increment (operator++)
        b1++;
        std::cout << "After increment: " << b1 << std::endl;

        // Test decrement (operator--)
        b1--;
        std::cout << "After decrement: " << b1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // Test too high
    try
    {
        Bureaucrat b2("Bob", 0); // Invalid -> should throw
        std::cout << b2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // Test too low
    try
    {
        Bureaucrat b3("Charlie", 200); // Invalid -> should throw
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // Edge cases
    try
    {
        Bureaucrat b4("Diana", 1);
        std::cout << b4 << std::endl;
        b4++; // Should throw (goes above 1)
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;
        b5--; // Should throw (goes below 150)
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
