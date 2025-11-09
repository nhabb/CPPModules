#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing MutantStack Copy Constructor ===" << std::endl;
    
    // Create original stack
    MutantStack<int> original;
    original.push(42);
    original.push(100);
    original.push(200);
    
    std::cout << "\nOriginal stack contents:" << std::endl;
    for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Test copy constructor
    MutantStack<int> copy(original);
    std::cout << "\nCopied stack contents:" << std::endl;
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Modify original
    original.push(999);
    std::cout << "\nAfter pushing 999 to original:" << std::endl;
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    
    // Test assignment operator
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "\nAssigned stack contents:" << std::endl;
    for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Test conversion to std::stack
    std::stack<int> s(copy);
    std::cout << "\nConverted to std::stack, size: " << s.size() << std::endl;
    std::cout << "Top element: " << s.top() << std::endl;
    
    return 0;
}
