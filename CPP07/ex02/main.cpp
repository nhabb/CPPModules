#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Array Template Class Tests ===\n\n";

    std::cout << "1. Testing default constructor:\n";
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << "\n\n";

    std::cout << "2. Testing parameterized constructor:\n";
    Array<int> intArr(5);
    std::cout << "Int array size: " << intArr.size() << "\n";
    
    for (int i = 0; i < intArr.size(); i++) {
        intArr[i] = (i + 1) * 10;
    }
    
    std::cout << "Int array contents: ";
    for (int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "3. Testing copy constructor:\n";
    Array<int> intArrCopy(intArr);
    std::cout << "Copied array size: " << intArrCopy.size() << "\n";
    std::cout << "Copied array contents: ";
    for (int i = 0; i < intArrCopy.size(); i++) {
        std::cout << intArrCopy[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "4. Testing assignment operator:\n";
    Array<int> intArr2(3);
    intArr2 = intArr;
    std::cout << "Assigned array size: " << intArr2.size() << "\n";
    std::cout << "Assigned array contents: ";
    for (int i = 0; i < intArr2.size(); i++) {
        std::cout << intArr2[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "5. Testing deep copy (modifying original):\n";
    intArr[0] = 999;
    std::cout << "Original array[0]: " << intArr[0] << "\n";
    std::cout << "Copied array[0]: " << intArrCopy[0] << "\n";
    std::cout << "Assigned array[0]: " << intArr2[0] << "\n\n";

    std::cout << "6. Testing with different types:\n";
    
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "!";
    std::cout << "String array: ";
    for (int i = 0; i < strArr.size(); i++) {
        std::cout << strArr[i] << " ";
    }
    std::cout << "\n";
    
    Array<double> doubleArr(4);
    for (int i = 0; i < doubleArr.size(); i++) {
        doubleArr[i] = (i + 1) * 3.14;
    }
    std::cout << "Double array: ";
    for (int i = 0; i < doubleArr.size(); i++) {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "7. Testing exception handling:\n";
    
    try {
        std::cout << "Trying to access index -1: ";
        std::cout << intArr[-1] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    
    try {
        std::cout << "Trying to access index " << intArr.size() << ": ";
        std::cout << intArr[intArr.size()] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    
    try {
        std::cout << "Trying to access empty array index 0: ";
        std::cout << empty[0] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    std::cout << "\n8. Testing const array access:\n";
    const Array<int> constArr(intArr);
    std::cout << "Const array size: " << constArr.size() << "\n";
    std::cout << "Const array[1]: " << constArr[1] << "\n";

    std::cout << "\n=== All tests completed ===\n";
    return 0;
}